class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        vector<string> ans;
        vector<int> rowOf(26, 0 );
        for(auto ch : row1){
            rowOf[ch - 'a'] = 1;
        }
        for(auto ch : row2){
            rowOf[ch - 'a'] = 2;
        }
        for(auto ch : row3){
            rowOf[ch - 'a'] = 3;
        }

        for(auto it : words){
            int row = rowOf[tolower(it[0]) - 'a'];
            bool isvalid = true;
            for(auto ch : it){
                if(rowOf[tolower(ch) - 'a'] != row){
                    isvalid = false;
                    break;
                }
            }
            if(isvalid){
                ans.push_back(it);
            }
        }
        return ans;
    }
};