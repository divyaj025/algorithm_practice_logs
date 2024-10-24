class Solution {
public:
    int help(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int c=i;c<=j;c++)
        {
             int ans = cuts[j + 1] - cuts[i - 1] +
                  help(i, c - 1, cuts, dp) +
                  help(c + 1, j, cuts, dp);

        mini = min(mini, ans);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
int c= cuts.size()-2;
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
     return help(1, c, cuts, dp);
    }
};