class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int depth = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                depth++;
            }
            else if(s[i] == ')'){
                depth--;
                if(s[i - 1] == '('){
                    cnt += pow(2, depth);
                }
            }
        }
        return cnt;
    }
};