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
        std::list<Line *> rights;
        std::list<Line *> lefts;
        std::list<std::pair<Line *, Line *> > intersections;


        Event(Point *point,
              std::list<Line *> rights, std::list<Line *> lefts,
              std::list<std::pair<Line *, Line *> > intersections
        ) :

                point(point), rights(rights),
                lefts(lefts),
                intersections(intersections) { }

        ~Event() {
            delete point;
        }

        Point *getPoint() const {
            return point;
        }

        std::list<Line *> getRights() const {
            return rights;
        }

        std::list<Line *> getLefts() const {
            return lefts;
        }

        const std::list<std::pair<Line *, Line *> > getIntersections() const {
            return intersections;
        }

        /** Overloading math operators **/
        bool operator<(const Inters::Event &e1) {
            return *this->getPoint() < *e1.getPoint();
        };

        bool operator>(const Inters::Event &e1) {
            return *this->getPoint() > *e1.getPoint();
        }

        bool operator==(const Inters::Event &e1) {
            return *this->getPoint() == *e1.getPoint();
        }

        bool operator<=(const Inters::Event &e1) {
            return *this->getPoint() <= *e1.getPoint();
        }

        bool operator>=(const Inters::Event &e1) {
            return *this->getPoint() >= *e1.getPoint();
        }

        friend std::ostream &operator<<(std::ostream &output,
                                        const Event &e) {
            output << "Event: {" << *e.getPoint() << "}";
            return output;
        }


    };
}

#endif //INTERSCPP_EVENT_H
