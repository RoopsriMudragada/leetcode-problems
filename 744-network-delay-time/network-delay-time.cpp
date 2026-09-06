class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n + 1);
        for(auto it : times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

        q.push({0, k});

        while(!q.empty()){
            auto [d, node] = q.top();
            q.pop();

            if(d > dist[node]) continue;

            for(auto it : adj[node]){
                int nbr = it.first;
                int wt = it.second;

                if(dist[node] + wt < dist[nbr]){
                    dist[nbr] = dist[node] + wt;
                    q.push({dist[nbr], nbr});
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            else{
                maxi = max(maxi, dist[i]);
            }
        }
        return maxi;
    }
};