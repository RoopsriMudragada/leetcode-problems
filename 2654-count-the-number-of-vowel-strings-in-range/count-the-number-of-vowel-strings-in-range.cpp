class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char>vow = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        int i = 0;
        for(auto word : words){
            string w = word;
            int size = w.size();
            if(i >= left && i <= right && vow.find(w[0]) != vow.end() && vow.find(w[size - 1]) != vow.end()){
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};