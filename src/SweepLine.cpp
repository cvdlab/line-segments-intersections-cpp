#include "../headers/SweepLine.h"
#include <algorithm>

/** It handles a single event of the queue and returns the handled event **/
Inters::Event *Inters::SweepLine::handleEvent() {
    Event *E = this->eventQueue->getEvent();
    if (E != NULL) {
        add(E);
        remove(E);
        swapLines(E);
    }

    return E;
}

void Inters::SweepLine::add(Event *E) {


    double sweepLinePointX = E->getPoint()->getX();
    this->Tree->setCurrentSweepPointX(sweepLinePointX);

    /* Now I have to add all segments in lefts list */

    std::list<Line *> *left = E->getLefts();

    std::list<Line *>::const_iterator iterator;
    for (iterator = left->begin(); iterator != left->end(); ++iterator) {
        AvlNode *insertedNode = this->Tree->insert(*iterator);

        /* Now I can check for intersections */
        AvlNode *previousNode = this->Tree->prev(insertedNode);
        AvlNode *nextNode = this->Tree->next(insertedNode);
        LineUtils lineUtils;
        Line *currentLine = insertedNode->Key();

        if (previousNode != NULL) {
            Line *previousLine = previousNode->Key();
            Intersection *intersectionPrev = lineUtils.findIntersection(previousLine, currentLine);

            if (addIntersectionToList(intersectionPrev)) {
                std::list<pair<Line *, Line *> > *couples = new std::list<pair<Line *, Line *> >();
                couples->push_back(intersectionPrev->getLines());
                std::list<Line *> *rights = new std::list<Line *>();
                std::list<Line *> *lefts = new std::list<Line *>();
                this->eventQueue->addEvent(new Event(intersectionPrev->getIntersectionPoint(), rights, lefts, couples));
            }
        }

        if (nextNode != NULL) {
            Line *nextLine = nextNode->Key();

            Intersection *intersectionNext = lineUtils.findIntersection(currentLine, nextLine);

            if (addIntersectionToList(intersectionNext)) {
                std::list<pair<Line *, Line *> > *couples = new std::list<std::pair<Line *, Line *> >();
                couples->push_back(intersectionNext->getLines());
                std::list<Line *> *rights = new std::list<Line *>();
                std::list<Line *> *lefts = new std::list<Line *>();
                this->eventQueue->addEvent(new Event(intersectionNext->getIntersectionPoint(), rights, lefts, couples));
            }

        }

    }
}

void Inters::SweepLine::remove(Event *E) {

    double sweepLinePointX = E->getPoint()->getX();
    this->Tree->setCurrentSweepPointX(sweepLinePointX);

    /* Now I have to remove all segments in rights list */

    std::list<Line *> *right = E->getRights();

    std::list<Line *>::const_iterator iterator;
    for (iterator = right->begin(); iterator != right->end(); ++iterator) {


        AvlNode *nodeToRemove = this->Tree->search(*iterator); //Search the line we want to remove

        /* Now I can check for intersections */
        AvlNode *previousNode = this->Tree->prev(nodeToRemove);
        AvlNode *nextNode = this->Tree->next(nodeToRemove);
        LineUtils lineUtils;

        if (previousNode != NULL && nextNode != NULL) {

            Line *previousLine = previousNode->Key();
            Line *nextLine = nextNode->Key();

            Intersection *intersection = lineUtils.findIntersection(previousLine, nextLine);

            if (addIntersectionToList(intersection)) {
                std::list<pair<Line *, Line *> > *couples = new std::list<std::pair<Line *, Line *> >();
                couples->push_back(intersection->getLines());
                std::list<Line *> *rights = new std::list<Line *>();
                std::list<Line *> *lefts = new std::list<Line *>();
                this->eventQueue->addEvent(new Event(intersection->getIntersectionPoint(), rights, lefts, couples));
            }

        }
        this->Tree->remove(*iterator); // Remove the line from the tree
    }
}

void Inters::SweepLine::swapLines(Event *E) {
    std::list<pair<Line *, Line *> > *intersections = E->getIntersections();

    std::list<pair<Line *, Line *> >::const_iterator iterator;
    for (iterator = intersections->begin(); iterator != intersections->end(); ++iterator) {
        pair<Line *, Line *> linesCouple = *iterator;
        AvlNode *firstLineNode = this->Tree->search(linesCouple.first);
        AvlNode *secondLineNode = this->Tree->search(linesCouple.second);

        AvlNode *previousNode = this->Tree->prev(firstLineNode);
        AvlNode *nextNode = this->Tree->next(secondLineNode);

        if (previousNode != NULL && nextNode != NULL) {
            Line *previousLine = previousNode->Key();
            Line *nextLine = nextNode->Key();

            LineUtils lineUtils;
            Intersection *intersection = lineUtils.findIntersection(previousLine, nextLine);

            if (addIntersectionToList(intersection)) {
                std::list<pair<Line *, Line *> > *couples = new std::list<std::pair<Line *, Line *> >();
                couples->push_back(intersection->getLines());
                std::list<Line *> *rights = new std::list<Line *>();
                std::list<Line *> *lefts = new std::list<Line *>();
                this->eventQueue->addEvent(new Event(intersection->getIntersectionPoint(), rights, lefts, couples));
            }

        }


        this->Tree->remove(linesCouple.first);
        this->Tree->remove(linesCouple.second);

        this->Tree->insert(linesCouple.second);
        this->Tree->insert(linesCouple.first);

    }
}

/** Adds an intersection to the list of intersections and return false if the intersection was
 * already there or true if it was not found before **/
bool Inters::SweepLine::addIntersectionToList(Intersection *intersection) {

    std::list<Intersection *>::iterator findIter = std::find(intersections.begin(), intersections.end(),
                                                             intersection);

    if (findIter == intersections.end()) {
        intersections.push_back(intersection);
        return true;
    }

    return false;
}

void Inters::SweepLine::initEventQueue() {
    this->eventQueue = new EventQueue();
    std::list<Line *>::const_iterator iterator;
    for (iterator = this->lines->begin(); iterator != this->lines->end(); ++iterator) {

        Point *leftPoint = std::min((*iterator)->getV0(), (*iterator)->getV1());
        Point *rightPoint = std::max((*iterator)->getV0(), (*iterator)->getV1());

        std::list<Line *> *rights1 = new std::list<Line *>();
        std::list<Line *> *lefts1 = new std::list<Line *>();
        std::list<std::pair<Line *, Line *> > *intersections1 = new std::list<std::pair<Line *, Line *>>();

        std::list<Line *> *rights2 = new std::list<Line *>();
        std::list<Line *> *lefts2 = new std::list<Line *>();
        std::list<std::pair<Line *, Line *> > *intersections2 = new std::list<std::pair<Line *, Line *>>();

        lefts1->push_back(*iterator);
        rights1->push_back(*iterator);

        this->eventQueue->addEvent(new Inters::Event(leftPoint, lefts1, rights1, intersections1));
        this->eventQueue->addEvent(new Inters::Event(rightPoint, lefts2, rights2, intersections2));
    }

}


