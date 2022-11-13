#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>
#include "BST.h"

BST::BST()
{
    this->root = nullptr;
}

BST::Node *BST::cons(int x)
{
    return new Node{nullptr, x, nullptr};
}

bool BST::isEmpty() const
{
    return (this->root == nullptr);
}

bool BST::serach(int x)
{
    return (search(x, this->root) != nullptr);
}

BST::Node *BST::insert(int x, Node *n)
{
    if (n == nullptr)
    {
        return cons(x);
    }

    if (x <= n->x)
    {
        n->left = insert(x, n->left);
    }
    else
    {
        n->right = insert(x, n->right);
    }

    return n;
}

void BST::insert(int x)
{

    this->root = insert(x, root);
}

void BST::randomGenerateTree(std::vector<int> vec)
{
    auto rng = std::default_random_engine{};
    shuffle(vec.begin(), vec.end(), rng);

    for (auto e : vec)
        this->insert(e);
}

int randNum(int min, int max)
{
    return rand() % (max - min) + max;
}

void BST::randomGenerateTree(int num, int min, int max)
{
    for (int i = 0; i < num; i++)
    {
        this->insert(randNum(min, max));
    }
}

BST::Node *BST::search(int x, Node *n)
{
    if (n == nullptr)
        return nullptr;

    if (x == n->x)
    {
        return n;
    }
    else if (x < n->x)
    {
        return search(x, n->left);
    }
    else
    {
        return search(x, n->right);
    }
}

BST::Node *BST::findParent(Node *n, Node *target)
{
    // target must exsit in tree. use search method first.
    int key = target->x;
    Node *child = n;
    Node *parent;

    if (child->x == key)
    {
        return nullptr; // there is no parent of target
    }

    while (child->x != key)
    {
        if (key < child->x)
        {
            parent = child;
            child = child->left;
        }
        else if (key > child->x)
        {
            parent = child;
            child = child->right;
        }
    }

    return parent;
}

void BST::transplant(Node *parent, Node *target, Node *newChild)
{
    if (parent == nullptr)
        this->root = newChild;

    else if (parent->left == target)
        parent->left = newChild;

    else
        parent->right = newChild;

    delete target;
}

bool BST::remove(int x)
{
    return remove(x, this->root);
}

bool BST::remove(int x, Node *n)
{
    // case 0: empty tree
    if (n == nullptr)
    {
        return false;
    }

    Node *target = search(x, n);
    if (target == nullptr)
        return false;

    Node *parent = findParent(n, target);

    // case 1: if left node is empty, target node is replaced by right node

    if (target->left == nullptr)
    {
        transplant(parent, target, target->right);
        return true;
    }

    // case 2: if right nod id empty, target node is replaced by left node

    else if (target->right == nullptr)
    {
        transplant(parent, target, target->left);
        return true;
    }

    // case 3: if target has both right and left node,s

    else
    {
        Node *newChild = target->right;
        if (newChild->left == nullptr)
        {
            transplant(parent, target, newChild);
        }
        else
        {
            while (newChild->left != nullptr)
            {
                newChild = newChild->left;
            }

            target->x = newChild->x;
            delete newChild;
            newChild = nullptr;
        }
        return true;
    }
}

void BST::inOrderWalk(std::ostream &out)
{
    inOrderWalk(out, this->root);
}

void BST::inOrderWalk(std::ostream &out, Node *n)
{
    if (n == nullptr)
        return;

    inOrderWalk(out, n->left);
    out << n->x << " ";
    inOrderWalk(out, n->right);
}

void BST::preOrderWalk(std::ostream &out)
{
    preOrderWalk(out, this->root);
}

void BST::preOrderWalk(std::ostream &out, Node *n)
{
    if (n == nullptr)
        return;

    out << n->x << " ";
    preOrderWalk(out, n->left);
    preOrderWalk(out, n->right);
}

void BST::postOrderWalk(std::ostream &out)
{
    postOrderWalk(out, this->root);
}

void BST::postOrderWalk(std::ostream &out, Node *n)
{
    if (n == nullptr)
        return;

    postOrderWalk(out, n->left);
    postOrderWalk(out, n->right);
    out << n->x << " ";
}

void BST::reverseOrderWalk(std::ostream &out)
{
    reverseOrderWalk(out, this->root);
}

void BST::reverseOrderWalk(std::ostream &out, Node *n)
{
    if (n == nullptr)
        return;

    inOrderWalk(out, n->right);
    out << n->x << " ";
    inOrderWalk(out, n->left);
}

int BST::maxDepth()
{
    return maxDepth(root, 0);
}

int BST::maxDepth(Node *n, int count)
{
    int left = (n->left != nullptr) ? maxDepth(n->left, count + 1) : count;
    int right = (n->right != nullptr) ? maxDepth(n->right, count + 1) : count;
    return std::max(left, right);
}

BST::Node *BST::copyTree(Node *n)
{
    if (n == nullptr)
    {
        return nullptr;
    }

    Node *newRoot = cons(n->x);

    newRoot->left = copyTree(n->left);
    newRoot->right = copyTree(n->right);

    return newRoot;
}

BST::BST(const BST &other)
{
    this->root = copyTree(other.root);
}

BST &BST::operator=(const BST &rhs)
{
    deleteTree(this->root);
    this->root = copyTree(rhs.root);

    return *this;
}

void BST::deleteTree(Node *n)
{
    if (n == nullptr)
        return;

    Node *discard = n;
    deleteTree(n->left);
    deleteTree(n->right);
    delete discard;
    discard = nullptr;
}

BST::~BST()
{
    deleteTree(this->root);
}
