#ifndef INTERSCPP_LINECOMPARABLE_H
#define INTERSCPP_LINECOMPARABLE_H

#include "../../headers/Utils/Comparable.h"

class LineComparable : public Comparable<Inters::Line> {

public:
    LineComparable(Inters::Line line) : Comparable<Inters::Line>(line) { };

    cmp_t Compare(Inters::Line line) { Comparable<Inters::Line>::Compare(line); };

    cmp_t Compare(Inters::Line line, double sweepLine);

};

#endif //INTERSCPP_LINECOMPARABLE_H
