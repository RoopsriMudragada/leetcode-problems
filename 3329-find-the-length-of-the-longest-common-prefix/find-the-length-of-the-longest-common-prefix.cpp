class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        int cnt = 0;

        unordered_set<string> st;
        for(int i = 0; i < n; i++){
            string str = to_string(arr1[i]);
            for(int len = 1; len <= str.size(); len++){
                st.insert(str.substr(0, len));
            }
        }

        for(int i = 0; i < m; i++){
            string str = to_string(arr2[i]);
            for(int len = 1; len <= str.size(); len++){
                string s = str.substr(0, len);
                if(st.find(s) != st.end()){
                    cnt = max(cnt,(int)s.size());
                }
            }
        }
        return cnt;
    }
};