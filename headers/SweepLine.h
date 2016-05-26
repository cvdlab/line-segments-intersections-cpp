//
// Created by danilo on 09/05/16.
//

#ifndef INTERSCPP_SWEEPLINE_H
#define INTERSCPP_SWEEPLINE_H

#include "Utils/Point.h"
#include "Utils/Event.h"
#include "Utils/AVLTree.h"
#include "Utils/Line.h"
#include <list>

// the Sweep Line itself
namespace Inters {
    class SweepLine {
        std::list<Line> lines; //List of lines
        AVLtree Tree;      // balanced binary tree
        std::list<std::pair<std::pair<Line, Line>, Point> > intersections;

    public:
        SweepLine(std::list<Inters::Line> lines) : lines(lines) { }           // constructor

        ~SweepLine(void) { delete &Tree; } // destructor

        void handleEvent(Event *E);

    private:

        void add(Event *);

        void remove(Event *);

        void swapLines(Event *E);

        bool addIntersectionToList(Point *intersection,
                                   Line *l1, Line
                                   *l2);
    };
}

#endif //INTERSCPP_SWEEPLINE_H
