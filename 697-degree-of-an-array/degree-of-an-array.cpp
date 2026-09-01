class Solution {
public:
    int findShortestSubArray(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>mp;

        unordered_map<int, int>first;
        unordered_map<int, int>last;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;

            if(first.find(arr[i]) == first.end()){
                first[arr[i]] = i;
            }
            last[arr[i]] = i;
        }

        int maxFreq = 0;

        for (auto it : mp) {
            maxFreq = max(maxFreq, it.second);
        }

        int ans = INT_MAX;

        for (auto it : mp) {
            int ele = it.first;
            int freq = it.second;

            if (freq == maxFreq) {
                int length = last[ele] - first[ele] + 1;
                ans = min(ans, length);
            }
        }
        return ans;
    }
};