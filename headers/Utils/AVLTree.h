//
// Created by danilo on 12/05/16.
//

#ifndef INTERSCPP_AVLTREE_H
#define INTERSCPP_AVLTREE_H

#include "AVLNode.h"

/* AVL tree */
class AVLTree {

private:

    AvlNode *root;
    double currentSweepPointX;

public:

    AVLTree() : root(NULL) { };

    ~AVLTree() { if (root) delete root; }

    // See if the tree is empty
    int IsEmpty() const {
        return (root == NULL);
    }

    AvlNode *insert(LineComparable *item);

    LineComparable *remove(Inters::Line *key, cmp_t cmp = EQ_CMP);

    AvlNode *next(AvlNode *node);

    AvlNode *prev(AvlNode *node);

    AvlNode *search(Inters::Line *key, cmp_t cmp = EQ_CMP);

    int check();

    void setCurrentSweepPointX(double currentSweepPointX) {
        this->currentSweepPointX = currentSweepPointX;
    }

};


#endif //INTERSCPP_AVLTREE_H
