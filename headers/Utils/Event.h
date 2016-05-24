#ifndef INTERSCPP_EVENT_H
#define INTERSCPP_EVENT_H

#include <utility>
#include <list>
#include "Point.h"
#include "Line.h"

namespace Inters {
    class Event {
    public:
        Point *point;
        std::list<Line> rights;
        std::list<Line> lefts;
        std::list<std::pair<Line *, Line *> > intersections;


        Event(Point
              *point,
              std::list<Line> right, std::list<Line> left,
              std::list<std::pair<Line *, Line *> > &intersections
        ) :

                point(point), rights(right),
                lefts(left),
                intersections(intersections) { }

        Point *getPoint() const {
            return point;
        }

        std::list<Line> getRights() const {
            return rights;
        }

        std::list<Line> getLefts() const {
            return lefts;
        }

        const std::list<std::pair<Line *, Line *> > getIntersections() const {
            return intersections;
        }

        /** Overloading math operators **/
        friend bool operator<(const Event &c1);

        friend bool operator>(const Event &c1);

        friend bool operator==(const Event &c1);

        friend bool operator<=(const Event &c1);

        friend bool operator>=(const Event &c1);

    };
}

#endif //INTERSCPP_EVENT_H
