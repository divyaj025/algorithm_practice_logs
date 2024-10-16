class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,long long>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long>dis(n,1e18);
        vector<int>ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        ways[0]=1;
        dis[0]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            long long dist=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                int newn=it.first;
                long long newd=it.second;
                if(dist+newd<dis[newn])
                {
                    dis[newn]=dist+newd;
                    pq.push({dist+newd,newn});
                    ways[newn]=ways[node];
                }
                else if(dist+newd==dis[newn])
                {
                    ways[newn]=(ways[newn]+ways[node])%1000000007;
                }
            }
        }
        return (ways[n-1])%1000000007;
    }
};