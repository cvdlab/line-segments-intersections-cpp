//
// Created by danilo on 11/05/16.
//

#include <cstdlib>
#include <cmath>

#include "../../headers/Utils/LineUtils.h"

/* Find the intersection point between two lines */
Inters::Intersection *Inters::LineUtils::findIntersection(Line *l1, Line *l2) {

    /* First line goes between a and b */
    Point *a = l1->getV0();
    Point *b = l1->getV1();

    /* Second line goes between c and d */
    Point *c = l2->getV0();
    Point *d = l2->getV1();

    double det = determinant(a->getX() - b->getX(), d->getX() - c->getX(), a->getY() - b->getY(),
                             d->getY() - c->getY());

    double lambdaNum = determinant(d->getX() - b->getX(), d->getX() - c->getX(), d->getY() - b->getY(),
                                   d->getY() - c->getY());

    double muNum = determinant(a->getX() - b->getX(), d->getX() - b->getX(), a->getY() - b->getY(),
                               d->getY() - b->getY());

    if (det == 0) {
        if (lambdaNum == 0) {
            return new Intersection(NULL, std::pair<Line *, Line *>(l1, l2), true);
        }
        /* The lines are parallel or coincident */
        return NULL;
    }

    /* lambda and mu are the coefficients of the equations of the two lines */
    double lambda = lambdaNum / det;

    double mu = muNum / det;

    if (lambda >= 0 && lambda <= 1 && mu >= 0 && mu <= 1) {
        /* Compute intersection point */
        double intersX = lambda * a->getX() + (1 - lambda) * b->getX();
        double intersY = lambda * a->getY() + (1 - lambda) * b->getY();

        return new Intersection(new Point(intersX, intersY), std::pair<Line *, Line *>(l1, l2), false);
    }

    return NULL; // We do not have an intersection

}

/** Find the determinant of a 2x2 matrix **/
double Inters::LineUtils::determinant(double m1, double m2, double m3, double m4) {
    return m1 * m4 - (m2 * m3);
}


/** Find the intersection between a segment and a vertical line **/
Inters::Point *Inters::LineUtils::findVerticalIntersection(Line *l1, double verticalLineX) {

    /* Check if l1 is vertical */
    if (l1->getV0()->getX() == l1->getV1()->getX()) {
        if (l1->getV0()->getX() == verticalLineX) {
            return l1->getV0();
        }
        return NULL;
    }

    double deltaY = l1->getV1()->getY() - l1->getV0()->getY();
    double deltaX = l1->getV1()->getX() - l1->getV0()->getX();
    Point *intersectionPoint = new Point(verticalLineX,
                                         deltaY / deltaX * (verticalLineX - l1->getV0()->getX()) + l1->getV0()->getY());

    double epsilon = 0.01;
    /* Now I have to check if the intersection is valid (see http://stackoverflow.com/a/328122) */
    double crossProduct =
            (intersectionPoint->getY() - l1->getV0()->getY()) * (l1->getV1()->getX() - l1->getV0()->getX()) -
            (intersectionPoint->getX() - l1->getV0()->getX()) * (l1->getV1()->getY() - l1->getV0()->getY());

    if (std::abs(crossProduct) > epsilon || crossProduct != 0) {
        return NULL;
    }

    double dotProduct =
            (intersectionPoint->getX() - l1->getV0()->getX()) * (l1->getV1()->getX() - l1->getV0()->getX()) +
            (intersectionPoint->getY() - l1->getV0()->getY()) * (l1->getV1()->getY() - l1->getV0()->getY());

    if (dotProduct < 0) {
        return NULL;
    }

    double squaredLength = (l1->getV1()->getX() - l1->getV0()->getX()) * (l1->getV1()->getX() - l1->getV0()->getX()) +
                           (l1->getV1()->getY() - l1->getV0()->getY()) * (l1->getV1()->getY() - l1->getV0()->getY());

    if (dotProduct > squaredLength) {
        return NULL;
    }

    return intersectionPoint;

}