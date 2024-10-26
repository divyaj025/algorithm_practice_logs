class Solution {
public:
  string func(string& ans) {
        int ct = 1;
        string res;
        for (int i = 0; i < ans.size(); i++) {
            if (i + 1 < ans.size() && ans[i] == ans[i + 1]) {
                ct++;
            } else {                
                res +=to_string(ct) + ans[i];
                ct = 1;
            }
        }
        return res;
    }
    string countAndSay(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        string ans = "1";
        
        for (int i = 1; i <n; i++) {
           ans = func(ans);
        }
        return ans;
    }
};