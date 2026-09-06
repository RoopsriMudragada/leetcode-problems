class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue < pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> q;

        q.push({0, {0, 0}});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        int drow[] = {-1,0, 0, 1};
        int dcol[] = {0, -1, 1, 0};


        while (!q.empty()) {
            auto diff = q.top().first;
            auto row = q.top().second.first;
            auto col = q.top().second.second;
            q.pop();

            if(row == n - 1 && col == m - 1){
                return diff;
            }

            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int neweffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);

                    if(neweffort < dist[nrow][ncol]){
                        q.push({neweffort,{nrow, ncol}});
                        dist[nrow][ncol] = neweffort;
                    }
                }
            }
        }
        return 0;
    }
};