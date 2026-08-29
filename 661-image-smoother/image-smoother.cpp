class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = img[i][j];
                int cnt = 1;
                for (int k = 0; k < 8; k++) {
                    int nrow = i + drow[k];
                    int ncol = j + dcol[k];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                        sum += img[nrow][ncol];
                        cnt++;
                    }
                }
                ans[i][j] = floor(sum / cnt);
            }
        }
        return ans;
    }
};