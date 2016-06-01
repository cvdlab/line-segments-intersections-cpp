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
        std::list<Line *> *lines; //List of lines
        AVLTree *Tree;      // balanced binary tree
        std::list<Intersection *> intersections;
        EventQueue *eventQueue;

    public:

        SweepLine(list<Line *> *lines) {
            this->lines = lines;
            this->Tree = new AVLTree();
            initEventQueue();
        }

        ~SweepLine(void) {
            delete Tree;
            delete eventQueue;
        } // destructor

        Inters::Event *handleEvent();

    private:

        void add(Event *);

        void remove(Event *);

        void swapLines(Event *E);

        bool addIntersectionToList(Intersection *intersection);

        void initEventQueue();
    };
}

#endif //INTERSCPP_SWEEPLINE_H
