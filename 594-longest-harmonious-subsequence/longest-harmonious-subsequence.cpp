class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            int x = it.first;
            if(mp.find(x + 1) != mp.end()){
                int len = mp[x] + mp[x + 1];
                ans = max(ans, len);
            }
        }
        return ans;
    }
};