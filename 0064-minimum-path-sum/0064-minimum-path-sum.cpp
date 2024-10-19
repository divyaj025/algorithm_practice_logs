class Solution {
public:
    int help(int m, int n, vector<vector<int>>&dp, vector<vector<int>>&grid)
    {
        if(m==0 && n==0) return grid[0][0];
        if(m<0 || n<0) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        int t1=help(m-1,n,dp,grid);
        int t2=help(m,n-1,dp,grid);
        return dp[m][n]=grid[m][n]+min(t1,t2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=help(m-1,n-1,dp,grid);
        return ans;
    }
};