class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a, b;
        long long actualsum=0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualsum += grid[i][j];
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                } else {
                    s.insert(grid[i][j]);
                }
            }
        }
            long long totalsum = (long long)n * n;
            long long expectedsum = totalsum * (totalsum + 1) / 2;
        b = expectedsum + a - actualsum;
        ans.push_back(b);

        return ans;
    }
};