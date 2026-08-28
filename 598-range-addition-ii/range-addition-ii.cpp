class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.empty()){
            return m * n;
        }

        int mini = INT_MAX;
        int a = INT_MAX;
        int b = INT_MAX;
        int cnt = 0;
        for(auto it : ops){
            a = min(a,it[0]);
            b = min(b,it[1]);

            cnt = a * b;
        }
        return cnt;
    }
};