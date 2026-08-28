class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = list1.size();
        int m = list2.size();
        vector<string> result;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(list1[i] == list2[j]){
                    if(i + j < mini){
                        mini = i + j;
                        result.clear();
                        result.push_back(list1[i]);
                    }
                    else if(i + j == mini){
                        result.push_back(list1[i]);
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        return result;
    }
};