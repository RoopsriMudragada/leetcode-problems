class Solution {
public:
    bool solve(string &s, int idx, int cnt, vector<vector<int>> &dp){
        int n = s.size();
        if(cnt < 0){
            return false;
        }

        if(idx == n){
            return (cnt == 0);
        }

        if(dp[idx][cnt] != -1){
            return dp[idx][cnt];
        }

        if(s[idx] == '('){
            return dp[idx][cnt] = solve(s, idx + 1, cnt + 1, dp);
        }

        if(s[idx] == ')'){
            return dp[idx][cnt] = solve(s, idx + 1, cnt - 1, dp);
        }

        return dp[idx][cnt] = solve(s, idx + 1, cnt + 1, dp) || solve(s, idx + 1, cnt - 1, dp) || solve(s, idx + 1, cnt, dp);
    }

    bool checkValidString(string s) {
        int n = s.size();
        int cnt = 0;
        int idx = 0;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(s, idx, cnt, dp);
    }
};