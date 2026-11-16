class Codec {
public:
    
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";

        queue<TreeNode*> q;
        q.push(root);

        string result = "";

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                result += "N,";
            }
            else {

                result += to_string(node->val) + ",";

                q.push(node->left);
                q.push(node->right);
            }
        }

        return result;
    }

    TreeNode* deserialize(string data) {

        if (data.empty())
            return nullptr;

        stringstream ss(data);
        string value;
        getline(ss, value, ',');

        TreeNode* root = new TreeNode(stoi(value));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (!getline(ss, value, ','))
                break;

            if (value != "N") {

                TreeNode* leftNode = new TreeNode(stoi(value));

                node->left = leftNode;
                q.push(leftNode);
            }

            if (!getline(ss, value, ','))
                break;

            if (value != "N") {

                TreeNode* rightNode = new TreeNode(stoi(value));

                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
