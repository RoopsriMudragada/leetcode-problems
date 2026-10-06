class Solution {
public:
    // int solve(int i, int j, int n, int m, vector<vector<int>>& triangle, vector<vector<int>> &dp){

    //     if(dp[i][j] != INT_MAX){
    //         return dp[i][j];
    //     }

    //     if(i == n - 1){
    //         return dp[i][j] = triangle[n - 1][j];
    //     }

    //     int d = triangle[i][j] + solve(i + 1, j, n, m, triangle, dp);
    //     int dg = triangle[i][j] + solve(i + 1, j + 1, n, m, triangle, dp);
    //     return dp[i][j] = min(d, dg);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // int m = triangle[0].size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        // return solve(0, 0, n, m, triangle, dp);

        for(int j = 0; j < n; j++){
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
};