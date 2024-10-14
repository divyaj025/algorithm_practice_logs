class Solution {
public:
    void dfs(int i,int j, vector<vector<int>>&grid, vector<vector<bool>>&vis)
    {
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];

            if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size()) continue;
            if(grid[nx][ny]==1 && vis[nx][ny]!=1)
            {
                dfs(nx,ny,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 && vis[0][i]==0)
            {
                dfs(0,i,grid,vis);
            }
            if(grid[n-1][i]==1 && vis[n-1][i]==0)
            {
                dfs(n-1,i,grid,vis);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 && vis[i][0]==0)
            {
               dfs(i,0,grid,vis); 
            }
            if(grid[i][m-1]==1 && vis[i][m-1]==0)
            {
                dfs(i,m-1,grid,vis);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};