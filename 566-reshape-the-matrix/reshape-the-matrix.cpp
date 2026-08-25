class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();

        if(n * m != r * c){
            return mat;
        }

        vector<int> onedArr;
        //2D --> 1D
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                onedArr.push_back(mat[i][j]);
            }
        }

        //1D --> 2D
        vector<vector<int>>arr(r,vector<int>(c, 0));
        for(int i = 0; i < onedArr.size(); i++){
            arr[i/c][i%c] = onedArr[i];
        }
        return arr;
    }
};