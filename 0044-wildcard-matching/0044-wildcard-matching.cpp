class Solution {
public:
bool isAllStars(string &S1, int i) {
    for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
            return false;
    }
    return true;
}
bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp) {
   
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return isAllStars(S1, i);

  
    if (dp[i][j] != -1)
        return dp[i][j];

    
    if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
    else {
        if (S1[i] == '*')
            
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else
            return false;
    }
}

    bool isMatch(string S1, string S2) {
       int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return wildcardMatchingUtil(S2, S1, m - 1, n - 1, dp);
    }
};