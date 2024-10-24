class Solution {
public:
int dp[501];
    int f(int i,vector<int>&arr,int k,int n){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int tsum=0;
        int maxi=arr[i];
        int sum=0;
        for(int j=i;j<min(i+k,n);j++){
            maxi=max(maxi,arr[j]);
            tsum=maxi*(j-i+1);
            int rsum=f(j+1,arr,k,n);
            sum=max(sum,tsum+rsum);
        }
     return dp[i]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
         int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return f(0,arr,k,n);
    }
};