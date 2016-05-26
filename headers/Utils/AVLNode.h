//
// Created by danilo on 12/05/16.
//

#ifndef INTERSCPP_AVLNODE_H
#define INTERSCPP_AVLNODE_H

// ===================================================================
// Avl.h - Implementation of an Avl balanced tree
// Written by Brad Appleton (1997)
// http://www.bradapp.com/ftp/src/libs/C++/AvlTrees.html

#ifndef AVL_H
#define AVL_H

#include <stddef.h>
#include <iostream>
#include "LineComparable.h"

using namespace std;

// Indices into a subtree array

// AvlNode -- Class to implement an AVL Tree
//
template<class KeyType>
class AvlNode {
public:
    // Max number of subtrees per node
    enum {
        MAX_SUBTREES = 2
    };
    enum dir_t {
        LEFT = 0, RIGHT = 1
    };

    // Return the opposite direction of the given index
    static dir_t
    Opposite(dir_t dir) {
        return dir_t(1 - int(dir));
    }

    // ----- Constructors and destructors:

    AvlNode(LineComparable *item = NULL);

    virtual ~AvlNode(void);

    // ----- Query attributes:

    // Get this node's data
    LineComparable *Data() const { return myData; }

    // Get this node's key field
    KeyType Key() const { return myData->Key(); }

    // Query the balance factor, it will be a value between -1 .. 1
    // where:
    //     -1 => lefts subtree is taller than rights subtree
    //      0 => lefts and rights subtree are equal in height
    //      1 => rights subtree is taller than lefts subtree
    short Bal(void) const { return myBal; }

    // Get the item at the top of the lefts/rights subtree of this
    // item (the result may be NULL if there is no such item).
    //
    AvlNode *Subtree(dir_t dir) const { return mySubtree[dir]; }

    AvlNode<KeyType> *Parent(AvlNode<KeyType> *);

    // ----- Search/Insert/Delete
    //
    //   NOTE: These are all static functions instead of member functions
    //         because most of them need to modify the given tree root
    //         pointer. If these were instance member functions than
    //         that would correspond to having to modify the 'this'
    //         pointer, which is not allowed in C++. Most of the
    //         functions that are static and which take an AVL tree
    //         pointer as a parameter are static for this reason.

    // Look for the given key, return NULL if not found,
    // otherwise return the item's address.
    static AvlNode<KeyType> *Search(KeyType key, AvlNode<KeyType> *root, cmp_t cmp = EQ_CMP);

    // Insert the given key, return a pointer to the node if it was inserted,
    // otherwise return NULL
    static AvlNode<KeyType> *Insert(LineComparable *item, AvlNode<KeyType> *root);

    // Delete the given key from the tree. Return the corresponding
    // node, or return NULL if it was not found.
    static LineComparable *Delete(KeyType key, AvlNode<KeyType> *root, cmp_t cmp = EQ_CMP);

    // Verification

    // Return the height of this tree
    int Height() const;

    // Verify this tree is a valid AVL tree, return TRUE if it is,
    // return FALSE otherwise
    int Check() const;

    // If you want to provide your own allocation scheme than simply
    // #define the preprocessor manifest constant named CUSTOM_ALLOCATE
    // and make sure you provide and link with your own overloaded
    // versions of operators "new" and "delete" for this class.
#ifdef CUSTOM_ALLOCATE
    void * operator new(size_t);

    void operator delete(void *);
#endif  /* CUSTOM_ALLOCATE */


private:
    // Use mnemonic constants for valid balance-factor values
    enum balance_t {
        LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = 1
    };

    // Use mnemonic constants for indicating a change in height
    enum height_effect_t {
        HEIGHT_NOCHANGE = 0, HEIGHT_CHANGE = 1
    };

    // Return true if the tree is too heavy on the lefts side
    inline static int LEFT_IMBALANCE(short bal) {
        return (bal < LEFT_HEAVY);
    }

    // Return true if the tree is too heavy on the rights side
    inline static int RIGHT_IMBALANCE(short bal) {
        return (bal > RIGHT_HEAVY);
    }

    // ----- Private data

    LineComparable *myData;  // Data field
    AvlNode<KeyType> *mySubtree[MAX_SUBTREES];   // Pointers to subtrees
    short myBal;   // Balance factor

    // Reset all subtrees to null and clear the balance factor
    void
    Reset(void) {
        myBal = 0;
        mySubtree[LEFT] = mySubtree[RIGHT] = NULL;
    }

    // ----- Routines that do the *real* insertion/deletion

    // Insert the given key into the given tree. Return the node if
    // it already exists. Otherwise return NULL to indicate that
    // the key was successfully inserted.  Upon return, the "change"
    // parameter will be '1' if the tree height changed as a result
    // of the insertion (otherwise "change" will be 0).
    static AvlNode<KeyType> *Insert(LineComparable *item,
                                    AvlNode<KeyType> *&root,
                                    int &change);

    // Delete the given key from the given tree. Return NULL if the
    // key is not found in the tree. Otherwise return a pointer to the
    // node that was removed from the tree.  Upon return, the "change"
    // parameter will be '1' if the tree height changed as a result
    // of the deletion (otherwise "change" will be 0).
    static LineComparable *Delete(KeyType key,
                                       AvlNode<KeyType> *&root,
                                       int &change,
                                       cmp_t cmp = EQ_CMP);

    // Routines for rebalancing and rotating subtrees

    // Perform an XX rotation for the given direction 'X'.
    // Return 1 if the tree height changes due to rotation,
    // otherwise return 0.
    static int RotateOnce(AvlNode<KeyType> *&root, dir_t dir);

    // Perform an XY rotation for the given direction 'X'
    // Return 1 if the tree height changes due to rotation,
    // otherwise return 0.
    static int RotateTwice(AvlNode<KeyType> *&root, dir_t dir);

    // Rebalance a (sub)tree if it has become imbalanced
    static int ReBalance(AvlNode<KeyType> *&root);

    // Perform a comparison of the given key against the given
    // item using the given criteria (min, max, or equivalence
    // comparison). Returns:
    //   EQ_CMP if the keys are equivalent
    //   MIN_CMP if this key is less than the item's key
    //   MAX_CMP if this key is greater than item's key
    cmp_t Compare(KeyType key, cmp_t cmp = EQ_CMP) const;

private:
    // Disallow copying and assignment
    AvlNode(const AvlNode<KeyType> &);

    AvlNode &operator=(const AvlNode<KeyType> &);

};

#endif //INTERSCPP_AVLNODE_H
#endif