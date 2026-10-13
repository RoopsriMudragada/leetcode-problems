class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            nums[i] = nums[i] * nums[i];
        }

        sort(begin(nums), end(nums));
        long long larger = accumulate(nums.begin() + n / 2, nums.end(), 0LL);
        long long smaller = accumulate(nums.begin(),nums.begin() + n / 2, 0LL);

        return larger - smaller;
    }
};