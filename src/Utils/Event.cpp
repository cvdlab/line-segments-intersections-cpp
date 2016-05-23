//
// Created by danilo on 12/05/16.
//

#include "../../headers/Utils/Event.h"

/** Define an operator for events **/

bool operator<(const Inters::Event &e1, const Inters::Event &e2) {

    return e1.getPoint() < e2.getPoint();
};

bool operator>(const Inters::Event &e1, const Inters::Event &e2) {
    return e1.getPoint() > e2.getPoint();
}

bool operator==(const Inters::Event &e1, const Inters::Event &e2) {
    return e1.getPoint() == e2.getPoint();
}

bool operator<=(const Inters::Event &e1, const Inters::Event &e2) {
    return e1.getPoint() <= e2.getPoint();
}

bool operator>=(const Inters::Event &e1, const Inters::Event &e2) {
    return e1.getPoint() <= e2.getPoint();
}
