//
// Created by danilo on 09/05/16.
//

#ifndef INTERSCPP_POINT_H
#define INTERSCPP_POINT_H

#include <ostream>

namespace Inters {
    class Point {

        double x, y;

    public:

        Point(double x, double y) {
            this->x = x;
            this->y = y;
        }


        double getX() const {
            return x;
        }

        double getY() const {
            return y;
        }

        bool operator>(const Point &p1) {

            if (this->getY() == p1.getY()) {
                return this->getX() > p1.getX();
            }

            return this->getY() > p1.getY();
        }

        bool operator<(const Point &p1) {
            if (this->getY() == p1.getY()) {
                return this->getX() < p1.getX();
            }

            return this->getY() < p1.getY();
        }

        bool operator==(const Point &p1) {
            return this->getY() == p1.getY() && this->getX() == p1.getX();
        }

        bool operator<=(const Point &p1) {
            if (this->getY() == p1.getY()) {
                return this->getX() <= p1.getX();
            }

            return this->getY() < p1.getY();
        }

        bool operator>=(const Point &p1) {
            if (this->getY() == p1.getY()) {
                return this->getX() >= p1.getX();
            }

            return this->getY() > p1.getY();
        }

        friend std::ostream &operator<<(std::ostream &output,
                                        const Point &p) {
            output << "Point(" << p.getX() << "," << p.getY() << ")";
            return output;
        }


    };
}

#endif //INTERSCPP_POINT_H
