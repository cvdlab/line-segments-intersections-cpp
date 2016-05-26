//
// Created by danilo on 12/05/16.
//

#ifndef INTERSCPP_AVLTREE_H
#define INTERSCPP_AVLTREE_H

#include "AVLNode.h"

/* AVL tree */
template<class KeyType>
class AVLtree {

private:

    AvlNode<KeyType> *root;
    double currentSweepPointX;

    AvlNode<KeyType> *rotateLeft(AvlNode<KeyType> *a);

    AvlNode<KeyType> *rotateRight(AvlNode<KeyType> *a);

    AvlNode<KeyType> *rotateLeftThenRight(AvlNode<KeyType> *n);

    AvlNode<KeyType> *rotateRightThenLeft(AvlNode<KeyType> *n);

    void rebalance(AvlNode<KeyType> *n);

    int height(AvlNode<KeyType> *n);

    void setBalance(AvlNode<KeyType> *n);

public:

    AVLtree(void);

    ~AVLtree(void);

    // See if the tree is empty
    int IsEmpty() const {
        return (root == NULL);
    }


    AvlNode<KeyType> *insert(LineComparable *item);

    LineComparable *remove(KeyType key, cmp_t cmp = EQ_CMP);


    AvlNode<KeyType> *next(AvlNode<KeyType> *node);

    AvlNode<KeyType> *prev(AvlNode<KeyType> *node);

    AvlNode<KeyType> *search(KeyType key, cmp_t cmp = EQ_CMP);

    int check();

    void setCurrentSweepPointX(double currentSweepPointX) {
        this->currentSweepPointX = currentSweepPointX;
    }

};


#endif //INTERSCPP_AVLTREE_H
