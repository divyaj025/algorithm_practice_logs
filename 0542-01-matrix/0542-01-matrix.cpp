class Solution {
public:
    vector<vector<int>>updateMatrix(vector<vector<int>>mat)
	{
         vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size()));
        vector<vector<bool>>vis(mat.size(),vector<bool>(mat[0].size(),false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={-1,1,0,0};
         while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            ans[a][b]=dis;
            for(int i=0;i<4;i++)
            {
                int nx=a+dx[i];
                int ny=b+dy[i];
                if(nx<0 || ny<0 || nx>=mat.size() || ny>=mat[0].size()) continue;
                if(vis[nx][ny]==0)
                {
                    vis[nx][ny]=1;
                    q.push({{nx,ny},dis+1});
                }
            }
         } 
         return ans;  
    }
};