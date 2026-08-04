class Solution {
public:

    // Height return karega
    // Agar subtree unbalanced mila to -1 return karega
    int height(TreeNode* root) {

        // Empty tree ki height = 0
        if (root == NULL) {
            return 0;
        }

        // Left subtree ki height
        int left = height(root->left);

        // Agar left subtree already unbalanced hai
        if (left == -1) {
            return -1;
        }

        // Right subtree ki height
        int right = height(root->right);

        // Agar right subtree already unbalanced hai
        if (right == -1) {
            return -1;
        }

        // Current node par height difference > 1
        // matlab tree balanced nahi hai
        if (abs(left - right) > 1) {
            return -1;
        }

        // Otherwise current subtree balanced hai
        // Parent ko apni height return karo
        return 1 + max(left, right);
    }


    bool isBalanced(TreeNode* root) {

        // Agar height() -1 deta hai
        // matlab kahin na kahin tree unbalanced mila
        if (height(root) == -1) {
            return false;
        }

        return true;
    }
};