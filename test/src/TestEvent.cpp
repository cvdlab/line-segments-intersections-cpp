#include "../../headers/catch.hpp"
#include "../../headers/Utils/Event.h"

TEST_CASE("Test Event greater than operator", "[Event]") {

    Inters::Point *p1;
    Inters::Point *p2;

    std::list<Inters::Line *> *rights = new std::list<Inters::Line *>();
    std::list<Inters::Line *> *lefts = new std::list<Inters::Line *>();
    std::list<std::pair<Inters::Line *, Inters::Line *> > *intersections =
            new std::list<std::pair<Inters::Line *, Inters::Line *> >();


    Inters::Event *e1;
    Inters::Event *e2;

    SECTION("p1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 > *e2);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 > *e2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 > *e2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 > *e2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 > *e2);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 > *e2);
    }

}

TEST_CASE("Test Event less than operator", "[Event]") {

    Inters::Point *p1;
    Inters::Point *p2;

    std::list<Inters::Line *> *rights = new std::list<Inters::Line *>();
    std::list<Inters::Line *> *lefts = new std::list<Inters::Line *>();
    std::list<std::pair<Inters::Line *, Inters::Line *> > *intersections =
            new std::list<std::pair<Inters::Line *, Inters::Line *> >();

    Inters::Event *e1;
    Inters::Event *e2;

    SECTION("p1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 < *e2);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 < *e2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 < *e2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 < *e2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 < *e2);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 < *e2);
    }

}

TEST_CASE("Test Event greater than or equal operator", "[Event]") {

    Inters::Point *p1;
    Inters::Point *p2;

    std::list<Inters::Line *> *rights = new std::list<Inters::Line *>();
    std::list<Inters::Line *> *lefts = new std::list<Inters::Line *>();
    std::list<std::pair<Inters::Line *, Inters::Line *> > *intersections =
            new std::list<std::pair<Inters::Line *, Inters::Line *> >();

    Inters::Event *e1;
    Inters::Event *e2;

    SECTION("p1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 >= *e2);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 >= *e2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 >= *e2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 >= *e2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 >= *e2);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 >= *e2);
    }

}

TEST_CASE("Test Event less than or equal operator", "[Event]") {

    Inters::Point *p1;
    Inters::Point *p2;

    std::list<Inters::Line *> *rights = new std::list<Inters::Line *>();
    std::list<Inters::Line *> *lefts = new std::list<Inters::Line *>();
    std::list<std::pair<Inters::Line *, Inters::Line *> > *intersections =
            new std::list<std::pair<Inters::Line *, Inters::Line *> >();

    Inters::Event *e1;
    Inters::Event *e2;

    SECTION("p1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 <= *e2);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 <= *e2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 <= *e2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 <= *e2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 <= *e2);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 <= *e2);
    }

}

TEST_CASE("Test Event equal operator", "[Event]") {

    Inters::Point *p1;
    Inters::Point *p2;

    std::list<Inters::Line *> *rights = new std::list<Inters::Line *>();
    std::list<Inters::Line *> *lefts = new std::list<Inters::Line *>();
    std::list<std::pair<Inters::Line *, Inters::Line *> > *intersections =
            new std::list<std::pair<Inters::Line *, Inters::Line *> >();

    Inters::Event *e1;
    Inters::Event *e2;

    SECTION("p1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 == *e2);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 == *e2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 == *e2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 == *e2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE_FALSE(*e1 == *e2);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        e1 = new Inters::Event(p1, rights, lefts, intersections);
        e2 = new Inters::Event(p2, rights, lefts, intersections);

        REQUIRE(*e1 == *e2);
    }

}