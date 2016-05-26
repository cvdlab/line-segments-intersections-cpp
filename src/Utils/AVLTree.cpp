#include "../../headers/Utils/AVLTree.h"

// Class AvlTree is a simple container object to "house" an AvlNode
// that represents the root-node of and AvlTree. Most of the member
// functions simply delegate to the root AvlNode.

// Search, Insert, Delete, and Check
template<class T>
AvlNode<Inters::Line *> *AVLtree::search(Inters::Line *key, cmp_t cmp) {
    return AvlNode<Inters::Line *>::Search(key, root, cmp);
}

template<class T>
AvlNode<Inters::Line *> *AVLtree::insert(LineComparable *item) {
    return AvlNode<Inters::Line *>::Insert(item, root);
}

template<class T>
LineComparable *AVLtree::remove(Inters::Line *key, cmp_t cmp) {
    return AvlNode<Inters::Line *>::Delete(key, root, cmp);
}

// As with all binary trees, a node's in-order successor is the
// left-most child of its right subtree, and a node's in-order predecessor
// is the right-most child of its left subtree.
template<class T>
AvlNode<Inters::Line *> *AVLtree::next(AvlNode<Inters::Line *> *node) {
    AvlNode<Inters::Line *> *q, *p = node->Subtree(AvlNode<Inters::Line *>::RIGHT);
    if (p) {
        while (p->Subtree(AvlNode<Inters::Line *>::LEFT)) p = p->Subtree(AvlNode<Inters::Line *>::LEFT);
        return p;
    } else {
        // find parent, check if node is on left subtree
        q = node;
        p = node->Parent(root);
        while (p && (q == p->Subtree(AvlNode<Inters::Line *>::RIGHT))) {
            q = p;
            p = p->Parent(root);
        }

        return p;
    }
}

template<class T>
AvlNode<Inters::Line *> *AVLtree::prev(AvlNode<Inters::Line *> *node) {
    AvlNode<Inters::Line *> *q, *p = node->Subtree(AvlNode<Inters::Line *>::LEFT);
    if (p) {
        while (p->Subtree(AvlNode<Inters::Line *>::RIGHT)) p = p->Subtree(AvlNode<Inters::Line *>::RIGHT);
        return p;
    } else {
        // find parent, check if node is on left subtree
        q = node;
        p = node->Parent(root);
        while (p && (q == p->Subtree(AvlNode<Inters::Line *>::LEFT))) {
            q = p;
            p = p->Parent(root);
        }

        return p;
    }
}

template<class T>
int AVLtree::check() {
    return (root) ? root->Check() : 1;
}