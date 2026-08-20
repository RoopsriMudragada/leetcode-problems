class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<int>sortedScore = score;
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());

        unordered_map<int, string>mp;

        for(int i = 0; i < n; i++){
            if(i == 0)mp[sortedScore[i]] = "Gold Medal";
            else if(i == 1)mp[sortedScore[i]] = "Silver Medal";
            else if(i == 2)mp[sortedScore[i]] = "Bronze Medal";
            else mp[sortedScore[i]] = to_string(i + 1);
        }
        vector<string> ans;
        for(auto it : score){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};