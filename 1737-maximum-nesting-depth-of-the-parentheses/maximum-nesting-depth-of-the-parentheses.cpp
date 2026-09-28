class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                cnt++;
            }
            if(s[i] == ')'){
                cnt--;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};