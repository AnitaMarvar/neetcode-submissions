class Solution {
public:
vector<vector<int>>dir = {{-1,0},{0,-1},{1,0},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
       int fresh = 0;

       queue<pair<int,int>>q;  //coordinates

       for(int i=0;i<grid.size();i++)
       {
        for(int j = 0;j<grid[0].size();j++)
        {
            if(grid[i][j]==2)
            {
                q.push({i,j});
            }
            else if(grid[i][j]==1)
            {
                fresh++;
            }
        }
       } 

       if(fresh==0)return 0;
       int ans=0;
       while(!q.empty())
       {
        int sz = q.size();
        ans++;
        while(sz--){
             int x = q.front().first;
             int y = q.front().second;
             q.pop();

             for(auto it : dir)
             {
                int Nx = x + it[0];
                int Ny = y + it[1];

                if(Nx < 0 || Ny <0 || Nx >= grid.size() || grid[0].size() <= Ny || grid[Nx][Ny]==0)
                {
                    continue;
                }
                if(grid[Nx][Ny]==1)
                {
                    grid[Nx][Ny]=2;
                    q.push({Nx, Ny});
                    fresh--;
                }
             }
        }
       }
       if(fresh!=0)return -1;
       return ans-1;
    }
};
