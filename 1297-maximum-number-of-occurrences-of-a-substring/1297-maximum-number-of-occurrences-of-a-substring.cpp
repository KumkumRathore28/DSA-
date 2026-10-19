class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {

        unordered_map<string, int> freq;
        int ans = 0;

        for (int i = 0; i <= s.length() - minSize; i++) {

            string sub = s.substr(i, minSize);

            unordered_set<char> uniqueChars;

            for (char ch : sub) {
                uniqueChars.insert(ch);
            }

            if (uniqueChars.size() <= maxLetters) {
                freq[sub]++;
                ans = max(ans, freq[sub]);
            }
        }

        return ans;
    }
};