class Solution {
public:
//sliding window
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        string result = "";
        int cntones = 0;
        while(j < n){
            if(s[j] == '1'){
                cntones++;
            }

            while(cntones > k || s[i] == '0'){
                if(s[i] == '1'){
                    cntones--;
                }
                i++;
            }
            if(cntones == k){
                string temp = s.substr(i, j - i + 1);

                if(result.empty() || result.length() > j - i + 1 || (temp.length() == result.length() && temp < result)){
                    result = temp;
                }
            }
            j++;
        }
        return result;
    }
};