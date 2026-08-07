class Solution {
public:

    void inorder(TreeNode* root, int k, int &cnt, int &ans) {

        // Base case
        if (root == NULL)
            return;

        // 1. LEFT
        inorder(root->left, k, cnt, ans);

        // 2. ROOT
        cnt++;

        // kth node mil gaya
        if (cnt == k) {
            ans = root->val;
            return;
        }

        // 3. RIGHT
        inorder(root->right, k, cnt, ans);
    }


    int kthSmallest(TreeNode* root, int k) {

        int cnt = 0;
        int ans = -1;

        inorder(root, k, cnt, ans);

        return ans;
    }
};