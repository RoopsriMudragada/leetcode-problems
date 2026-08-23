class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int acount = 0;
        int lcount = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'A'){
                acount++;
            }

            if(s[i] == 'L'){
                lcount++;

                if(lcount >= 3){
                    return false;
                }
            }
            else{
                lcount = 0;
            }
        }
        return acount < 2;
    }
};