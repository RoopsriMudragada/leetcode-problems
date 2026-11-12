class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n = arr.size();
        int inc = 1;
        int dec = 1;
        int maxi = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] > arr[i - 1]){
                inc++;
                dec = 1;
                maxi = max(maxi, max(inc, dec));
            }
            else if(arr[i] < arr[i - 1]){
                dec++;
                inc = 1;
                maxi = max(maxi, max(inc, dec));
            }
            else{
                inc = 1;
                dec = 1;
                maxi = max(maxi, max(inc, dec));
            }
        }
        return n == 1 ? 1 : maxi;
    }
};