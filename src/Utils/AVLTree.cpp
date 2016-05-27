#include "../../headers/Utils/AVLTree.h"

// Class AvlTree is a simple container object to "house" an AvlNode
// that represents the root-node of and AvlTree. Most of the member
// functions simply delegate to the root AvlNode.

// Search, Insert, Delete, and Check
AvlNode *AVLTree::search(Inters::Line *key, cmp_t cmp) {
    return AvlNode::Search(key, root, currentSweepPointX, cmp);
}


AvlNode *AVLTree::insert(Inters::Line *item) {
    LineComparable *lineComparable = new LineComparable(item);
    return AvlNode::Insert(lineComparable, root, currentSweepPointX);
}

LineComparable *AVLTree::remove(Inters::Line *key, cmp_t cmp) {
    return AvlNode::Delete(key, root, currentSweepPointX, cmp);
}

// As with all binary trees, a node's in-order successor is the
// left-most child of its right subtree, and a node's in-order predecessor
// is the right-most child of its left subtree.
AvlNode *AVLTree::next(AvlNode *node) {
    AvlNode *q, *p = node->Subtree(AvlNode::RIGHT);
    if (p) {
        while (p->Subtree(AvlNode::LEFT)) p = p->Subtree(AvlNode::LEFT);
        return p;
    } else {
        // find parent, check if node is on left subtree
        q = node;
        p = node->Parent(root, currentSweepPointX);
        while (p && (q == p->Subtree(AvlNode::RIGHT))) {
            q = p;
            p = p->Parent(root, currentSweepPointX);
        }

        return p;
    }
}

AvlNode *AVLTree::prev(AvlNode *node) {
    AvlNode *q, *p = node->Subtree(AvlNode::LEFT);
    if (p) {
        while (p->Subtree(AvlNode::RIGHT)) p = p->Subtree(AvlNode::RIGHT);
        return p;
    } else {
        // find parent, check if node is on left subtree
        q = node;
        p = node->Parent(root, currentSweepPointX);
        while (p && (q == p->Subtree(AvlNode::LEFT))) {
            q = p;
            p = p->Parent(root, currentSweepPointX);
        }

        return p;
    }
}

int AVLTree::check() {
    return (root) ? root->Check(currentSweepPointX) : 1;
}