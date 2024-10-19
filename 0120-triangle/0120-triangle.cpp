class Solution {
public:
    int help(int m,int n, vector<vector<int>>& triangle, vector<vector<int>>&dp)
    {
        if(m==0 && n==0) return triangle[0][0];
        if(m<0 || n<0 || n >= triangle[m].size()) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        int t1=help(m-1,n,triangle,dp);
        int t2=help(m-1,n-1,triangle,dp);
        return dp[m][n]=triangle[m][n]+min(t1,t2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        int minpath = INT_MAX;
        for(int i=0;i<triangle[m-1].size();i++)
        {
            minpath=min(minpath,help(m-1,i,triangle,dp));
        }
        return minpath;
    }
};