class Solution {
public:
void solve(vector<int>&nums,int n, vector<int>&temp)
{
     vector<int>dp(n+1),hash(n);
        int ind=0;
        int maxi=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                ind=i;
            }
        }

        temp.push_back(nums[ind]);
        while(hash[ind]!=ind)
        {
            ind=hash[ind];
            temp.push_back(nums[ind]);
        }
}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       
int n=nums.size();
vector<int>temp;
solve(nums,n,temp);
return temp;

    }
};