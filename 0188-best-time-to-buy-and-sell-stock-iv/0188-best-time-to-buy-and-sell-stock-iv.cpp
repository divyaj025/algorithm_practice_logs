class Solution {
public:
    int help(int k,vector<int>&prices,int i,int buy, vector<vector<vector<int>>>&dp)
    {
        int n=prices.size();
        if(i==n || k==0) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int profit;
        if(buy==0)
        {
            profit=max(help(k,prices,i+1,0,dp),-prices[i]+help(k,prices,i+1,1,dp));
        }

        else if(buy==1)
        {
            profit=max(help(k,prices,i+1,1,dp),prices[i]+help(k-1,prices,i+1,0,dp));
        }

        return dp[i][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return help(k,prices,0,0,dp);
    }
};