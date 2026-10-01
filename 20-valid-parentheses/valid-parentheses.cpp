class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for(auto ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
                continue;
            }

            if(st.empty()){
                return false;
            }
            
            auto c = st.top();
            if((c == '(' && ch == ')') || (c == '[' && ch == ']') || (c == '{' && ch == '}')){
                st.pop();
                // continue;
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};