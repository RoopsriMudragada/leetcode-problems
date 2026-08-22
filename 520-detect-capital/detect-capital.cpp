class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cnt = 0;

        for(auto it : word){
            if(isupper(it)){
                cnt++;
            }
        }
        if(cnt == n){
            return true;
        }
        if(cnt == 0){
            return true;
        }
        if(cnt == 1 && isupper(word[0])){
            return true;
        }
        return false;
    }
};