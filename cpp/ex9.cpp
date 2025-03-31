#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;    
};

TreeNode* RotateLeft(TreeNode* nd) {
    return nullptr;
};

TreeNode* LeftSpine (TreeNode* nd) {

    if (!nd) return nullptr;

    while (nd->right) nd = RotateLeft(nd);

    if (nd->left) LeftSpine(nd->left);

    return nd;

} 