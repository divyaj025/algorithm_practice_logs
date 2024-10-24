class Solution {
public:

    int help(int i, int j, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int maxcoins=INT_MIN;

        for(int k=i;k<=j;k++)
        {
            int coins=(nums[i-1]*nums[k]*nums[j+1])+help(i,k-1,nums,dp)+help(k+1,j,nums,dp);

            maxcoins=max(maxcoins,coins);
        }

       return dp[i][j]=maxcoins;
    }
    int maxCoins(vector<int>& nums) {
         ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));

       return help(1,n,nums,dp);
    }
};