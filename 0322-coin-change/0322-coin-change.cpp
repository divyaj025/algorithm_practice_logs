class Solution {
public:
    int help(vector<int>&coins, int amount, int i, vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(amount%coins[i]==0)
            {
                return amount/coins[i];
            }
            else return 1e9;
        }

        if(dp[i][amount]!=-1) return dp[i][amount];
        int t1=help(coins,amount,i-1,dp);
        int t2=1e9;
        if(coins[i]<=amount)
        {
            t2=1+help(coins,amount-coins[i],i,dp);
        }
        return dp[i][amount]=min(t1,t2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
         int ans=help(coins,amount,n-1,dp);
         if(ans >= 1e9)
        return -1;
    return ans;
    }
};