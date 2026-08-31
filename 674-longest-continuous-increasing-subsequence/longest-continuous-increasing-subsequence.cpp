class Solution {
public:
    int findLengthOfLCIS(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int maxi = 0;

        if(arr.size() == 1){
            return 1;
        }
        
        while (j + 1 < n) {
                if (arr[j + 1] > arr[j]) {
                    j++;
                }
                else{
                    i = j + 1;
                    j++;
                }
                maxi = max(maxi, j - i + 1);
            }
        return maxi;
    }
};