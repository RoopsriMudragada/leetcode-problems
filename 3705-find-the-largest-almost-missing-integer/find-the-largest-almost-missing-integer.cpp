class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>count;

        for(int i = 0; i <= n - k; i++){
            unordered_set<int> seen;
            for(int j = i; j < i + k; j++){
                seen.insert(nums[j]);
            }
            for(auto it : seen){
                count[it]++;
            }
        }

        int ans = -1;
        for(auto & [val, freq] : count){
            if(freq == 1){
                ans = max(ans, val);
            }
        }
        return ans;
    }
};