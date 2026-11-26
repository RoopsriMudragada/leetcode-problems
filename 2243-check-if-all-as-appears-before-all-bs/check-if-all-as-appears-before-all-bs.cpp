class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        for(int i = 1; i < n; i++){
            if(s[i] < s[i - 1]){
                return false;
            }
        }
        return true;
    }
};