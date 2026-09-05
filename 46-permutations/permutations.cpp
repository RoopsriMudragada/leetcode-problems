class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int>& arr, vector<int> &used){
        if(temp.size() == arr.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < arr.size(); i++){
            if(used[i]){
                continue;
            }

            temp.push_back(arr[i]);
            used[i] = 1;

            solve(arr, used);

            temp.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& arr) {
        int n = arr.size();
        vector<int>used(n, 0);
        solve(arr, used);
        return ans;
    }
};