class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size();
        unordered_map<int,int>mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            mp[sum] = i;
        }

        if(sum < x){
            return -1;
        }

        int remsum = sum - x;

        sum = 0;
        int longsubbarr = INT_MIN;
        for(int i  = 0; i < n; i++){
            sum += arr[i];
            int find = sum - remsum;
            if(mp.find(find) != mp.end()){
                int idx = mp[find];
                longsubbarr = max(longsubbarr, i - idx);
            }
        }
        return longsubbarr == INT_MIN ? -1 : n - longsubbarr;
    }
};