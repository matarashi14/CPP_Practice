
#include <iostream>
#ifndef BST_H
#define BST_H

class BST
{
public:
    BST();
    bool isEmpty() const;
    void insert(int x);
    bool remove(int x);
    void randomGenerateTree(std::vector<int> vec);
    void randomGenerateTree(int numOfLeaf, int min, int max);
    bool serach(int x);

    void preOrderWalk(std::ostream &out);
    void postOrderWalk(std::ostream &out);
    void reverseOrderWalk(std::ostream &out);
    void inOrderWalk(std::ostream &out);

    int maxDepth();

    friend bool operator==(const BST &lfSide, const BST &rtSide);
    friend bool operator!=(const BST &lfSide, const BST &rtSide);

    // constructor
    BST(const BST &);
    // assignment operator
    BST &operator=(const BST &);
    // destructor
    ~BST();

private:
    struct Node
    {
        Node *left;
        int x;
        Node *right;
    };
    static Node *copyTree(Node *root);
    static Node *search(int x, Node *root);
    static Node *findParent(Node *root, Node *target);
    static void inOrderWalk(std::ostream &out, Node *root);
    static void preOrderWalk(std::ostream &out, Node *root);
    static void postOrderWalk(std::ostream &out, Node *root);
    static void reverseOrderWalk(std::ostream &out, Node *root);
    static int maxDepth(Node *root, int count);
    void transplant(Node *parent, Node *target, Node *newChild);
    static Node *cons(int x);
    static void deleteTree(Node *root);
    static Node *insert(int x, Node *root);
    bool remove(int x, Node *root);
    static Node *findParent(Node *p, int x);

    int randNum(int min, int max);

    // instance variable
    Node *root;
};

#endif