#ifndef INTERSCPP_EVENTQUEUE_H
#define INTERSCPP_EVENTQUEUE_H

#include <map>
#include "Point.h"
#include "Event.h"

/** This class maps an abstract EventQueue (which is a priority queue) with an implementation based on a stl map */


struct cmpByPoint {
    bool operator()(Inters::Point *p1, Inters::Point *p2) const {
        return *p1 < *p2;
    }
};

namespace Inters {
    class EventQueue {
        std::map<Point *, Event *, cmpByPoint> eventQueue;
    public:
        EventQueue() { }

        Event *getEvent();

        void addEvent(Event *e);

    private:
        Event *mergeEvents(Event *e1, Event *e2);
    };
}
#endif //INTERSCPP_EVENTQUEUE_H
