class Solution {
public:
    int arrayPairSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        int maxi = 0;
        for(int i = 0; i < n; i+=2){
            if(i + 1 < n){
                maxi += min(arr[i], arr[i + 1]);
            }
        }
        return maxi;
    }
};