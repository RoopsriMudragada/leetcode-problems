class Solution {
public:
    int calPoints(vector<string>& arr) {
        int n = arr.size();
        vector<int>ans;

        for(int i = 0; i < n; i++){
            if(arr[i] == "C"){
                ans.pop_back();
            }
            else if(arr[i] == "D"){
                int val = ans.back() * 2;
                ans.push_back(val);
            }
            else if(arr[i] == "+"){
                int sum = ans[ans.size() - 1] + ans[ans.size() - 2];
                ans.push_back(sum);
            }
            else{
                ans.push_back(stoi(arr[i]));
            }
        }

        int total = 0;
        for(int i = 0; i < ans.size(); i++){
            total += ans[i];
        }
        return total;
    }
};