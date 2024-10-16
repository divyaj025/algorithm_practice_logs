class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        q.push({0,{0,0}});
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty())
        {
            int dist=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            if(x==n-1 && y==m-1) return dist;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m )
                {
                    int ndist=max(abs(heights[x][y]-heights[nx][ny]),dist);
                    if(ndist<dis[nx][ny])
                    {
                        dis[nx][ny]=ndist;
                        q.push({ndist,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};