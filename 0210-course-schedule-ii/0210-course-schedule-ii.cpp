class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>courses;
        unordered_map<int,int>indegree;
        if(n<=0) return {};
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<n;i++)
        {
            indegree[i]=0;
            graph[i]={};
        }

        for(int i=0;i<pre.size();i++)
        {
            int child=pre[i][0];
            int par=pre[i][1];
            graph[par].push_back(child);
            indegree[child]+=1;
        }

        queue<int>sources;
        for(auto it=indegree.begin();it!=indegree.end();it++)
        {
            if(it->second==0)
            {
                sources.push(it->first);
            }
        }
        while(!sources.empty())
        {
            int v=sources.front();
            sources.pop();
            courses.push_back(v);
            vector<int>c=graph[v];
            for(int ch: c)
            {
                indegree[ch]=indegree[ch]-1;
                if(indegree[ch]==0)
                {
                    sources.push(ch);
                }
            }
        }
        if(courses.size()!=n) courses.clear();
        return courses;
    }
};