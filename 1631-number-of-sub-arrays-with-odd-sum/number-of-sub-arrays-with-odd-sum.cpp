class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long even = 1;
        long long odd = 0;
        int sum = 0;

        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }
        return (odd * even) % mod;
    }
};