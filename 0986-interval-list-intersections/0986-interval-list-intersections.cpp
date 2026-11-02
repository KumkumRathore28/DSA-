class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first,
        vector<vector<int>>& second
    ) {
        
        vector<vector<int>> ans;

        int i = 0;
        int j = 0;

        while (i < first.size() && j < second.size()) {
            int start = max(first[i][0], second[j][0]);
            int end = min(first[i][1], second[j][1]);

            if (start <= end) {
                ans.push_back({start, end});
            }

            if (first[i][1] < second[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return ans;
    }
};