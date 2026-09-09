class DSU {
public:
    vector<int>parent, rank;
    DSU(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for(int i = 0;i < n; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(parent[node] == node){
            return parent[node]; //
        }
        return parent[node] = findUpar(parent[node]);
    }

    void unite(int u, int v){
        int up_u = findUpar(u);
        int up_v = findUpar(v);

        if(rank[up_u < rank[up_v]]){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);

        if(connections.size() < n - 1){
            return -1;
        }

        for(auto it : connections){
            dsu.unite(it[0], it[1]);
        }

        unordered_set<int>components;
        for(int i = 0; i < n; i++){
            components.insert(dsu.findUpar(i));
        }

        return components.size() - 1;

    }
};