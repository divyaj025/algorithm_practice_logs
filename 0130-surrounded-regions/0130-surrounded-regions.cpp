class Solution {
public:
    void dfs(int i,int j, vector<vector<bool>>&vis, vector<vector<char>>&board)
    {
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        vis[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx<0 || ny<0 || nx>=board.size() || ny>=board[0].size()) continue;
            if(vis[nx][ny]==0 && board[nx][ny]=='O')
            {
                dfs(nx,ny,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O' && vis[0][i]==0)
            {
                dfs(0,i,vis,board);
            }

            if(board[n-1][i]=='O' && vis[n-1][i]==0)
            {
                dfs(n-1,i,vis,board);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0)
            {
                dfs(i,0,vis,board);
            }

            if(board[i][m-1]=='O' && vis[i][m-1]==0)
            {
                dfs(i,m-1,vis,board);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
    }
};