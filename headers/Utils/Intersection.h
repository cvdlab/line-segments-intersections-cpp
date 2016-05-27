//
// Created by danilo on 24/05/16.
//

#ifndef INTERSCPP_INTERSECTION_H
#define INTERSCPP_INTERSECTION_H

#include "Point.h"
#include "Line.h"

namespace Inters {
    class Intersection {

        Point *intersectionPoint;
        std::pair<Line *, Line *> lines;
        bool isColinear;


    public:


        Intersection(Point *intersectionPoint, const std::pair<Line *, Line *> lines, bool isColinear) : isColinear(
                isColinear), intersectionPoint(intersectionPoint), lines(lines) { }


        ~Intersection() {
            delete intersectionPoint;
        }


        Point *getIntersectionPoint() const {
            return intersectionPoint;
        }

        const std::pair<Line *, Line *> &getLines() const {
            return lines;
        }

        bool isIsColinear() const {
            return isColinear;
        }

        friend std::ostream &operator<<(std::ostream &output,
                                        const Intersection &i) {

            if (i.getIntersectionPoint() != NULL) {
                output << "Intersection{ IntersectionPoint: " << *i.getIntersectionPoint() << "\nLine 1: " <<
                *i.getLines().first << "\nLine 2: " << *i.getLines().second << "\nisColinear: " << i.isIsColinear() <<
                " }";
            } else {
                output << "Intersection{ IntersectionPoint: NULL" << "\nLine 1: " <<
                *i.getLines().first << "\nLine 2: " << *i.getLines().second << "\nisColinear: " << i.isIsColinear() <<
                " }";
            }
            return output;
        }


        bool operator==(const Inters::Intersection &i) {
            return (this->getIntersectionPoint() == i.getIntersectionPoint() &&
                    ((this->getLines().first && i.getLines().first && this->getLines().second && i.getLines().second)
                     ||
                     (this->getLines().second && i.getLines().first && this->getLines().first && i.getLines().second)));
        }


    };
}


#endif //INTERSCPP_INTERSECTION_H
