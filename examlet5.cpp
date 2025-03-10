#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform the required swapping
void swapChildrenIfNeeded(TreeNode*& root) {
    
    if (!root) return;

    TreeNode* trueRight = root->right;

    if (root->right && root->right->val < root->val) {
        
        TreeNode* rLeft = root->right->left;
        TreeNode* rRight = root->right->right;
        TreeNode* currLeft = root->left;

        root->left = rLeft;
        root->right = rRight;

        trueRight->left = currLeft;
        trueRight->right = root;

        root = trueRight;

    }

    swapChildrenIfNeeded(root->left);
    swapChildrenIfNeeded(root->right);

}

void swap(TreeNode*& a, TreeNode*& b) {

    TreeNode* temp = a;
    a = b;
    b = a;

}

void fitch(TreeNode*& root) {

    if (!root) return;

    if (root->right && root->right->val < root->val) {

        swap()

    }

    fitch(root->left);
    fitch(root->right);

}

// Helper function to print the tree (for debugging)
void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

// Helper function to create a simple test tree
TreeNode* createSampleTree() {
    /*
          5
         / \
        12   3
       / \   \
      1   2   7
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(12);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(7);

    return root;
}

int main() {
    TreeNode* root = createSampleTree();

    cout << "Before swapping:\n";
    inorderPrint(root);
    cout << endl;

    swapChildrenIfNeeded(root);

    cout << "After swapping:\n";
    inorderPrint(root);
    cout << endl;

    return 0;
}
