#include "../../headers/catch.hpp"
#include "../../headers/Utils/Intersection.h"

TEST_CASE("Test Equal function for Intersection class", "[Intersection]") {

    Inters::Point *p1;
    Inters::Point *p2;

    Inters::Line *l1;
    Inters::Line *l2;

    Inters::Line *l3;
    Inters::Line *l4;

    Inters::Intersection *i1;
    Inters::Intersection *i2;

    SECTION("Same Intersection point but different Lines") {
        p1 = new Inters::Point(4, 4);
        p2 = new Inters::Point(4, 4);

        l1 = new Inters::Line(new Inters::Point(3, 3), new Inters::Point(5, 5));
        l2 = new Inters::Line(new Inters::Point(2, 2), new Inters::Point(5, 5));

        l3 = new Inters::Line(new Inters::Point(13, 13), new Inters::Point(15, 15));
        l4 = new Inters::Line(new Inters::Point(12, 12), new Inters::Point(15, 15));

        i1 = new Inters::Intersection(p1, std::pair<Inters::Line *, Inters::Line *>(l1, l2), false);
        i2 = new Inters::Intersection(p2, std::pair<Inters::Line *, Inters::Line *>(l3, l4), false);

        REQUIRE_FALSE(*i1 == *i2);
    }

    SECTION("Different Intersection point and different Lines") {
        p1 = new Inters::Point(4, 4);
        p2 = new Inters::Point(6, 4);

        l1 = new Inters::Line(new Inters::Point(3, 3), new Inters::Point(5, 5));
        l2 = new Inters::Line(new Inters::Point(2, 2), new Inters::Point(5, 5));

        l3 = new Inters::Line(new Inters::Point(13, 13), new Inters::Point(15, 15));
        l4 = new Inters::Line(new Inters::Point(12, 12), new Inters::Point(15, 15));

        i1 = new Inters::Intersection(p1, std::pair<Inters::Line *, Inters::Line *>(l1, l2), false);
        i2 = new Inters::Intersection(p2, std::pair<Inters::Line *, Inters::Line *>(l3, l4), false);

        REQUIRE_FALSE(*i1 == *i2);
    }

    SECTION("Same Intersection point and same Lines") {
        p1 = new Inters::Point(4, 4);
        p2 = new Inters::Point(4, 4);

        l1 = new Inters::Line(new Inters::Point(3, 3), new Inters::Point(5, 5));
        l2 = new Inters::Line(new Inters::Point(2, 2), new Inters::Point(5, 5));

        i1 = new Inters::Intersection(p1, std::pair<Inters::Line *, Inters::Line *>(l1, l2), false);
        i2 = new Inters::Intersection(p2, std::pair<Inters::Line *, Inters::Line *>(l1, l2), false);

        REQUIRE(*i1 == *i2);
    }

    SECTION("Same Intersection point and same Lines but in different order") {
        p1 = new Inters::Point(4, 4);
        p2 = new Inters::Point(4, 4);

        l1 = new Inters::Line(new Inters::Point(3, 3), new Inters::Point(5, 5));
        l2 = new Inters::Line(new Inters::Point(2, 2), new Inters::Point(5, 5));

        i1 = new Inters::Intersection(p1, std::pair<Inters::Line *, Inters::Line *>(l1, l2), false);
        i2 = new Inters::Intersection(p2, std::pair<Inters::Line *, Inters::Line *>(l2, l1), false);

        REQUIRE(*i1 == *i2);
    }

}