#include "../../headers/Utils/AVLTree.h"

// Class AvlTree is a simple container object to "house" an AvlNode
// that represents the root-node of and AvlTree. Most of the member
// functions simply delegate to the root AvlNode.


// Search, Insert, Delete, and Check
template<class KeyType>
AvlNode<KeyType> *AVLtree<KeyType>::search(KeyType key, cmp_t cmp) {
    return AvlNode<KeyType>::Search(key, root, cmp);
}

template<class KeyType>
AvlNode<KeyType> *AVLtree<KeyType>::insert(LineComparable *item) {
    return AvlNode<KeyType>::Insert(item, root);
}

template<class KeyType>
LineComparable *AVLtree<KeyType>::remove(KeyType key, cmp_t cmp) {
    return AvlNode<KeyType>::Delete(key, root, cmp);
}

// As with all binary trees, a node's in-order successor is the
// left-most child of its right subtree, and a node's in-order predecessor
// is the right-most child of its left subtree.
template<class KeyType>
AvlNode<KeyType> *AVLtree<KeyType>::next(AvlNode<KeyType> *node) {
    AvlNode<KeyType> *q, *p = node->Subtree(AvlNode<KeyType>::RIGHT);
    if (p) {
        while (p->Subtree(AvlNode<KeyType>::LEFT)) p = p->Subtree(AvlNode<KeyType>::LEFT);
        return p;
    } else {
        // find parent, check if node is on left subtree
        q = node;
        p = node->Parent(root);
        while (p && (q == p->Subtree(AvlNode<KeyType>::RIGHT))) {
            q = p;
            p = p->Parent(root);
        }

        return p;
    }
}

template<class KeyType>
AvlNode<KeyType> *AVLtree<KeyType>::prev(AvlNode<KeyType> *node) {
    AvlNode<KeyType> *q, *p = node->Subtree(AvlNode<KeyType>::LEFT);
    if (p) {
        while (p->Subtree(AvlNode<KeyType>::RIGHT)) p = p->Subtree(AvlNode<KeyType>::RIGHT);
        return p;
    } else {
        // find parent, check if node is on left subtree
        q = node;
        p = node->Parent(root);
        while (p && (q == p->Subtree(AvlNode<KeyType>::LEFT))) {
            q = p;
            p = p->Parent(root);
        }

        return p;
    }
}

template<class KeyType>
int AVLtree<KeyType>::check() {
    return (root) ? root->Check() : 1;
}