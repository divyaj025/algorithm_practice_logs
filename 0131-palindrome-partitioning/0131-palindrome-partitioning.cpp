class Solution {
public:
    bool ispalindorme(string &s, int i, int j)
    {
        while(i<j)
        {
           if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void help(string &s, int i, vector<string>&res, vector<vector<string>>&ans)
    {
        if(i==s.size())
        {
            ans.push_back(res);
            return;
        }
        for(int j=i;j<s.size();++j)
        {
            if (ispalindorme(s,i,j))
            {
                res.push_back(s.substr(i,j-i+1));
                help(s,j+1,res,ans);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>res;
        vector<vector<string>>ans;
        help(s,0,res,ans);
        return ans;
    }
};