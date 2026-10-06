class Solution {
public:
    int solve(int row, int col, int n, int m, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(col < 0 || col >= n){
            return INT_MAX;
        }

        if(row == n - 1){
            return matrix[row][col];
        }

        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }

        int downleft = solve(row + 1, col - 1, n, m, matrix, dp);
        int down = solve(row + 1, col, n, m, matrix, dp);
        int downright = solve(row + 1, col + 1, n, m, matrix, dp);

        int bestpath = min(downleft, min(down, downright));

        return dp[row][col] = matrix[row][col] + bestpath;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        for(int col = 0; col < m; col++){
            int pathsum = solve(0, col, n, m, matrix, dp);
            ans = min(ans, pathsum);
        }
        return ans;
    }
};