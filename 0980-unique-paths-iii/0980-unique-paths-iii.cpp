class Solution {
private:
    int totalPaths = 0;
    int emptyCells = 1;

    void dfs(vector<vector<int>>& grid, int r, int c, int count) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == -1) {
            return;
        }

        if (grid[r][c] == 2) {
            if (count == emptyCells) {
                totalPaths++;
            }
            return;
        }

        int temp = grid[r][c];
        grid[r][c] = -1;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            dfs(grid, r + dr[i], c + dc[i], count + 1);
        }

        grid[r][c] = temp;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startR = 0, startC = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startR = i;
                    startC = j;
                } else if (grid[i][j] == 0) {
                    emptyCells++;
                }
            }
        }

        dfs(grid, startR, startC, 0);
        return totalPaths;
        
    }
};