#include "../../headers/Utils/LineComparable.h"


// Compare this item against the given key & return the result
cmp_t LineComparable::Compare(Inters::Line *line, double sweepLine) {

    /* Compute the intersection between the sweepline and the two lines and
     * compare the two lines*/
    Inters::LineUtils lineUtils;

    Inters::Line *myLine = Key();

    Inters::Point *intersMyLine = lineUtils.findVerticalIntersection(myLine, sweepLine);

    return (line->getV0()->getY() == intersMyLine->getY()) ? EQ_CMP
                                                           : ((line->getV0()->getY() < intersMyLine->getY())
                                                              ? MIN_CMP : MAX_CMP);

}



