class Solution {
public:
    int n, m;
    int solve(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
        if (row == n - 1) {
            if (col1 == col2) {
                return grid[row][col1];
            }
            if (col1 != col2) {
                return grid[row][col1] + grid[row][col2];
            }
        }

        if(dp[row][col1][col2] != -1){
            return dp[row][col1][col2];
        }

        int curr;

        if (col1 == col2)
            curr = grid[row][col1];
        else
            curr = grid[row][col1] + grid[row][col2];

        int maxi = 0;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int newcol1 = col1 + d1;
                int newcol2 = col2 + d2;

                if (newcol1 >= 0 && newcol1 < m && newcol2 >= 0 &&
                    newcol2 < m) {
                    int val = curr + solve(row + 1, newcol1, newcol2, grid, dp);
                    maxi = max(maxi, val);
                }
            }
        }
        return dp[row][col1][col2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m - 1, grid, dp);
    }
};