class Solution {
public:
    vector<int> resultArray(vector<int>& arr) {
        int n = arr.size();

        vector<int>arr1;
        vector<int>arr2;

        arr1.push_back(arr[0]);
        arr2.push_back(arr[1]);
        for(int i = 2; i < n; i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(arr[i]);
            }
            else{ 
                arr2.push_back(arr[i]);
            }
        }

        for(int i = 0; i < arr2.size(); i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};