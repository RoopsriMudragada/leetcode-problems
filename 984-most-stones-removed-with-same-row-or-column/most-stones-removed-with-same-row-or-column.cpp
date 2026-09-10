class DSU{
public:
    vector<int>parent, rank;

    DSU(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }

    void unite(int u, int v){
        int up_u = findUpar(u);
        int up_v = findUpar(v);

        if(rank[up_u] < rank[up_v]){
            parent[up_u] = up_v;
        }
        else if(rank[up_v] < rank[up_u]){
            parent[up_v] = up_u;
        }
        else{
            parent[up_v] = up_u;
            rank[up_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(n);

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    dsu.unite(i, j);
                }
            }
        }

        int groups = 0;
        for(int i = 0; i < n; i++){
            if(dsu.findUpar(i) == i){
                groups++;
            }
        }
        return n - groups;
    }
};