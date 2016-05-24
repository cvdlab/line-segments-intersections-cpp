//
// Created by danilo on 12/05/16.
//

#include "../../headers/Utils/Event.h"

/** Define an operator for events **/

bool operator<(const Inters::Event &e1) {

    if (this->getPoint()->getX() == e1.getPoint()->getX()) {
        return this->getPoint()->getY() < e1.getPoint()->getY();
    }

    return this->getPoint()->getX() < e1.getPoint()->getX();
};

bool operator>(const Inters::Event &e1) {
    if (this->getPoint()->getX() == e1.getPoint()->getX()) {
        return this->getPoint()->getY() > e1.getPoint()->getY();
    }

    return this->getPoint()->getX() > e1.getPoint()->getX();

}

bool operator==(const Inters::Event &e1) {
    return this->getPoint() == e1.getPoint();
}

bool operator<=(const Inters::Event &e1) {
    if (this->getPoint()->getX() == e1.getPoint()->getX()) {
        return this->getPoint()->getY() <= e1.getPoint()->getY();
    }

    return this->getPoint()->getX() < e1.getPoint()->getX();

}

bool operator>=(const Inters::Event &e1) {
    if (this->getPoint()->getX() == e1.getPoint()->getX()) {
        return this->getPoint()->getY() >= e1.getPoint()->getY();
    }

    return this->getPoint()->getX() > e1.getPoint()->getX();
}
