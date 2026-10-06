class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;

        for(auto ch : s){
            if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        return st.size();
    }
};