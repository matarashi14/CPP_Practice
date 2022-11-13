#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>
#include "BST.h"

using namespace std;

int main()
{

    srand(time(0));

    // BST b;
    // b.insert(8);
    // b.insert(3);
    // b.insert(10);
    // b.insert(1);
    // b.insert(6);
    // b.insert(9);
    // b.insert(12);
    // b.insert(15);

    // //          8
    // //         / \a
    // //       3    10
    // //      / \   / \a
    // //     1   6 9   12
    // //                 \a
    // //                  15

    // // 8 3 1 6 10 9 12
    // // root -> left subtree -> right subtree
    // b.preOrderWalk(cout);
    // cout << endl;

    // // 1 3 6 8 9 10 12
    // // left subtree -> root -> right subtree
    // b.inOrderWalk(cout);
    // cout << endl;

    // // 1 6 3 9 12 10 8
    // // left subtree -> right subtree -> root
    // // children first walk
    // b.postOrderWalk(cout);
    // cout << endl;

    // // 12 10 9 8 6 3 1
    // // right subtree -> root -> left subtree
    // b.reverseOrderWalk(cout);
    // cout << endl;

    // cout << b.maxDepth() << endl;

    // cout << boolalpha;
    // cout << b.serach(6) << endl; // true
    // cout << b.serach(5) << endl; // false

    // b.remove(6);
    // b.remove(15);
    // b.remove(1);
    // b.remove(9);
    // b.insert(11);
    // b.remove(11);
    // b.remove(3);
    // b.remove(8);
    // // b.remove(10);
    // b.remove(12);
    // b.inOrderWalk(cout);
    // cout << endl;

    return 0;
}
