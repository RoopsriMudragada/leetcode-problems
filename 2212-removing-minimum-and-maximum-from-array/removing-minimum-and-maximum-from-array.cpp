class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 1;
        }

        int maxInd = max_element(nums.begin(), nums.end()) - nums.begin();
        int minInd = min_element(nums.begin(), nums.end()) - nums.begin();


        //Both from left
        int left = max(maxInd, minInd) + 1;
        int right = n - min(maxInd, minInd);
        int both = min(minInd, maxInd) + 1 + (n - max(maxInd, minInd));

        return min({left, right, both});
    }
};