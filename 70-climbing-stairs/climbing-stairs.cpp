class Solution {
public:
    int solve(int n, int start, vector<int> &dp){
        if(start > n){
            return 0;
        }

        if(start == n){
            return 1;
        }

        if(dp[start] != -1){
            return dp[start];
        }

        return dp[start] = solve(n, start + 1, dp) + solve(n, start + 2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, 0, dp);
    }
};