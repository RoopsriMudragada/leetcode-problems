class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 1 ; ; i++){
            bool found = false;
            for(int j = 0; j < n; j++){
                if(nums[j] == i * k){
                    found = true;
                    break;
                }
            }
            if(!found){
                return i * k;
            }
        }
        return -1;
    }
};