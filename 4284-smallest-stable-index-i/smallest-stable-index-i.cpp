class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int stableIndx = -1;
        int instabilityScore;
        for(int i = 0; i < n; i++){
            int maxi = INT_MIN;
            for(int j = 0; j <= i; j++){
                maxi = max(maxi, nums[j]);
            }
            int mini = INT_MAX;
            for(int j = i; j < n; j++){
                mini = min(mini, nums[j]);
            }
            instabilityScore = maxi - mini;

            if(instabilityScore <= k){
                return i;
            } 
        }
        return -1;
    }
};