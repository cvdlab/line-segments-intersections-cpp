//
// Created by danilo on 12/05/16.
//

#ifndef INTERSCPP_AVLTREE_H
#define INTERSCPP_AVLTREE_H

#include "AVLNode.h"

/* AVL tree */
template<class T>
class AVLtree {
public:


    AVLtree(void);

    ~AVLtree(void);

    AvlNode<T> *insert(T key);

    AvlNode<T> *remove(T key);


    AvlNode<T> *next(AvlNode<T> *node);

    AvlNode<T> *prev(AvlNode<T> *node);

    AvlNode<T> *search(T key);

    void setCurrentSweepPointX(double currentSweepPointX) {
        this->currentSweepPointX = currentSweepPointX;
    }

private:

    double currentSweepPointX;


    AvlNode<T> *root;

    AvlNode<T> *rotateLeft(AvlNode<T> *a);

    AvlNode<T> *rotateRight(AvlNode<T> *a);

    AvlNode<T> *rotateLeftThenRight(AvlNode<T> *n);

    AvlNode<T> *rotateRightThenLeft(AvlNode<T> *n);

    void rebalance(AvlNode<T> *n);

    int height(AvlNode<T> *n);

    void setBalance(AvlNode<T> *n);
};


#endif //INTERSCPP_AVLTREE_H
