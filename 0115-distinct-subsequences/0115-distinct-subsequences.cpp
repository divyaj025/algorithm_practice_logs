class Solution {
public:
const int prime = 1e9 + 7;
/*int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
        int result = 0;
         if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) % prime;
    } else {  result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }
    dp[ind1][ind2] = (result)%prime;
    return result;
}*/
    int numDistinct(string s1, string s2) {
        int n = s1.size();
    int m = s2.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
     for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % prime;
            } else {
              
                dp[i][j] = dp[i-1][j] % prime;
            }
        }
    }

    return dp[n][m];
    }
};