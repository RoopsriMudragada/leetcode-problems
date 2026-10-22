class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(begin(s), end(s))){
            return 0;
        }

        if(n == 2){
            return -1;
        }

        auto maxele = *max_element(begin(s), end(s));
        auto minele = *min_element(begin(s), end(s));

        if(s[0] == minele || s[n - 1] == maxele){
            return 1;
        }

        auto max_mid = *max_element(begin(s) + 1, end(s) - 1);
        auto min_mid = *min_element(begin(s) + 1, end(s) - 1); 

        if(s[0] > max_mid && s[n - 1] < min_mid){
            return 3;
        }

        return 2;
    }
};