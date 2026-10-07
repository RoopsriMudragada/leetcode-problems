class Solution {
public:
    unordered_set<string> st;
    void solve(string &s, int idx, int balance, int removeopen, int removeclose, string &curr){
        if(balance < 0){
            return;
        }

        if(idx == s.size()){
            if(balance == 0 && removeopen == 0 && removeclose == 0){
                st.insert(curr);
            }
            return;
        }

        char ch = s[idx];

        if(ch != '(' && ch != ')'){
            curr.push_back(ch);
            solve(s, idx + 1, balance, removeopen, removeclose, curr);
            curr.pop_back();
        }

        else if(ch == '('){
            if(removeopen > 0){
                solve(s, idx + 1, balance, removeopen - 1, removeclose, curr);
            }
            
            curr.push_back('(');
            solve(s, idx + 1, balance + 1, removeopen, removeclose, curr);
            curr.pop_back();
        }

        else{
            if(removeclose > 0){
                solve(s, idx + 1, balance, removeopen, removeclose - 1, curr);
            }

            if(balance > 0){
                curr.push_back(')');
                solve(s, idx + 1, balance - 1, removeopen, removeclose, curr);
                curr.pop_back();
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int  n = s.size();
        vector<string> ans;
        int balanced = 0;
        int removeclose = 0;
        int removeopen = 0;
        for(auto ch : s){
            if(ch == '('){
                balanced++;
            }
            else if(ch == ')'){
                if(balanced > 0){
                    balanced--;
                }
                else{
                    removeclose++;
                }
            }
        }
        removeopen = balanced;

        string curr;
        solve(s, 0, 0, removeopen, removeclose, curr);

        return vector<string>(st.begin(), st.end());
    }
};
