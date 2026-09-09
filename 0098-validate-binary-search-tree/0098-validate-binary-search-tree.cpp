class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }

    bool check(TreeNode* root, long minValue, long maxValue) {

        if (root == NULL)
            return true;

        if (root->val <= minValue || root->val >= maxValue)
            return false;

        return check(root->left, minValue, root->val) &&
               check(root->right, root->val, maxValue);
    }
};