#ifndef INTERSCPP_EVENTQUEUE_H
#define INTERSCPP_EVENTQUEUE_H

#include <map>
#include "Point.h"
#include "Event.h"

/** This class maps an abstract EventQueue (which is a priority queue) with an implementation based on a stl map */

namespace Inters {
    class EventQueue {
        std::map<Point *, Event *> eventQueue;
    public:
        EventQueue(const std::map<Point *, Event *> &eventQueue) : eventQueue(eventQueue) { }

        Event *getEvent();

        void addEvent(Event *e);

    private:
        Event *mergeEvents(Event *e1, Event *e2);
    };
}
#endif //INTERSCPP_EVENTQUEUE_H
