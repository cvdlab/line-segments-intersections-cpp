#include "../../headers/catch.hpp"
#include "../../headers/Utils/LineUtils.h"

TEST_CASE("Test determinant", "[LineUtils]") {

    SECTION("Determinant is not zero") {
        Inters::LineUtils lineUtils;
        REQUIRE(lineUtils.determinant(5, 2, 4, 3) == 7);
    }

    SECTION("Determinant is zero") {
        Inters::LineUtils lineUtils;
        REQUIRE(lineUtils.determinant(5, 2, 0, 0) == 0);
        REQUIRE(lineUtils.determinant(15, 10, 3, 2) == 0);
    }

    SECTION("Determinant is negative") {
        Inters::LineUtils lineUtils;
        REQUIRE(lineUtils.determinant(5, 6, 1, 1) == -1);
        REQUIRE(lineUtils.determinant(-15, 10, 3, 2) == -60);
    }
}

TEST_CASE("Test find intersection", "[LineUtils]") {

    Inters::Point *p1, *p2, *p3, *p4, *expectedIntersectionPoint;
    Inters::Line *l1, *l2;

    Inters::Intersection *intersection;

    Inters::LineUtils lineUtils;

    SECTION("l1 and l2 have an intersection in the middle") {
        p1 = new Inters::Point(0, 5);
        p2 = new Inters::Point(10, 5);

        p3 = new Inters::Point(5, 0);
        p4 = new Inters::Point(5, 10);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        expectedIntersectionPoint = new Inters::Point(5, 5);

        intersection = lineUtils.findIntersection(l1, l2);

        REQUIRE(*intersection->getIntersectionPoint() == *expectedIntersectionPoint);
        REQUIRE(*intersection->getLines().first == *l1);
        REQUIRE(*intersection->getLines().second == *l2);
        REQUIRE_FALSE(intersection->isIsColinear());

    }

    SECTION("l1 and l2 do not have intersections") {
        p1 = new Inters::Point(0, 5);
        p2 = new Inters::Point(10, 5);

        p3 = new Inters::Point(15, 0);
        p4 = new Inters::Point(15, 10);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        intersection = lineUtils.findIntersection(l1, l2);

        REQUIRE(intersection == NULL);
    }

    SECTION("l1 and l2 are colinear") {
        p1 = new Inters::Point(0, 5);
        p2 = new Inters::Point(10, 5);

        p3 = new Inters::Point(4, 5);
        p4 = new Inters::Point(15, 5);

        l1 = new Inters::Line(p1, p2);
        l2 = new Inters::Line(p3, p4);

        expectedIntersectionPoint = NULL;

        intersection = lineUtils.findIntersection(l1, l2);

        REQUIRE(intersection->getIntersectionPoint() == expectedIntersectionPoint);
        REQUIRE(*intersection->getLines().first == *l1);
        REQUIRE(*intersection->getLines().second == *l2);
        REQUIRE(intersection->isIsColinear());

    }
}

TEST_CASE("Test vertical intersection", "[LineUtils]") {

    Inters::Point *p1, *p2, *expectedIntersectionPoint, *intersectionPoint;

    double sweepLine;
    Inters::Line *l1;

    Inters::LineUtils lineUtils;

    SECTION("l1 has an intersection in the middle") {
        p1 = new Inters::Point(0, 5);
        p2 = new Inters::Point(10, 5);

        sweepLine = 5;

        l1 = new Inters::Line(p1, p2);

        expectedIntersectionPoint = new Inters::Point(5, 5);

        intersectionPoint = lineUtils.findVerticalIntersection(l1, sweepLine);

        REQUIRE(*intersectionPoint == *expectedIntersectionPoint);
    }

    SECTION("l1 and the sweepline do not intersect") {
        p1 = new Inters::Point(0, 5);
        p2 = new Inters::Point(10, 5);

        sweepLine = 25;

        l1 = new Inters::Line(p1, p2);

        intersectionPoint = lineUtils.findVerticalIntersection(l1, sweepLine);

        REQUIRE(intersectionPoint == NULL);
    }

    SECTION("l1 is vertical") {
        p1 = new Inters::Point(5, 0);
        p2 = new Inters::Point(5, 10);

        sweepLine = 5;

        l1 = new Inters::Line(p1, p2);

        expectedIntersectionPoint = new Inters::Point(5, 0);

        intersectionPoint = lineUtils.findVerticalIntersection(l1, sweepLine);

        REQUIRE(*intersectionPoint == *expectedIntersectionPoint);
    }
}

