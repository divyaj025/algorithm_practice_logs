class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string p="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') 
            {
                if(count>0) p+=s[i];
                count++;
            }
            else if(s[i]==')')
            {
                count--;
                if(count>0)
                {
                    p+=s[i];
                }
            }
        }
        return p;
    }
};