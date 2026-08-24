class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int canEat = n / 2;

        unordered_set<int>st(candyType.begin(), candyType.end());
        int typesOfCandies = st.size();

        return min(canEat, typesOfCandies);

    }
};