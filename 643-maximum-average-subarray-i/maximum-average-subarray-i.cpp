class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        double maxi = 1LL * INT_MIN;
        double sum = 0;
        while(j < n){
            sum += nums[j];
            while(j - i + 1 > k){
                sum -= nums[i];
                i++;
            }
            if(j - i + 1 == k){
                maxi = max(maxi, (double)sum / k);
            }
            j++;
        } 
        return maxi;
    }
};