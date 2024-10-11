class Solution {
public:
    void help(string &digits, int i, string &si, vector<string>&ans,vector<string>&s)
    {   
        if(i>=digits.size())
        {
            ans.push_back(si);
            return;
        }
        string curr=s[digits[i]-'0'];
        for(int j=0;j<curr.size();j++)
        {
            si.push_back(curr[j]);
            help(digits,i+1,si,ans,s);
            si.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
        {
            return {};
        }
        vector<string>s={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string si;
        vector<string>ans;
        help(digits,0,si,ans,s);
        return ans;
    }
};