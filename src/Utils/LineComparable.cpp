#include <cstddef>
#include "../../headers/Utils/Comparable.h"
#include "../../headers/Utils/Line.h"

class LineComparable : public Comparable {

public:
    LineComparable(Inters::Line line) : Comparable<Inters::Line>(line) { };

    //virtual ~LineComparable() { };

    // Compare this item against the given key & return the result
    cmp_t Compare(Inters::Line line, double sweepLine = NULL) const {

        if (sweepLine != NULL) {
            /* Compute the intersection between the sweepline and the two lines and
             * compare the two lines*/
            Inters::LineUtils lineUtils;

            Inters::Line myLine = Key();
            Inters::Point *intersMyLine = lineUtils.findVerticalIntersection(myLine, sweepLine);

            return (line.getV0()->getY() == intersMyLine->getY()) ? EQ_CMP
                                                                  : ((line.getV0()->getY() < intersMyLine->getY())
                                                                     ? MIN_CMP : MAX_CMP);
        }

        return (line == Key()) ? EQ_CMP
                               : ((line < Key())
                                  ? MIN_CMP : MAX_CMP);
    }


};
