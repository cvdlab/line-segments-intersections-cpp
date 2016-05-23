#include "../../headers/Utils/AVLNode.h"

template<class KeyType>
AvlNode<KeyType>::AvlNode(Comparable<KeyType> *item)
        : myData(item), myBal(0) {
    Reset();
}

template<class KeyType>
AvlNode<KeyType>::~AvlNode(void) {
    if (mySubtree[LEFT]) delete mySubtree[LEFT];
    if (mySubtree[RIGHT]) delete mySubtree[RIGHT];
}

// ------------------------------------------------- Rotating and Re-Balancing

template<class KeyType>
int AvlNode<KeyType>::RotateOnce(AvlNode<KeyType> *&root, dir_t dir) {
    dir_t otherDir = Opposite(dir);
    AvlNode<KeyType> *oldRoot = root;

    // See if otherDir subtree is balanced. If it is, then this
    // rotation will *not* change the overall tree height.
    // Otherwise, this rotation will shorten the tree height.
    int heightChange = (root->mySubtree[otherDir]->myBal == 0)
                       ? HEIGHT_NOCHANGE
                       : HEIGHT_CHANGE;

    // assign new root
    root = oldRoot->mySubtree[otherDir];

    // new-root exchanges it's "dir" mySubtree for it's parent
    oldRoot->mySubtree[otherDir] = root->mySubtree[dir];
    root->mySubtree[dir] = oldRoot;

    // update balances
    oldRoot->myBal = -((dir == LEFT) ? --(root->myBal) : ++(root->myBal));

    return heightChange;
}

template<class KeyType>
int AvlNode<KeyType>::RotateTwice(AvlNode<KeyType> *&root, dir_t dir) {
    dir_t otherDir = Opposite(dir);
    AvlNode<KeyType> *oldRoot = root;
    AvlNode<KeyType> *oldOtherDirSubtree = root->mySubtree[otherDir];

    // assign new root
    root = oldRoot->mySubtree[otherDir]->mySubtree[dir];

    // new-root exchanges it's "dir" mySubtree for it's grandparent
    oldRoot->mySubtree[otherDir] = root->mySubtree[dir];
    root->mySubtree[dir] = oldRoot;

    // new-root exchanges it's "other-dir" mySubtree for it's parent
    oldOtherDirSubtree->mySubtree[dir] = root->mySubtree[otherDir];
    root->mySubtree[otherDir] = oldOtherDirSubtree;

    // update balances
    root->mySubtree[LEFT]->myBal = -max(root->myBal, 0);
    root->mySubtree[RIGHT]->myBal = -min(root->myBal, 0);
    root->myBal = 0;

    // A double rotation always shortens the overall height of the tree
    return HEIGHT_CHANGE;
}

template<class KeyType>
int AvlNode<KeyType>::ReBalance(AvlNode<KeyType> *&root) {
    int heightChange = HEIGHT_NOCHANGE;

    if (LEFT_IMBALANCE(root->myBal)) {
        // Need a rights rotation
        if (root->mySubtree[LEFT]->myBal == RIGHT_HEAVY) {
            // RL rotation needed
            heightChange = RotateTwice(root, RIGHT);
        } else {
            // RR rotation needed
            heightChange = RotateOnce(root, RIGHT);
        }
    } else if (RIGHT_IMBALANCE(root->myBal)) {
        // Need a lefts rotation
        if (root->mySubtree[RIGHT]->myBal == LEFT_HEAVY) {
            // LR rotation needed
            heightChange = RotateTwice(root, LEFT);
        } else {
            // LL rotation needed
            heightChange = RotateOnce(root, LEFT);
        }
    }

    return heightChange;
}

// ------------------------------------------------------- Comparisons

template<class KeyType>
cmp_t AvlNode<KeyType>::Compare(KeyType key, cmp_t cmp) const {
    switch (cmp) {
        default:
        case EQ_CMP :  // Standard comparison
            return myData->Compare(key);

        case MIN_CMP :  // Find the minimal element in this tree
            return (mySubtree[LEFT] == NULL) ? EQ_CMP : MIN_CMP;

        case MAX_CMP :  // Find the maximal element in this tree
            return (mySubtree[RIGHT] == NULL) ? EQ_CMP : MAX_CMP;
    }
}

template<class KeyType>
AvlNode<KeyType> *AvlNode<KeyType>::Parent(AvlNode<KeyType> *myRoot) {
    if (this == myRoot) return 0;

    AvlNode<KeyType> *p = myRoot;
    while (p) {
        if (this == p->Subtree(AvlNode<KeyType>::LEFT)) return p;
        if (this == p->Subtree(AvlNode<KeyType>::RIGHT)) return p;

        cmp_t result = p->Compare(this->Key());
        if (result == MIN_CMP)
            p = p->Subtree(AvlNode<KeyType>::LEFT);
        else
            p = p->Subtree(AvlNode<KeyType>::RIGHT);
    }

    return 0;
}

// ------------------------------------------------------- Search/Insert/Delete

template<class KeyType>
AvlNode<KeyType> *AvlNode<KeyType>::Search(KeyType key, AvlNode<KeyType> *root, cmp_t cmp) {
    cmp_t result;
    while (root && (result = root->Compare(key, cmp))) {
        root = root->mySubtree[(result < 0) ? LEFT : RIGHT];
    }
    return (root) ? root : NULL;
}

template<class KeyType>
AvlNode<KeyType> *AvlNode<KeyType>::Insert(Comparable<KeyType> *item,
                                           AvlNode<KeyType> *&root) {
    int change;
    return Insert(item, root, change);
}

template<class KeyType>
Comparable<KeyType> *AvlNode<KeyType>::Delete(KeyType key, AvlNode<KeyType> *&root, cmp_t cmp) {
    int change;
    return Delete(key, root, change, cmp);
}


template<class KeyType>
AvlNode<KeyType> *AvlNode<KeyType>::Insert(Comparable<KeyType> *item,
                                           AvlNode<KeyType> *&root,
                                           int &change) {
    // See if the tree is empty
    if (root == NULL) {
        // Insert new node here
        root = new AvlNode<KeyType>(item);
        change = HEIGHT_CHANGE;
        return root;
    }

    // Initialize
    AvlNode<KeyType> *found = NULL;
    int increase = 0;

    // Compare items and determine which direction to search
    cmp_t result = root->Compare(item->Key());
    dir_t dir = (result == MIN_CMP) ? LEFT : RIGHT;

    if (result != EQ_CMP) {
        // Insert into "dir" subtree
        found = Insert(item, root->mySubtree[dir], change);
        if (!found) return NULL;     // already here - don't insert
        increase = result * change;  // set balance factor increment
    } else {   // key already in tree at this node
        increase = HEIGHT_NOCHANGE;
        return NULL;
    }

    root->myBal += increase;    // update balance factor

    // ----------------------------------------------------------------------
    // re-balance if needed -- height of current tree increases only if its
    // subtree height increases and the current tree needs no rotation.
    // ----------------------------------------------------------------------

    change = (increase && root->myBal)
             ? (1 - ReBalance(root))
             : HEIGHT_NOCHANGE;
    return found;
}


template<class KeyType>
Comparable<KeyType> *AvlNode<KeyType>::Delete(KeyType key,
                                              AvlNode<KeyType> *&root,
                                              int &change,
                                              cmp_t cmp) {
    // See if the tree is empty
    if (root == NULL) {
        // Key not found
        change = HEIGHT_NOCHANGE;
        return NULL;
    }

    // Initialize
    Comparable<KeyType> *found = NULL;
    int decrease = 0;

    // Compare items and determine which direction to search
    cmp_t result = root->Compare(key, cmp);
    dir_t dir = (result == MIN_CMP) ? LEFT : RIGHT;

    if (result != EQ_CMP) {
        // Delete from "dir" subtree
        found = Delete(key, root->mySubtree[dir], change, cmp);
        if (!found) return found;   // not found - can't delete
        decrease = result * change;    // set balance factor decrement
    } else {   // Found key at this node
        found = root->myData;  // set return value

        // ---------------------------------------------------------------------
        // At this point we know "result" is zero and "root" points to
        // the node that we need to delete.  There are three cases:
        //
        //    1) The node is a leaf.  Remove it and return.
        //
        //    2) The node is a branch (has only 1 child). Make "root"
        //       (the pointer to this node) point to the child.
        //
        //    3) The node has two children. We swap items with the successor
        //       of "root" (the smallest item in its rights subtree) and delete
        //       the successor from the rights subtree of "root".  The
        //       identifier "decrease" should be reset if the subtree height
        //       decreased due to the deletion of the successor of "root".
        // ---------------------------------------------------------------------

        if ((root->mySubtree[LEFT] == NULL) &&
            (root->mySubtree[RIGHT] == NULL)) {
            // We have a leaf -- remove it
            delete root;
            root = NULL;
            change = HEIGHT_CHANGE;    // height changed from 1 to 0
            return found;
        } else if ((root->mySubtree[LEFT] == NULL) ||
                   (root->mySubtree[RIGHT] == NULL)) {
            // We have one child -- only child becomes new root
            AvlNode<KeyType> *toDelete = root;
            root = root->mySubtree[(root->mySubtree[RIGHT]) ? RIGHT : LEFT];
            change = HEIGHT_CHANGE;    // We just shortened the subtree
            // Null-out the subtree pointers so we dont recursively delete
            toDelete->mySubtree[LEFT] = toDelete->mySubtree[RIGHT] = NULL;
            delete toDelete;
            return found;
        } else {
            // We have two children -- find successor and replace our current
            // data item with that of the successor
            root->myData = Delete(key, root->mySubtree[RIGHT],
                                  decrease, MIN_CMP);
        }
    }

    root->myBal -= decrease;       // update balance factor

    // ------------------------------------------------------------------------
    // Rebalance if necessary -- the height of current tree changes if one
    // of two things happens: (1) a rotation was performed which changed
    // the height of the subtree (2) the subtree height decreased and now
    // matches the height of its other subtree (so the current tree now
    // has a zero balance when it previously did not).
    // ------------------------------------------------------------------------
    //change = (decrease) ? ((root->myBal) ? balance(root) : HEIGHT_CHANGE)
    //                    : HEIGHT_NOCHANGE ;
    if (decrease) {
        if (root->myBal) {
            change = ReBalance(root);  // rebalance and see if height changed
        } else {
            change = HEIGHT_CHANGE;   // balanced because subtree decreased
        }
    } else {
        change = HEIGHT_NOCHANGE;
    }

    return found;
}

// --------------------------------------------------------------- Verification

template<class KeyType>
int
AvlNode<KeyType>::Height() const {
    int leftHeight = (mySubtree[LEFT]) ? mySubtree[LEFT]->Height() : 0;
    int rightHeight = (mySubtree[RIGHT]) ? mySubtree[RIGHT]->Height() : 0;
    return (1 + max(leftHeight, rightHeight));
}

template<class KeyType>
int
AvlNode<KeyType>::Check() const {
    int valid = 1;

    // First verify that subtrees are correct
    if (mySubtree[LEFT]) valid *= mySubtree[LEFT]->Check();
    if (mySubtree[RIGHT]) valid *= mySubtree[RIGHT]->Check();

    // Now get the height of each subtree
    int leftHeight = (mySubtree[LEFT]) ? mySubtree[LEFT]->Height() : 0;
    int rightHeight = (mySubtree[RIGHT]) ? mySubtree[RIGHT]->Height() : 0;

    // Verify that AVL tree property is satisfied
    int diffHeight = rightHeight - leftHeight;
    if (LEFT_IMBALANCE(diffHeight) || RIGHT_IMBALANCE(diffHeight)) {
        valid = 0;
        cerr << "Height difference is " << diffHeight
        << " at node " << Key() << endl;
    }

    // Verify that balance-factor is correct
    if (diffHeight != myBal) {
        valid = 0;
        cerr << "Height difference " << diffHeight
        << " doesn't match balance-factor of " << myBal
        << " at node " << Key() << endl;
    }

    // Verify that search-tree property is satisfied
    if ((mySubtree[LEFT])
        &&
        (mySubtree[LEFT]->Compare(Key()) == MIN_CMP)) {
        valid = 0;
        cerr << "Node " << Key() << " is *smaller* than lefts subtree"
        << mySubtree[LEFT]->Key() << endl;
    }
    if ((mySubtree[RIGHT])
        &&
        (mySubtree[RIGHT]->Compare(Key()) == MAX_CMP)) {
        valid = 0;
        cerr << "Node " << Key() << " is *greater* than rights subtree"
        << mySubtree[RIGHT]->Key() << endl;
    }

    return valid;
}