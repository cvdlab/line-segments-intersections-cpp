//
// Created by danilo on 09/05/16.
//

#include "../headers/SweepLine.h"
#include <algorithm>

/** It handles a single event of the queue **/
void Inters::SweepLine::handleEvent(Event *E) {
    add(E);
    remove(E);
    swapLines(E);
}

void Inters::SweepLine::add(Event *E) {


    double sweepLinePointX = E->getPoint()->getX();
    this->Tree.setCurrentSweepPointX(sweepLinePointX);

    /* Now I have to add all segments in lefts list */

    std::list<Line *> left = E->getLefts();

    std::list<Line *>::const_iterator iterator;
    for (iterator = left.begin(); iterator != left.end(); ++iterator) {
        AvlNode *insertedLine = this->Tree.insert(*iterator);

        /* Now I can check for intersections */
        Line *previousLine = this->Tree.prev(insertedLine)->Key();
        Line *nextLine = this->Tree.next(insertedLine)->Key();
        Line *currentLine = insertedLine->Key();
        LineUtils lineUtils;
        Intersection *intersectionPrev = lineUtils.findIntersection(previousLine, currentLine);
        Intersection *intersectionNext = lineUtils.findIntersection(currentLine, nextLine);

        if (addIntersectionToList(intersectionPrev)) {
            /*** ADD TO QUEUE ***/

        }

        if (addIntersectionToList(intersectionNext)) {
            /*** ADD TO QUEUE ***/
        }


    }
}

void Inters::SweepLine::remove(Event *E) {

    double sweepLinePointX = E->getPoint()->getX();
    this->Tree.setCurrentSweepPointX(sweepLinePointX);

    /* Now I have to remove all segments in rights list */

    std::list<Line *> right = E->getRights();

    std::list<Line *>::const_iterator iterator;
    for (iterator = right.begin(); iterator != right.end(); ++iterator) {


        AvlNode *nodeToRemove = this->Tree.search(*iterator); //Search the line we want to remove

        /* Now I can check for intersections */
        Line *previousLine = this->Tree.prev(nodeToRemove)->Key();
        Line *nextLine = this->Tree.next(nodeToRemove)->Key();
        LineUtils lineUtils;
        Intersection *intersection = lineUtils.findIntersection(previousLine, nextLine);

        if (addIntersectionToList(intersection)) {
            /*** ADD TO QUEUE ***/
        }

        this->Tree.remove(*iterator); // Remove the line from the tree
    }
}

void Inters::SweepLine::swapLines(Event *E) {
    std::list<pair<Line *, Line *> > intersections = E->getIntersections();

    std::list<pair<Line *, Line *> >::const_iterator iterator;
    for (iterator = intersections.begin(); iterator != intersections.end(); ++iterator) {
        pair<Line *, Line *> linesCouple = *iterator;
        AvlNode *firstLineNode = this->Tree.search(linesCouple.first);
        AvlNode *secondLineNode = this->Tree.search(linesCouple.second);

        Line *previousLine = this->Tree.prev(firstLineNode)->Key();
        Line *nextLine = this->Tree.next(secondLineNode)->Key();

        LineUtils lineUtils;
        Intersection *intersection = lineUtils.findIntersection(previousLine, nextLine);

        if (addIntersectionToList(intersection)) {
            /*** ADD TO QUEUE ***/
        }

        this->Tree.remove(linesCouple.first);
        this->Tree.remove(linesCouple.second);

        this->Tree.insert(linesCouple.second);
        this->Tree.insert(linesCouple.first);

    }
}

/** Adds an intersection to the list of intersections and return false if the intersection was
 * already there an true if it was not found before **/
bool Inters::SweepLine::addIntersectionToList(Intersection *intersection) {

    std::list<Intersection *>::iterator findIter = std::find(intersections.begin(), intersections.end(), intersection);

    if (findIter == intersections.end()) {
        intersections.push_back(intersection);
        return true;
    }

    return false;
}
