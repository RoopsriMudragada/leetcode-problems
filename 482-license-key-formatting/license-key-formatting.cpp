class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str = "";

        for(auto ch : s){
            if(ch == '-'){
                continue;
            }
            str += toupper(ch);
        }

        if(str.empty()){
            return "";
        }

        int n = str.size();
        int first = n % k;

        if(first == 0){
            first = k;
        }
        string ans = "";
        for(int i = 0; i < first; i++){
            ans += str[i];
        }

        for(int i = first; i < n; i += k){
            ans += '-';

            for(int j = i; j < i + k; j++){
                ans += str[j];
            }
        }
        return ans;
    }
};