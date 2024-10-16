class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();

        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        int dis=1;
        int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
        int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1};
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                if(row==n-1 && col==m-1) return dis;
                for(int i=0;i<8;i++)
                {
                    int nx=row+dx[i];
                    int ny=col+dy[i];

                    if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0 && grid[nx][ny]==0)
                    {
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
             

            }
               dis++;
        }
return -1;
    }
};