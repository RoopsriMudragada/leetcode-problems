class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>prefixmax(n);
        vector<int>suffixmin(n);
        int stableindx = -1;
        prefixmax[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixmax[i] = max(prefixmax[i - 1], nums[i]);
        }

        suffixmin[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffixmin[i] = min(suffixmin[i + 1], nums[i]);
        }
        for(int i = 0;i < n;i++){
            cout << prefixmax[i] << " " << suffixmin[i] << "\n";
        }
        for(int i = 0; i < n; i++){
            int instabilityscore = prefixmax[i] - suffixmin[i];
            if(instabilityscore <= k){
                return i;
            }
        }
        return -1;
    }
};