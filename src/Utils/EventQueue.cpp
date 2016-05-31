#include "../../headers/Utils/EventQueue.h"

void Inters::EventQueue::addEvent(Event *e) {

    std::map<Point *, Event *>::iterator iterator = eventQueue.find(e->getPoint());

    if (iterator == eventQueue.end()) {
        eventQueue[e->getPoint()] = e;
    } else {
        eventQueue[e->getPoint()] = mergeEvents(iterator->second, e);
    }
}


Inters::Event *Inters::EventQueue::getEvent() {
    if (eventQueue.size() == 0) {
        return NULL;
    }
    Event *e = std::move(eventQueue.begin()->second);
    eventQueue.erase(eventQueue.begin());
    return e;
}

Inters::Event *Inters::EventQueue::mergeEvents(Event *e1, Event *e2) {

    e1->getLefts()->splice(e1->getLefts()->end(), *e2->getLefts());
    e1->getRights()->splice(e1->getRights()->end(), *e2->getRights());
    e1->getIntersections()->splice(e1->getIntersections()->end(), *e2->getIntersections());

    return e1;
}