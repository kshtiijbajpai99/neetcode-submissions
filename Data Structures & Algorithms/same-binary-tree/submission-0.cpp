class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Dono NULL hain -> same
        if (p == NULL && q == NULL) {
            return true;
        }

        // Ek NULL hai aur doosra nahi -> different
        if (p == NULL || q == NULL) {
            return false;
        }

        // Current nodes ki value different hai -> different tree
        if (p->val != q->val) {
            return false;
        }

        // Current nodes same hain
        // Ab left-left aur right-right recursively check karo
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};