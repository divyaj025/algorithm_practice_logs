class Solution {
public:

    bool dfs(int i,int color,vector<int>&col,vector<vector<int>>& graph)
    {
        col[i]=color;
        for(auto it:graph[i])
        {
            if(col[it]==-1)
            {
                if(!dfs(it,!color,col,graph)) return false;
            }
            else if(col[it]==color) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>col(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(col[i]==-1)
            {
                if(!dfs(i,0,col,graph)) return false;
            }
        }
        return true;
    }
};