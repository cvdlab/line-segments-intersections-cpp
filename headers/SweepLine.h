//
// Created by danilo on 09/05/16.
//

#ifndef INTERSCPP_SWEEPLINE_H
#define INTERSCPP_SWEEPLINE_H

#include "Utils/Event.h"
#include "Utils/AVLTree.h"
#include "Utils/EventQueue.h"

// the Sweep Line itself
namespace Inters {
    class SweepLine {
        std::list<Line *> lines; //List of lines
        AVLTree Tree;      // balanced binary tree
        std::list<Intersection *> intersections;
        EventQueue eventQueue;

    public:

        SweepLine(const list<Line *> &lines) {
            this->lines = lines;
        }

        ~SweepLine(void) { delete &Tree; } // destructor

        void handleEvent(Event *E);

    private:

        void add(Event *);

        void remove(Event *);

        void swapLines(Event *E);

        bool addIntersectionToList(Intersection *intersection);
    };
}

#endif //INTERSCPP_SWEEPLINE_H
