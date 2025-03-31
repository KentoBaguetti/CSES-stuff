#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort

// Binary tree node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    // Constructor for convenience
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to create a new node
TreeNode* createNode(int data) {
    return new TreeNode(data);
}

// Function to print the tree in-order (left, root, right)
void printInOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    printInOrder(root->left);
    std::cout << root->data << " ";
    printInOrder(root->right);
}

// Function to print the tree pre-order (root, left, right)
void printPreOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    std::cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Function to print the tree post-order (left, right, root)
void printPostOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    printPostOrder(root->left);
    printPostOrder(root->right);
    std::cout << root->data << " ";
}

// Function to print the tree structure visually (simple version)
void printTree(TreeNode* root, int level = 0) {
    if (root == nullptr) {
        return;
    }
    
    // Print right subtree
    printTree(root->right, level + 1);
    
    // Print current node
    for (int i = 0; i < level; i++) {
        std::cout << "    ";
    }
    std::cout << root->data << std::endl;
    
    // Print left subtree
    printTree(root->left, level + 1);
}

// Function to check if the tree is a straight line (right-skewed)
bool isRightSkewedLine(TreeNode* root) {
    if (root == nullptr) return true;
    
    // A straight line (right-skewed) tree should have no left children
    while (root != nullptr) {
        if (root->left != nullptr) return false;
        root = root->right;
    }
    return true;
}

// Function to collect all values in the tree (in-order)
void collectValues(TreeNode* root, std::vector<int>& values) {
    if (root == nullptr) return;
    
    collectValues(root->left, values);
    values.push_back(root->data);
    collectValues(root->right, values);
}

// Function to verify that the linearized tree contains all original values
bool containsAllValues(TreeNode* original, TreeNode* linearized) {
    std::vector<int> originalValues;
    std::vector<int> linearizedValues;
    
    collectValues(original, originalValues);
    collectValues(linearized, linearizedValues);
    
    if (originalValues.size() != linearizedValues.size()) return false;
    
    // Sort both vectors to compare values regardless of order
    std::sort(originalValues.begin(), originalValues.end());
    std::sort(linearizedValues.begin(), linearizedValues.end());
    
    return originalValues == linearizedValues;
}

// Function to create a copy of the tree
TreeNode* copyTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    
    TreeNode* newRoot = new TreeNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    
    return newRoot;
}

// Function to free memory of a tree
void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Function to perform a right rotation on a node
TreeNode* rotateRight(TreeNode* y) {
    if (y == nullptr || y->left == nullptr) {
        return y; // Can't rotate if node is null or has no left child
    }
    
    // Store the left child (which will become the new root)
    TreeNode* x = y->left;
    
    // The right subtree of x becomes the left subtree of y
    y->left = x->right;
    
    // y becomes the right child of x
    x->right = y;
    
    // Return the new root
    return x;
}

// Function to perform a left rotation on a node
TreeNode* rotateLeft(TreeNode* y) {
    if (y == nullptr || y->right == nullptr) {
        return y; // Can't rotate if node is null or has no right child
    }
    
    // Store the right child (which will become the new root)
    TreeNode* x = y->right;
    
    // The left subtree of x becomes the right subtree of y
    y->right = x->left;
    
    // y becomes the left child of x
    x->left = y;
    
    // Return the new root
    return x;
}

// Forward declaration for MakeRotateLeft since it's used in MakeRotateRight
TreeNode* MakeRotateLeft(TreeNode* nd);

// void MakeRotateRight(TreeNode* nd){
//     if (nd == nullptr){
//         return;
//     }
    
//     // Process children first
//     if (nd->left != nullptr){
//         MakeRotateLeft(nd->left);
//     }
//     if (nd->right != nullptr){
//         MakeRotateRight(nd->right);
//     }
//     while(nd -> left != nullptr){
//         nd = rotateRight(nd);
//     }
// }

// TreeNode* MakeRotateRight(TreeNode* nd) {
//     if (!nd) return nullptr;

//     while (nd->left) {
//         nd = rotateRight(nd);
//     }

//     if (nd->right) {
//         nd->right = MakeRotateRight(nd->right);
//     }

//     return nd;
// }

TreeNode* MakeRotateRight(TreeNode* nd) 

// TreeNode* MakeRotateLeft(TreeNode* nd){
//     if (nd == nullptr){
//         return nullptr;
//     }
    
//     // Process children first
//     if (nd->left != nullptr){
//         nd->left = MakeRotateLeft(nd->left);
//     }
//     if (nd->right != nullptr){
//         nd->right = MakeRotateRight(nd->right);
//     }
    
//     // Fix: Check for right children when doing left rotations
//     while(nd->right != nullptr){
//         nd = rotateLeft(nd);
//     }
    
//     return nd;
// }

// Answer function
TreeNode* answer(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    return MakeRotateRight(root);
}

// Test function to create different tree shapes for testing
TreeNode* createTestTree(int testCase) {
    TreeNode* root = nullptr;
    
    switch (testCase) {
        case 1: // Balanced tree
            //        10
            //       /  \
            //      5    15
            //     / \     \
            //    3   7     20
            root = createNode(10);
            root->left = createNode(5);
            root->right = createNode(15);
            root->left->left = createNode(3);
            root->left->right = createNode(7);
            root->right->right = createNode(20);
            break;
            
        case 2: // Already a line (right-skewed)
            //  1
            //   \
            //    2
            //     \
            //      3
            //       \
            //        4
            root = createNode(1);
            root->right = createNode(2);
            root->right->right = createNode(3);
            root->right->right->right = createNode(4);
            break;
            
        case 3: // Left-skewed tree
            //      4
            //     /
            //    3
            //   /
            //  2
            // /
            //1
            root = createNode(4);
            root->left = createNode(3);
            root->left->left = createNode(2);
            root->left->left->left = createNode(1);
            break;
            
        case 4: // Complex tree
            //         10
            //        /  \
            //       5    15
            //      / \   / \
            //     3   7 12  20
            //    / \    \
            //   1   4    9
            root = createNode(10);
            root->left = createNode(5);
            root->right = createNode(15);
            root->left->left = createNode(3);
            root->left->right = createNode(7);
            root->right->left = createNode(12);
            root->right->right = createNode(20);
            root->left->left->left = createNode(1);
            root->left->left->right = createNode(4);
            root->left->right->right = createNode(9);
            break;
            
        case 5: // Zigzag tree (alternating left-right pattern)
            //        50
            //       /
            //      40
            //       \
            //        45
            //       /
            //      42
            //       \
            //        43
            //       /
            //      41
            //       \
            //        44
            root = createNode(50);
            root->left = createNode(40);
            root->left->right = createNode(45);
            root->left->right->left = createNode(42);
            root->left->right->left->right = createNode(43);
            root->left->right->left->right->left = createNode(41);
            root->left->right->left->right->left->right = createNode(44);
            break;
            
        case 6: // Complete binary tree with multiple levels
            //              100
            //             /    \
            //           50      150
            //          /  \    /   \
            //        25   75  125  175
            //       / \   / \  / \  / \
            //      10 30 60 90 110 140 160 190
            root = createNode(100);
            
            root->left = createNode(50);
            root->right = createNode(150);
            
            root->left->left = createNode(25);
            root->left->right = createNode(75);
            root->right->left = createNode(125);
            root->right->right = createNode(175);
            
            root->left->left->left = createNode(10);
            root->left->left->right = createNode(30);
            root->left->right->left = createNode(60);
            root->left->right->right = createNode(90);
            root->right->left->left = createNode(110);
            root->right->left->right = createNode(140);
            root->right->right->left = createNode(160);
            root->right->right->right = createNode(190);
            break;
    }
    
    return root;
}

int main() {
    // Test all cases including the new complex ones
    for (int testCase = 1; testCase <= 6; testCase++) {
        std::cout << "\n=== Test Case " << testCase << " ===\n";
        
        // Create a test tree
        TreeNode* original = createTestTree(testCase);
        
        std::cout << "Original tree:\n";
        printTree(original);
        
        // Make a copy to linearize (so we can compare later)
        TreeNode* treeCopy = copyTree(original);
        
        // Linearize the tree with the updated MakeRotateRight function which now returns the new root
        TreeNode* linearized = answer(treeCopy);
        
        std::cout << "\nLinearized tree:\n";
        printTree(linearized);
        
        // Verify the result
        bool isLine = isRightSkewedLine(linearized);
        bool hasAllValues = containsAllValues(original, linearized);
        
        std::cout << "\nIs a straight line? " << (isLine ? "Yes" : "No") << std::endl;
        std::cout << "Contains all original values? " << (hasAllValues ? "Yes" : "No") << std::endl;
        
        // Clean up
        freeTree(original);
        freeTree(linearized);
    }
    
    return 0;
} 