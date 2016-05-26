//
// Created by danilo on 12/05/16.
//

#ifndef INTERSCPP_AVLTREE_H
#define INTERSCPP_AVLTREE_H

#include "AVLNode.h"

/* AVL tree */
class AVLtree {

private:

    AvlNode<Inters::Line *> *root;
    double currentSweepPointX;

public:

    AVLtree() : root(NULL) { };

    ~AVLtree() { if (root) delete root; }

    // See if the tree is empty
    int IsEmpty() const {
        return (root == NULL);
    }

    template<class T>
    AvlNode<Inters::Line *> *insert(LineComparable *item);

    template<class T>
    LineComparable *remove(Inters::Line *key, cmp_t cmp = EQ_CMP);

    template<class T>
    AvlNode<Inters::Line *> *next(AvlNode<Inters::Line *> *node);

    template<class T>
    AvlNode<Inters::Line *> *prev(AvlNode<Inters::Line *> *node);

    template<class T>
    AvlNode<Inters::Line *> *search(Inters::Line *key, cmp_t cmp = EQ_CMP);

    template<class T>
    int check();

    void setCurrentSweepPointX(double currentSweepPointX) {
        this->currentSweepPointX = currentSweepPointX;
    }

};


#endif //INTERSCPP_AVLTREE_H
