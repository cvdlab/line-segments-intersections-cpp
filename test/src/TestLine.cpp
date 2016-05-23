#include "../../headers/catch.hpp"
#include "../../headers/Utils/Line.h"

#include <iostream>

TEST_CASE("Test line greater than operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    Inters::Point *p3;
    Inters::Point *p4;

    Inters::Line *l1;
    Inters::Line *l2;

    SECTION("l1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE(*l1 > *l2);
    }

    SECTION("p1 has greater y and lower x") {

        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE(*l1 > *l2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE_FALSE(*l1 > *l2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE_FALSE(*l1 > *l2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(4, 1);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE(*l1 > *l2);
    }

    SECTION("p1 and p3 are equal") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(1, 0);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE_FALSE(*l1 > *l2);
    }

}

TEST_CASE("Test line greater than or equal operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    Inters::Point *p3;
    Inters::Point *p4;

    Inters::Line *l1;
    Inters::Line *l2;

    SECTION("l1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE(*l1 >= *l2);
    }

    SECTION("p1 has greater y and lower x") {

        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE(*l1 >= *l2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE_FALSE(*l1 >= *l2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE_FALSE(*l1 >= *l2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(4, 1);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE(*l1 >= *l2);
    }

    SECTION("p1 and p3 are equal") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(1, 0);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE(*l1 >= *l2);
    }

}

TEST_CASE("Test line less than operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    Inters::Point *p3;
    Inters::Point *p4;

    Inters::Line *l1;
    Inters::Line *l2;

    SECTION("l1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE_FALSE(*l1 < *l2);
    }

    SECTION("p1 has greater y and lower x") {

        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE_FALSE(*l1 < *l2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE(*l1 < *l2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE(*l1 < *l2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(4, 1);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE_FALSE(*l1 < *l2);
    }

    SECTION("p1 and p3 are equal") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(1, 0);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE_FALSE(*l1 < *l2);
    }

}

TEST_CASE("Test line less than or equal operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    Inters::Point *p3;
    Inters::Point *p4;

    Inters::Line *l1;
    Inters::Line *l2;

    SECTION("l1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE_FALSE(*l1 <= *l2);
    }

    SECTION("p1 has greater y and lower x") {

        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE_FALSE(*l1 <= *l2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE(*l1 <= *l2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE(*l1 <= *l2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(4, 1);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE_FALSE(*l1 <= *l2);
    }

    SECTION("p1 and p3 are equal") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(1, 0);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE(*l1 <= *l2);
    }

}

TEST_CASE("Test line equal operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    Inters::Point *p3;
    Inters::Point *p4;

    Inters::Line *l1;
    Inters::Line *l2;

    SECTION("l1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE_FALSE(*l1 == *l2);
    }

    SECTION("p1 has greater y and lower x") {

        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE_FALSE(*l1 == *l2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE_FALSE(*l1 == *l2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);
        REQUIRE_FALSE(*l1 == *l2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(4, 1);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(2, 1);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE_FALSE(*l1 == *l2);
    }

    SECTION("p1 and p3 are equal") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(9, 9);

        p3 = new Inters::Point(1, 0);
        p4 = new Inters::Point(6, 7);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        REQUIRE(*l1 == *l2);
    }

}