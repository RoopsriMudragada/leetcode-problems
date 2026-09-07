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

            if(i > 0 && arr[i] == arr[i - 1] && !used[i - 1]){
                continue;
            }

            temp.push_back(arr[i]);
            used[i] = 1;

            solve(arr, used);

            temp.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> used(n, 0);
        solve(arr, used);
        return ans;
    }
};