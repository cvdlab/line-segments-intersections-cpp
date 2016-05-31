#include "../../headers/catch.hpp"
#include "../../headers/Utils/EventQueue.h"
#include "../../headers/Utils/Intersection.h"

TEST_CASE("Test EventQueue", "[EventQueue]") {

    Inters::EventQueue *eventQueue = new Inters::EventQueue();
    Inters::Event *e1;
    Inters::Event *e2;
    Inters::Event *e3;

    Inters::Point *eventPoint1;
    Inters::Point *eventPoint2;
    Inters::Point *eventPoint3;

    eventPoint1 = new Inters::Point(1, 1);
    eventPoint2 = new Inters::Point(3, 3);
    eventPoint3 = new Inters::Point(3, 3);

    Inters::Line *l1, *l2, *l3;

    l1 = new Inters::Line(new Inters::Point(1, 2), new Inters::Point(5, 6));
    l2 = new Inters::Line(new Inters::Point(3, 4), new Inters::Point(6, 7));
    l3 = new Inters::Line(new Inters::Point(5, 6), new Inters::Point(7, 8));

    std::list<Inters::Line *> *lefts1, *lefts2, *lefts3;
    std::list<Inters::Line *> *rights1, *rights2, *rights3;
    std::list<std::pair<Inters::Line *, Inters::Line *> > *intersections1, *intersections2, *intersections3;

    lefts1 = new std::list<Inters::Line *>();
    lefts2 = new std::list<Inters::Line *>();
    lefts3 = new std::list<Inters::Line *>();

    rights1 = new std::list<Inters::Line *>();
    rights2 = new std::list<Inters::Line *>();
    rights3 = new std::list<Inters::Line *>();

    intersections1 = new std::list<std::pair<Inters::Line *, Inters::Line *> >();
    intersections2 = new std::list<std::pair<Inters::Line *, Inters::Line *> >();
    intersections3 = new std::list<std::pair<Inters::Line *, Inters::Line *> >();

    lefts1->push_back(l1);
    lefts2->push_back(l2);
    lefts3->push_back(l3);

    rights1->push_back(l3);
    rights2->push_back(l2);
    rights3->push_back(l1);

    intersections1->push_back(std::pair<Inters::Line *, Inters::Line *>(l1, l2));
    intersections2->push_back(std::pair<Inters::Line *, Inters::Line *>(l2, l3));
    intersections3->push_back(std::pair<Inters::Line *, Inters::Line *>(l1, l3));

    e1 = new Inters::Event(eventPoint1, rights1, lefts1, intersections1);
    e2 = new Inters::Event(eventPoint2, rights2, lefts2, intersections2);
    e3 = new Inters::Event(eventPoint3, rights3, lefts3, intersections3);

    SECTION("Add a single Event to the queue") {
        eventQueue->addEvent(e1);
        REQUIRE(eventQueue->getEvent() == e1);
    }

    SECTION("Add two Events in order to the queue") {
        eventQueue->addEvent(e1);
        eventQueue->addEvent(e2);
        REQUIRE(eventQueue->getEvent() == e1);
        REQUIRE(eventQueue->getEvent() == e2);
    }

    SECTION("Add two Events without following order to the queue") {
        eventQueue->addEvent(e2);
        eventQueue->addEvent(e1);

        REQUIRE(eventQueue->getEvent() == e1);
        REQUIRE(eventQueue->getEvent() == e2);
    }

    SECTION("Get an Event from an empty queue") {
        REQUIRE(eventQueue->getEvent() == NULL);
    }

    SECTION("Add two events with the same point") {
        eventQueue->addEvent(e2);
        eventQueue->addEvent(e1);
        eventQueue->addEvent(e3);

        Inters::Event *mergedEvent;
        REQUIRE(eventQueue->getEvent() == e1);
        mergedEvent = eventQueue->getEvent();
        REQUIRE(eventQueue->getEvent() == NULL);

        REQUIRE(*mergedEvent->getPoint() == *e2->getPoint());
        REQUIRE(mergedEvent->getLefts()->size() == 2);
        REQUIRE(mergedEvent->getRights()->size() == 2);

        REQUIRE(**mergedEvent->getLefts()->begin() == *l2);
        REQUIRE(*mergedEvent->getLefts()->back() == *l3);

        REQUIRE(**mergedEvent->getRights()->begin() == *l2);
        REQUIRE(*mergedEvent->getRights()->back() == *l1);
    }
}
