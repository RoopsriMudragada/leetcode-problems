class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, false));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int cnt = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 0 && !vis[row][col]) {
                    queue<pair<int, int>> q;
                    q.push({row, col});
                    vis[row][col] = true;

                    bool closed = true;

                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();

                        if (row == 0 || row == n - 1 || col == 0 ||
                            col == m - 1) {
                            closed = false;
                        }

                        for (int d = 0; d < 4; d++) {
                            int nr = row + dx[d];
                            int nc = col + dy[d];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                grid[nr][nc] == 0 && !vis[nr][nc]) {
                                vis[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                    if (closed) {
                        cnt++;
                    }
                };
            }
        }
        return cnt;
    }
};