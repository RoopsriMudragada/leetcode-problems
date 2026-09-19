// TLE
// class Solution {
// public:
//     vector<long long> distance(vector<int>& arr) {
//         int n = arr.size();
//         vector<long long> ans(n, 0);
//         for(int i = 0; i < n; i++){
//             long long sum = 0;
//             for(int j = 0; j < n; j++){
//                 if(i != j && arr[i] == arr[j]){
//                     sum += abs(j - i);
//                 }
//                 else{
//                     continue;
//                 }
//             }
//             ans[i] = sum;
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>>mp;

        //insert every index of an element into map
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto it : mp){
            auto &pos = it.second;

            int m = pos.size();

            //prefixSum of pos
            vector<long long>prefixsum(m, 0);
            prefixsum[0] =  pos[0];

            for(int i = 1; i < m ;i++){
                prefixsum[i] = prefixsum[i - 1] + pos[i];
            }

            for(int i = 0; i < m; i++){
                long long left = 0;
                long long right = 0;
                //left 
                if(i > 0){
                    long long leftcnt = i;
                    long long leftsum = prefixsum[i - 1];

                    left = (long long)pos[i] * leftcnt - leftsum;
                }

                //right
                if(i < m - 1){
                    long long rightcnt = m - i - 1;
                    long long rightsum = prefixsum[m - 1] - prefixsum[i];

                    right = rightsum - (long long)pos[i] * rightcnt;
                }
                ans[pos[i]] = left + right;
            }
        }
        return ans;
    }
};