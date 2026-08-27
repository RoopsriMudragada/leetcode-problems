class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        for(int len = k; len <= n; len++){
            string result = "";

            for(int start = 0; start <= n - len; start++){
                string temp = s.substr(start, len);
                
                int cnt = 0;
                for(auto &it : temp){
                    cnt += (it == '1') ? 1 : 0;
                }
                if(cnt == k){
                    if(result.empty() || temp < result){
                        result = temp;
                    }
                }
            }
            if(!result.empty()){
                return result;
            }
        }
        return "";
    }
};