class Solution {
public:
    bool detectCapitalUse(string word) {

        int capital = 0;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                capital++;
            }
        }

        if (capital == word.size())
            return true;


        if (capital == 0)
            return true;

        if (capital == 1 && word[0] >= 'A' && word[0] <= 'Z')
            return true;

        return false;
    }
};