//
// Created by danilo on 11/05/16.
//

#ifndef INTERSCPP_LINEUTILS_H
#define INTERSCPP_LINEUTILS_H


#include "Point.h"
#include "Line.h"
#include "Intersection.h"

namespace Inters {
    class LineUtils {

    public:
        Intersection *findIntersection(Line *l1, Line *l2);

        double determinant(double m1, double m2, double m3, double m4);

        Point *findVerticalIntersection(Line *l1, double verticalLineX);
    };
}

#endif //INTERSCPP_LINEUTILS_H
