class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        int m = knowledge.size();
        unordered_map<string, string> mp;

        for (auto it : knowledge) {
            string key = it[0];
            string val = it[1];

            mp[key] = val;
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            string str = "";
            if (s[i] == '(') {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] != ')') {
                        str += s[j];
                    } else {
                        i = j;
                        break;
                    }
                }
                if (mp.find(str) != mp.end()) {
                    ans += mp[str];
                } else {
                    ans += '?';
                }
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};