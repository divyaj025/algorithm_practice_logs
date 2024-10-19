class Solution {
public:
    int help(int m, int n, vector<vector<int>>&dp)
    {
        if(m==0 && n==0) return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int t1=help(m-1,n,dp);
        int t2=help(m,n-1,dp);
        return dp[m][n]=t1+t2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=help(m-1,n-1,dp);
        return ans;
    }
};