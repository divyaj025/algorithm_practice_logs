class Solution {
public:
    void dfs (int s,vector<vector<int>>&list,vector<bool>&vis)
    {
        vis[s]=1;
        for(auto it: list[s])
        {
            if(vis[it]==0)
            {
                dfs(it,list,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n =mat.size();
        vector<vector<int>>list(n);
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1 && i!=j)
                {
                    list[i].push_back(j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                cnt++;
                dfs(i,list,vis);
            }
        }
        return cnt;
    }
};