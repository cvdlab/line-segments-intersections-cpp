//
// Created by danilo on 09/05/16.
//

#include "../headers/SweepLine.h"
#include "../headers/Utils/LineUtils.h"

void Inters::SweepLine::add(Event *E) {


//    double sweepLinePointX = E->getPoint()->getX();
//    this->Tree.setCurrentSweepPointX(sweepLinePointX);
//
//    /* Now I have to add all segments in lefts list */
//
//    std::list<Line> left = E->getLefts();
//
//    std::list<Line>::const_iterator iterator;
//    for (iterator = left.begin(); iterator != left.end(); ++iterator) {
//        AvlNode<Line> *insertedLine = this->Tree.insert(*iterator);
//
//        /* Now I can check for intersections */
//        Line previousLine = this->Tree.prev(insertedLine)->Key();
//        Line nextLine = this->Tree.next(insertedLine)->Key();
//        Line currentLine = insertedLine->Key();
//        LineUtils lineUtils;
//        Point *intersectionPrev = lineUtils.findIntersection(&previousLine, &currentLine);
//        Point *intersectionNext = lineUtils.findIntersection(&nextLine, &currentLine);
//
//        if (addIntersectionToList(intersectionPrev, &previousLine, &currentLine)) {
//            /*** ADD TO QUEUE ***/
//        }
//
//        if (addIntersectionToList(intersectionNext, &currentLine, &nextLine)) {
//            /*** ADD TO QUEUE ***/
//        }
//
//
//    }
}

void Inters::SweepLine::remove(Event *E) {

//    double sweepLinePointX = E->getPoint()->getX();
//    this->Tree.setCurrentSweepPointX(sweepLinePointX);
//
//    /* Now I have to remove all segments in rights list */
//
//    std::list<Line> right = E->getRights();
//
//    std::list<Line>::const_iterator iterator;
//    for (iterator = right.begin(); iterator != right.end(); ++iterator) {
//        AvlNode<Line> *removedLine = this->Tree.remove(*iterator);
//
//        /* Now I can check for intersections */
//        Line previousLine = this->Tree.prev(removedLine)->Key();
//        Line nextLine = this->Tree.next(removedLine)->Key();
//        Line currentLine = removedLine->Key();
//        LineUtils lineUtils;
//        Point *intersection = lineUtils.findIntersection(&previousLine, &nextLine);
//
//        if (addIntersectionToList(intersection, &previousLine, &nextLine)) {
//            /*** ADD TO QUEUE ***/
//        }
//    }
}

void Inters::SweepLine::swapLines(Event *E) {
//    std::list<pair<Line *, Line *> > intersections = E->getIntersections();
//
//    std::list<pair<Line *, Line *> >::const_iterator iterator;
//    for (iterator = intersections.begin(); iterator != intersections.end(); ++iterator) {
//        pair<Line *, Line *> linesCouple = *iterator;
//        AvlNode<Line> *firstLineNode = this->Tree.search(*linesCouple.first);
//        AvlNode<Line> *secondLineNode = this->Tree.search(*linesCouple.second);
//
//        Line previousLine = this->Tree.prev(firstLineNode)->Key();
//        Line nextLine = this->Tree.next(secondLineNode)->Key();
//
//        LineUtils lineUtils;
//        Point *intersection = lineUtils.findIntersection(&previousLine, &nextLine);
//
//        if (addIntersectionToList(intersection, &previousLine, &nextLine)) {
//            /*** ADD TO QUEUE ***/
//        }
//
//        this->Tree.remove(*linesCouple.first);
//        this->Tree.remove(*linesCouple.second);
//
//        this->Tree.insert(*linesCouple.second);
//        this->Tree.insert(*linesCouple.first);
//
//    }

}