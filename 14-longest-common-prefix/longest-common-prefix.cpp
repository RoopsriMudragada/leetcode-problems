class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        string first = arr[0];
        string last = arr[n - 1];
        string ans = "";
        for(int i = 0; i < min(first.size(), last.size()); i++){
            if(first[i] != last[i]){
                break;
            }
            ans += first[i];
        }
        return ans;
    }
};