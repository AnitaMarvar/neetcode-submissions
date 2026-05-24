class Solution {
public:
    void dfs(vector<bool>&vis, unordered_map<int, vector<int>>&adj, int node)
    {
        vis[node]=true;

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                dfs(vis, adj, it);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
       unordered_map<int, vector<int>>adj;

       for(auto edge : edges)
       {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       vector<bool>vis(n, false);

       int cnt=0;
       for(int i=0;i<n;i++)
       {
        if(!vis[i])
        {
            cnt++;
            dfs(vis, adj, i);
        }
       }
       return cnt;
    }
};
