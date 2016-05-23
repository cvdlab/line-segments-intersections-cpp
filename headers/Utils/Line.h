//
// Created by danilo on 11/05/16.
//

#ifndef INTERSCPP_LINE_H
#define INTERSCPP_LINE_H

#include "Point.h"
#include <ostream>

namespace Inters {
    class Line {

        Point *v0;
        Point *v1;

    public:

        Line(Point *v0, Point *v1) {
            this->v0 = v0;
            this->v1 = v1;
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
        bool operator<(const Inters::Line &l1) {
            return *this->getV0() < *l1.getV0();
        }

        bool operator>(const Inters::Line &l1) {
            return *this->getV0() > *l1.getV0();
        }

        bool operator==(const Inters::Line &l1) {
            return *this->getV0() == *l1.getV0();
        }

        bool operator<=(const Inters::Line &l1) {
            return *this->getV0() <= *l1.getV0();
        }

        bool operator>=(const Inters::Line &l1) {
            return *this->getV0() >= *l1.getV0();
        }

        friend std::ostream &operator<<(std::ostream &output,
                                        const Line &l) {
            output << "Line[" << *l.getV0() << " ; " << *l.getV1() << "]";
            return output;
        }

    };

}

#endif //INTERSCPP_LINE_H
