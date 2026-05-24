class Solution {
public:
    vector<vector<int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<bool>>&vis, vector<vector<char>>& grid, int i, int j)
    {
        vis[i][j]=true;

        for(auto it : dir)
        {
            int Nx = it[0] + i;
            int Ny = it[1] + j;

            if(Nx < 0 || Ny < 0 || Nx >= grid.size() || Ny >= grid[0].size() || grid[Nx][Ny]=='0')
            {
                continue;
            }
            if(!vis[Nx][Ny] && grid[Nx][Ny]=='1')
            dfs(vis, grid, Nx, Ny);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    dfs(vis, grid, i, j);
                }
            }
        }
        return cnt;
    }
};
