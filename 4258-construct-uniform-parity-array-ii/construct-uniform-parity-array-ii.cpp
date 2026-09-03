class Solution {
public:
    bool uniformArray(vector<int>& arr) {
        int minele = *min_element(arr.begin(), arr.end());

        //if minele == odd returns true because it make any even ele to odd
        if(minele % 2 == 1){
            return true;
        }

        //check any odd rather than even if odd exists return false
        for(auto it : arr){
            if(it % 2 == 1){
                return false;
            }
        }
        return true;
    }
};