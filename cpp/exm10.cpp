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

// Your task:
// BSTHNode* Balance(BSTHNode* root) {
//     // TODO: Implement this function to return a balanced BST

//     if (!root) return nullptr;

//     root = MakeRightSpine(root);
//     int leftHeight = 0;
//     int rightHeight = root->height;
//     while (abs(leftHeight - rightHeight) > 1) {
//         root = MakeRotateLeft(root);
//         leftHeight = root->left->height + 1;
//         rightHeight = root->height;
//     }

//     root->left = Balance(root->left);
//     root->right = Balance(root->right);

//     int leftChildHeight = 0;
//     int rightChildHeight = 0;

//     if (root->left) leftChildHeight = root->left->height + 1;
//     if (root->right) rightChildHeight = root->right->height + 1;

//     root->height = max(leftChildHeight, rightChildHeight);

//     return root;

// }

BSTHNode* Balance(BSTHNode* nd) {

    if (!nd) return nullptr;

    nd = MakeRightSpine(nd);
    int leftHeight = 0;
    int rightHeight = nd->height;
    while (abs(leftHeight - rightHeight) > 1) {
        nd = MakeRotateLeft(nd);
        leftHeight = nd->left->height + 1;
        rightHeight = nd->height;
    }

    nd->left = Balance(nd->left);
    nd->right = Balance(nd->right);

    int LH = 0;
    int RH = 0;

    if (nd->left) LH = nd->left->height + 1;
    if (nd->right) RH = nd->right->height + 1;

    nd->height = max(LH, RH);

    return nd;

}

bool BTreeSearch(BTreeNode* nd, int target) {

    int i = 0;
    while (i < nd->keys.size() && nd->keys[i] < target) i++;
    if (i < nd->keys.size() && nd->keys[i] == target) return true;
    if (nd->isLeaf == true) return false;

    return BTreeSearch(nd->children[i], target);

}
