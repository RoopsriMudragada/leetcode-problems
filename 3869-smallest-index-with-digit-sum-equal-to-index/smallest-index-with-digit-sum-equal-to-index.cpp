class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            string str = to_string(nums[i]);
            int s = str.size();
            int sum = 0;
            for(int i = 0; i < s; i++){
                char ch = str[i];
                sum = sum + (ch - '0');
            }
            if(sum == i){
                return i;
            }
        }
        return -1;
    }
};