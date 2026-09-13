class Solution {
public:
    int countOverLaps(vector<vector<int>>& img1, vector<vector<int>>& img2, int &row, int &col, int n){
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int b_i = i + row;
                int b_j = j + col;

                if(b_i < 0 || b_i >= n || b_j < 0 || b_j >= n){
                    continue;
                }

                if(img1[i][j] == 1 && img2[b_i][b_j] == 1){
                    count++;
                }
            }
        }
        return count;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int maxOverLapCnt = 0;

        for(int row = -n + 1; row < n; row++){
            for(int col = -n + 1; col < n; col++){
                int count = countOverLaps(img1, img2, row, col, n);
                maxOverLapCnt = max(maxOverLapCnt, count);
            }
        }
        return maxOverLapCnt;
    }
};