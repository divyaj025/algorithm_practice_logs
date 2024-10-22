class Solution {
public:
    int help(vector<int>&prices,int buy, int i,long long n,vector<vector<int>>&dp)
    {
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit;
        if(buy==0)
        {
            profit=max(help(prices,0,i+1,n,dp),-prices[i]+help(prices,1,i+1,n,dp));
        }
        if(buy==1)
        {
            profit=max(help(prices,1,i+1,n,dp),prices[i]+help(prices,0,i+1,n,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<int>>dp(n,vector<int>(2,-1));
       return help(prices,0,0,n,dp);
    }
};