class Solution {
public:
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd) {

        if (inStart > inEnd)
            return NULL;

        int rootValue = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int pos = mp[rootValue];

        root->right = build(inorder, postorder, pos + 1, inEnd);
        root->left = build(inorder, postorder, inStart, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};