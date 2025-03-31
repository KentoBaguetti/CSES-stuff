#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct BSTHNode {
    int value;
    BSTHNode* left;
    BSTHNode* right;
    int height;

    BSTHNode(int val) : value(val), left(nullptr), right(nullptr), height(0) {}
};

struct BTreeNode {
    bool isLeaf;
    vector<int> keys;
    vector<BTreeNode*> children;
};

// Provided helper functions
BSTHNode* MakeRightSpine(BSTHNode* root);
BSTHNode* MakeRotateLeft(BSTHNode* node);
BSTHNode* MakeRotateRight(BSTHNode* node);

BSTHNode* Balance (BSTHNode* nd) {

    if (!nd) return nullptr;

    nd = MakeRightSpine(nd);

    int lh = 0;
    int rh = nd->height;

    while (lh - rh < -1) {
        nd = MakeRotateLeft(nd);
        lh++;
        rh--;
    }

    nd->left = Balance(nd->left);
    nd->right = Balance(nd->right);

    lh = 0;
    rh = 0;

    if (nd->left) lh = nd->left->height + 1;
    if (nd->right) rh = nd->right->height + 1;

    nd->height = max(lh, rh);

    return nd;

}