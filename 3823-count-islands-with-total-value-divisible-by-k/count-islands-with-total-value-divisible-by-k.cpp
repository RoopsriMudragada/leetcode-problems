class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        vector<vector<int>>vis(n, vector<int>(m, false));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    long long compcnt = grid[i][j];
                    vis[i][j] = true;

                    while(!q.empty()){
                        auto [row, col] = q.front();
                        q.pop();

                        for(int d = 0; d < 4; d++){
                            int nr = row + dx[d];
                            int nc = col + dy[d];

                            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] > 0 && !vis[nr][nc]){
                                q.push({nr, nc});
                                compcnt += grid[nr][nc];
                                vis[nr][nc] = true;
                            }
                        }
                    }
                    if((compcnt % k) == 0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};