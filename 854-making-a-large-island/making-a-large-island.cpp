class Solution {
public:
    int n;
    vector<vector<int>> direc{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis,
            int id) {
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] ||
            grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = id;
        vis[i][j] = true;
        int size = 1;

        for (auto dir : direc) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            size += dfs(grid, i_, j_, vis, id);
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        int unqid = 2;
        int maxarea = 0;
        unordered_map<int, int>mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int size = dfs(grid, i, j, vis, unqid);
                    maxarea = max(maxarea, size);

                    mp[unqid] = size;
                    unqid++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int>unqids;
                    for(auto & dir : direc){
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];

                        if(i_ >= 0 && i_ < n && j_ >=0 && j_ < n && grid[i_][j_] != 0){
                            unqids.insert(grid[i_][j_]);
                        }
                    }
                    int overallsize = 1;
                    for(auto it : unqids){
                        overallsize += mp[it];
                    }
                    maxarea = max(maxarea, overallsize);
                }
            }
        }
        return maxarea == 0 ? (n * n) : maxarea;
    }
};