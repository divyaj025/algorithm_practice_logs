class Solution {
public: 
vector<vector<vector<int>>>dp;
    int h(vector<int>& p, int i, int can_buy, int cool){
        if(i >= p.size())
        return 0;
        if(dp[i][can_buy][cool] != -1)
        return dp[i][can_buy][cool];
        int profit = h(p, i + 1, can_buy, 0);
        if(!cool){
            if(can_buy)
            profit = max(profit, -p[i] + h(p, i + 1, 0, 0));
            else
            profit = max(profit, p[i] + h(p, i + 1, 1, 1));
        }

        return dp[i][can_buy][cool] = profit;
    }
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<vector<int>>>(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return h(prices, 0, 1, 0);
    }
};