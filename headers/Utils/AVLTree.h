//
// Created by danilo on 12/05/16.
//

#ifndef INTERSCPP_AVLTREE_H
#define INTERSCPP_AVLTREE_H

#include "AVLNode.h"

/* AVL tree */
class AVLTree {

private:

    AvlNode<Inters::Line *> *root;
    double currentSweepPointX;

public:

    AVLTree() : root(NULL) { };

    ~AVLTree() { if (root) delete root; }

    // See if the tree is empty
    int IsEmpty() const {
        return (root == NULL);
    }

    AvlNode<Inters::Line *> *insert(LineComparable *item);

    LineComparable *remove(Inters::Line *key, cmp_t cmp = EQ_CMP);

    AvlNode<Inters::Line *> *next(AvlNode<Inters::Line *> *node);

    AvlNode<Inters::Line *> *prev(AvlNode<Inters::Line *> *node);

    AvlNode<Inters::Line *> *search(Inters::Line *key, cmp_t cmp = EQ_CMP);

    int check();

    void setCurrentSweepPointX(double currentSweepPointX) {
        this->currentSweepPointX = currentSweepPointX;
    }

};


#endif //INTERSCPP_AVLTREE_H
