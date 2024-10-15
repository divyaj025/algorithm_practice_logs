class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<int> indegree(n, 0);
        for(auto it:pre)
        {
            adj[it[0]].push_back(it[1]);
             indegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
           if(indegree[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            ans.push_back(v);
            for(auto it:adj[v])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        if(ans.size()==n) return true;
        else return false;
    }
};