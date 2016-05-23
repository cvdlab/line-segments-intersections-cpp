#include "../../headers/catch.hpp"
#include "../../headers/Utils/Line.h"

TEST_CASE("Test greater than operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    Inters::Point *p3;
    Inters::Point *p4;

    SECTION("l1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        p3 = new Inters::Point(3, 4);
        p4 = new Inters::Point(2, 1);

        REQUIRE(*p1 > *p2);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        REQUIRE(*p1 > *p2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 > *p2) == false);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 > *p2) == false);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        REQUIRE(*p1 > *p2);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        REQUIRE((*p1 > *p2) == false);
    }

}

TEST_CASE("Test less than operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    SECTION("p1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 < *p2) == false);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 < *p2) == false);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE(*p1 < *p2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE(*p1 < *p2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 < *p2) == false);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        REQUIRE((*p1 < *p2) == false);
    }

}

TEST_CASE("Test greater than or equal operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    SECTION("p1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        REQUIRE(*p1 >= *p2);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        REQUIRE(*p1 >= *p2);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 >= *p2) == false);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 >= *p2) == false);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        REQUIRE(*p1 >= *p2);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        REQUIRE(*p1 >= *p2);
    }

}

TEST_CASE("Test less than or equal operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    SECTION("p1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 <= *p2) == false);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 <= *p2) == false);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE(*p1 <= *p2);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE(*p1 <= *p2);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 <= *p2) == false);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        REQUIRE(*p1 <= *p2);
    }

}

TEST_CASE("Test equal operator", "[Line]") {

    Inters::Point *p1;
    Inters::Point *p2;

    SECTION("p1 has greater y and greater x") {
        p1 = new Inters::Point(3, 4);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 == *p2) == false);
    }

    SECTION("p1 has greater y and lower x") {
        p1 = new Inters::Point(1, 4);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 == *p2) == false);
    }

    SECTION("p1 has lower y and lower x") {
        p1 = new Inters::Point(1, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 == *p2) == false);
    }

    SECTION("p1 has lower y and greater x") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 == *p2) == false);
    }

    SECTION("p1 has same y and greater x") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(2, 1);

        REQUIRE((*p1 == *p2) == false);
    }

    SECTION("p1 and p2 are equal") {
        p1 = new Inters::Point(5, 1);
        p2 = new Inters::Point(5, 1);

        REQUIRE(*p1 == *p2);
    }

}