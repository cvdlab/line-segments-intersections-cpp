//
// Created by danilo on 11/05/16.
//

#include "../../headers/Utils/Line.h"


friend bool operator<(const Inters::Line &l1, const Inters::Line &l2) {
    return l1.getV0() < l2.getV0();
}

friend bool operator>(const Inters::Line &l1, const Inters::Line &l2) {
    return l1.getV0() > l2.getV0();
}

friend bool operator==(const Inters::Line &l1, const Inters::Line &l2) {
    return l1.getV0() == l2.getV0();
}

friend bool operator<=(const Inters::Line &l1, const Inters::Line &l2) {
    return l1.getV0() <= l2.getV0();
}

friend bool operator>=(const Inters::Line &l1, const Inters::Line &l2) {
    return l1.getV0() >= l2.getV0();
}
