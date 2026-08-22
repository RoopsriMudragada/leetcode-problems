class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int sum = 0;
        int product = 1;
        while(num > 0){
            int digit = num % 10;
            sum += digit;
            product *= digit;
            num = num / 10;
        }
        if(n % (sum + product) == 0){
            return true;
        }
        return false;
    }
};