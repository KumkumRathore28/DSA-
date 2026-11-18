class Solution {
public:
    struct Node {
        Node* child[2];

        Node() {
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };

    Node* root = new Node();

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (node->child[bit] == nullptr) {
                node->child[bit] = new Node();
            }

            node = node->child[bit];
        }
    }

    int findMaxXOR(int num) {
        Node* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if (node->child[opposite] != nullptr) {
                ans |= (1 << i);
                node = node->child[opposite];
            }
            else {
                node = node->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0;

        for (int num : nums) {
            insert(num);
        }

        for (int num : nums) {
            maxi = max(maxi, findMaxXOR(num));
        }

        return maxi;
    }
};
