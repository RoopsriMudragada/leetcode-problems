class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftQnMarks = 0;
        int rightQnMarks = 0;

        int leftSum = 0;
        int rightSum = 0;

        //Calc leftQnMarks, rightQnMarks, leftSum, rightSum
        for(int i = 0; i < n; i++){
            if(num[i] == '?'){
                if(i < n / 2){
                    leftQnMarks++;
                }
                else{
                    rightQnMarks++;
                }
            }
            else{
                if(i < n / 2){
                    leftSum += num[i] - '0';
                }
                else{
                    rightSum += num[i] - '0';
                }
            }
        }

        int totalQnMarks = leftQnMarks + rightQnMarks;
        //If totalQnMarks are Odd Alice Win (return true);
        if(totalQnMarks % 2 == 1){
            return true;
        }

        int left = 2 * leftSum + 9 * leftQnMarks;
        int right = 2 * rightSum + 9 * rightQnMarks;

        return left == right ? false : true;
    }
};