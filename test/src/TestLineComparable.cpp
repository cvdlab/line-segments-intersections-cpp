#include "../../headers/catch.hpp"
#include "../../headers/Utils/LineComparable.h"

TEST_CASE("Test compare Lines", "[LineComparable]") {

    Inters::Point *p1;
    Inters::Point *p2;

    Inters::Point *p3;
    Inters::Point *p4;

    Inters::Line *l1;
    Inters::Line *l2;

    double sweepLine;

    LineComparable *lineComparable;
    SECTION("Check l2 < l1 with sweepLine in the middle") {

        p1 = new Inters::Point(0, 0);
        p2 = new Inters::Point(10, 10);

        p3 = new Inters::Point(5, 4);
        p4 = new Inters::Point(15, 14);

        sweepLine = 5;

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        lineComparable = new LineComparable(l1);

        REQUIRE(lineComparable->Compare(l2, sweepLine) == -1);

    }

    SECTION("l2 > l1 without sweepLine in the middle") {

        p1 = new Inters::Point(0, 0);
        p2 = new Inters::Point(10, 10);

        p3 = new Inters::Point(5, 4);
        p4 = new Inters::Point(15, 14);


        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        lineComparable = new LineComparable(l1);

        REQUIRE(lineComparable->Compare(l2) == 1);

    }

    SECTION("l2 > l1 with sweepLine in the middle") {

        p1 = new Inters::Point(0, 0);
        p2 = new Inters::Point(10, 10);

        p3 = new Inters::Point(5, 8);
        p4 = new Inters::Point(15, 14);

        sweepLine = 5;

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        lineComparable = new LineComparable(l1);

        REQUIRE(lineComparable->Compare(l2, sweepLine) == 1);

    }

    SECTION("l2 > l1 without sweepLine in the middle") {

        p1 = new Inters::Point(0, 0);
        p2 = new Inters::Point(10, 10);

        p3 = new Inters::Point(5, 8);
        p4 = new Inters::Point(15, 14);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        lineComparable = new LineComparable(l1);

        REQUIRE(lineComparable->Compare(l2) == 1);

    }
}