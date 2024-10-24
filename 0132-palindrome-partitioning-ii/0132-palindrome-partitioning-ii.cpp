class Solution {
public:

bool check(int i,int j, string &s)
{
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    int help(int i, int n, string &s, vector<int>&dp)
    {
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mcus=INT_MAX;

        for(int k=i;k<n;k++)
        {
            if(check(i,k,s))
            {
                int cost=1+help(k+1,n,s,dp);
                mcus=min(cost,mcus);
            }
        }

        return dp[i]=mcus;
    }
    int minCut(string s) {
        int n = s.size();
    vector<int> dp(n, -1);
     return help(0, n, s, dp) -1;
    }
};