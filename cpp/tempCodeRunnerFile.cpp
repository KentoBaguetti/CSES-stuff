void MakeRotateRight(TreeNode* nd){
    if (nd == nullptr){
        return;
    }
    
    // Process children first
    if (nd->left != nullptr){
        MakeRotateLeft(nd->left);
    }
    if (nd->right != nullptr){
        MakeRotateRight(nd->right);
    }
    while(nd -> left != nullptr){
        nd = rotateRight(nd);
    }
}