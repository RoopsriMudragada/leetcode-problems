class Solution {
public:
    unordered_set<string> st;

    void solve(string &s, int idx, int balance,
               int removeOpen, int removeClose,
               string &curr) {

        // Invalid state
        if (balance < 0)
            return;

        // End of string
        if (idx == s.size()) {
            if (balance == 0 && removeOpen == 0 && removeClose == 0) {
                st.insert(curr);
            }
            return;
        }

        char ch = s[idx];

        // Normal character
        if (ch != '(' && ch != ')') {
            curr.push_back(ch);
            solve(s, idx + 1, balance,
                  removeOpen, removeClose, curr);
            curr.pop_back();
        }

        // '('
        else if (ch == '(') {

            // Remove '('
            if (removeOpen > 0) {
                solve(s, idx + 1, balance,
                      removeOpen - 1, removeClose, curr);
            }

            // Keep '('
            curr.push_back('(');
            solve(s, idx + 1, balance + 1,
                  removeOpen, removeClose, curr);
            curr.pop_back();
        }

        // ')'
        else {

            // Remove ')'
            if (removeClose > 0) {
                solve(s, idx + 1, balance,
                      removeOpen, removeClose - 1, curr);
            }

            // Keep ')' only if it has a matching '('
            if (balance > 0) {
                curr.push_back(')');
                solve(s, idx + 1, balance - 1,
                      removeOpen, removeClose, curr);
                curr.pop_back();
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int balance = 0;
        int removeClose = 0;

        // Step 1: calculate minimum removals
        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {

                if (balance > 0) {
                    balance--;
                }
                else {
                    removeClose++;
                }
            }
        }

        int removeOpen = balance;

        // Step 2: backtracking
        string curr;

        solve(s, 0, 0,
              removeOpen, removeClose,
              curr);

        return vector<string>(st.begin(), st.end());
    }
};