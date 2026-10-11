class Solution {
public:
    int sumOfSquares(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(n % (i + 1) == 0){
                int square = arr[i] * arr[i];
                sum += square;
            }
        }
        return sum;
    }
};