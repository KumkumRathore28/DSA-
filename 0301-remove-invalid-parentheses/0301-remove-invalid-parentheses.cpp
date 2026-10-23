class Solution {
public:

    vector<string> ans;

    void dfs(string &s, int start,
             int leftRemove, int rightRemove) {
        if (leftRemove == 0 && rightRemove == 0) {
            if (isValid(s)) {
                ans.push_back(s);
            }
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (i != start && s[i] == s[i - 1]) {
                continue;
            }
            if (leftRemove + rightRemove > s.size() - i) {
                return;
            }
            if (leftRemove > 0 && s[i] == '(') {

                s.erase(i, 1);

                dfs(s, i, leftRemove - 1, rightRemove);

                s.insert(i, 1, '(');
            }
            if (rightRemove > 0 && s[i] == ')') {

                s.erase(i, 1);

                dfs(s, i, leftRemove, rightRemove - 1);

                s.insert(i, 1, ')');
            }
        }
    }
    bool isValid(string &s) {

        int count = 0;

        for (char ch : s) {

            if (ch == '(') {
                count++;
            }
            else if (ch == ')') {

                count--;

                if (count < 0) {
                    return false;
                }
            }
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }
        dfs(s, 0, leftRemove, rightRemove);

        return ans;
    }
};