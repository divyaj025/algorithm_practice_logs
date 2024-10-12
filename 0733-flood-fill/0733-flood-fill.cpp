class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        q.push({sr,sc});
        vector<vector<int>>ans=image;
        int initialColor = image[sr][sc];
    if (initialColor == color) return image;
    image[sr][sc]=color;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && image[nx][ny]==initialColor)
                {
                image[nx][ny]=color;
                q.push({nx,ny});
                }
            }
        }
        return image;
    }
};