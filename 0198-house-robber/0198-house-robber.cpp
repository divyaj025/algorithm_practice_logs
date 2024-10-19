class Solution {
public:
int arr[555];
int help(vector<int>&nums,int i)
{
     if(i<0) return 0;
    if(arr[i]!=-1) return arr[i];
    if(i==0) return nums[i];
    int t1=nums[i]+help(nums,i-2);
    int t2=help(nums,i-1);
    return arr[i]=max(t1,t2);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(arr,-1,sizeof(arr));
        int ans=help(nums,n-1);
        return ans;
    }
};