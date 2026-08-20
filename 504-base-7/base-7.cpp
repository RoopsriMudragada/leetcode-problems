class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0){
            return "0";
        }

        bool neg = num < 0;
        num = abs(num);
        string n = "";
        while(num > 0){
            int digit = num % 7;
            n += (char)(digit + '0');
            num /= 7;
        }
        reverse(n.begin(), n.end());
        return neg ? '-' + n : n;
    }
};