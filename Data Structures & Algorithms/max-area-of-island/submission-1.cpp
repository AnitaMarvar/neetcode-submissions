class Solution {
public:
vector<vector<int>>dir = {{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int &cnt, vector<vector<int>>& grid, vector<vector<bool>>&vis,int i, int j)
    {
        vis[i][j] = true;
        cnt++;

        for(auto it : dir)
        {
            int Nx = it[0] + i;
            int Ny = it[1] + j;
            if(Nx < 0 || Ny < 0 || Nx >= grid.size() || Ny >= grid[0].size() || grid[Nx][Ny]==0)
            {
                continue;
            }
            if(!vis[Nx][Ny] && grid[Nx][Ny])
            {
                dfs(cnt, grid, vis, Nx, Ny);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,false));

        int maxi=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    int cnt=0;
                    dfs(cnt, grid, vis,i,j);
                    if(cnt > maxi)
                    {
                        maxi = cnt;
                    }
                }
            }
        }
        return maxi;
    }
};
