class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int start, int n, int k, vector<int>& temp) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++) {

            temp.push_back(i);

            backtrack(i + 1, n, k, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<int> temp;

        backtrack(1, n, k, temp);

        return ans;
    }
};