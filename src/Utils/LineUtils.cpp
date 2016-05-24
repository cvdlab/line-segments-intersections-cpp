//
// Created by danilo on 11/05/16.
//

#include <cstdlib>
#include "../../headers/Utils/LineUtils.h"

/* Find the intersection point between two lines */
Inters::Point *Inters::LineUtils::findIntersection(Line *l1, Line *l2) {

    /* First line goes between a and b */
    Point *a = l1->getV0();
    Point *b = l1->getV1();

    /* Second line goes between c and d */
    Point *c = l2->getV0();
    Point *d = l2->getV1();

    double det = determinant(a->getX() - b->getX(), d->getX() - c->getX(), a->getY() - b->getY(),
                             d->getY() - c->getY());

    if (det == 0) {
        /* The lines are parallel or coincident */
        return NULL;
    }

    /* lambda and mu are the coefficients of the equations of the two lines */
    double lambda = determinant(d->getX() - b->getX(), d->getX() - c->getX(), d->getY() - b->getY(),
                                d->getY() - c->getY()) / det;

    double mu = determinant(a->getX() - b->getX(), d->getX() - b->getX(), a->getY() - b->getY(),
                            d->getY() - b->getY()) / det;
    
    if (lambda >= 0 && lambda <= 1 && mu >= 0 && mu <= 1) {
        /* Compute intersection point */
        double intersX = lambda * a->getX() + (1 - lambda) * b->getX();
        double intersY = lambda * a->getY() + (1 - lambda) * b->getY();

        return new Point(intersX, intersY);
    }

    return NULL; // We do not have an intersection

}

/** Find the determinant of a 2x2 matrix **/
double Inters::LineUtils::determinant(double m1, double m2, double m3, double m4) {
    return m1 * m4 - (m2 * m3);
}


/** Find the intersection between a segment and a vertical line **/
Inters::Point *Inters::LineUtils::findVerticalIntersection(Line l1, double verticalLineX) {
    double deltaY = l1.getV1()->getY() - l1.getV0()->getY();
    double deltaX = l1.getV1()->getX() - l1.getV0()->getX();
    return new Point(verticalLineX, deltaY / deltaX * (verticalLineX - l1.getV0()->getX()) + l1.getV0()->getY());
}