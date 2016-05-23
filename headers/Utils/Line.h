//
// Created by danilo on 11/05/16.
//

#ifndef INTERSCPP_LINE_H
#define INTERSCPP_LINE_H

#include "Point.h"

namespace Inters {
    class Line {

        Point *v0;
        Point *v1;

    public:

        Line(Point v0, Point v1) {
            this->v0 = &v0;
            this->v1 = &v1;
        }

        Point *getV0() const {
            return v0;
        }

        Point *getV1() const {
            return v1;
        }

        ~Line() {
            delete v0;
            delete v1;
        }

        /** Overloading math operators **/
        friend bool operator<(const Line &l1, const Line &l2);

        friend bool operator>(const Line &l1, const Line &l2);

        friend bool operator==(const Line &l1, const Line &l2);

        friend bool operator<=(const Line &l1, const Line &l2);

        friend bool operator>=(const Line &l1, const Line &l2);

    };
}

#endif //INTERSCPP_LINE_H
