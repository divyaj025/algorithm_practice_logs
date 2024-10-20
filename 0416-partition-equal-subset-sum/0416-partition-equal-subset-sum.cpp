class Solution {
public:
    bool help(vector<int>&nums,vector<vector<int>>&dp,int sum, int i)
    {
        if(sum==0) return true;
        if(sum<0 || i<0) return false;
        if (i == 0) return sum == 0 || nums[0] == sum;
        if(dp[sum][i]!=-1) return dp[sum][i];
        bool t1=help(nums,dp,sum,i-1);
        bool t2=false;
        if(nums[i]<=sum)
        {
            t2=help(nums,dp,sum-nums[i],i-1);
        }

        return dp[sum][i]=t1||t2;
    }
    bool canPartition(vector<int>& nums) 
    {
        int n=nums.size();
        int addy=0;
        for(int i=0;i<n;i++)
        {
            addy+=nums[i];
        }

        if(addy%2==1) return false;
        else{
            int k=addy/2;
            vector<vector<int>>dp(k+1,vector<int>(n,-1));
            return help(nums,dp,k,n-1);
        }
    }
};