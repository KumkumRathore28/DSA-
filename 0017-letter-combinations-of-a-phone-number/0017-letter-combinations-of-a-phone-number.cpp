class Solution {
public:
    vector<string> result;

    vector<string> letters = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string &digits, int index, string current) {

        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string possibleLetters = letters[digits[index] - '0'];

        for (char ch : possibleLetters) {

            current.push_back(ch);

            backtrack(digits, index + 1, current);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        backtrack(digits, 0, "");

        return result;
    }
};