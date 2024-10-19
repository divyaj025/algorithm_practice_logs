class Solution {
public:
int arr[48];
int help(int n, int x)
{
    if(x==n) return 1;
    if(x>n) return 0;
    if(arr[x]!=-1) return arr[x];
    int t1=help(n,x+1);
    int t2=help(n,x+2);
    
    return arr[x]=t1+t2;
}
    int climbStairs(int n) {
        memset(arr,-1,sizeof(arr));
        int ans=help(n,0);
        return ans;
    }
};