class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int r, int c, int n, int expvalue) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expvalue) {
            return false;
        }
        if (expvalue == n *n - 1) {
            return true;
        }
     bool ans1 = isvalid(grid, r - 2, c + 1, n, expvalue + 1);
        bool ans2 = isvalid(grid, r - 1, c + 2, n, expvalue + 1);
        bool ans3 = isvalid(grid, r + 1, c + 2, n, expvalue + 1);
        bool ans4 = isvalid(grid, r + 2, c + 1, n, expvalue + 1);
        bool ans5 = isvalid(grid, r + 2, c - 1, n, expvalue + 1);
        bool ans6 = isvalid(grid, r + 1, c - 2, n, expvalue + 1); 
        bool ans7 = isvalid(grid, r - 1, c - 2, n, expvalue + 1);
        bool ans8 = isvalid(grid, r - 2, c - 1, n, expvalue + 1);
        return ans1|| ans2|| ans3|| ans4|| ans5|| ans6|| ans7|| ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        int n=grid.size();
        return isvalid(grid, 0, 0, n, 0);
    }
};