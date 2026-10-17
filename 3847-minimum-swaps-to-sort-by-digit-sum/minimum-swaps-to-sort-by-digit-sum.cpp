class Solution {
public:
    int getdigitsum(int num){
        int sum = 0;
        while(num > 0){
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>aftersorted(nums);

        auto lamda = [&](int num1, int num2){
            int sum1 = getdigitsum(num1);
            int sum2 = getdigitsum(num2);

            if(sum1 != sum2){
                return sum1 < sum2;
            }
            return num1 < num2;
        };

        sort(begin(aftersorted), end(aftersorted), lamda);

        unordered_map<int, int>valtoidx;
        for(int i = 0; i < n; i++){
            valtoidx[nums[i]] = i;
        }

        int swaps = 0;
        for(int i = 0; i < n; i++){
            int expectedval = aftersorted[i];
            int currval = nums[i];

            if(expectedval == currval){
                continue;
            }

            int idx = valtoidx[expectedval];

            nums[i] = expectedval;
            nums[idx] = currval;

            valtoidx[expectedval] = i;
            valtoidx[currval] = idx;

            swaps++;
        }
        return swaps;
    }
};