class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int count=0;
        int ocount=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') count++;
            else if(s[i]=')')
            {
                if(count>0)
                {
                    count--;
                }
                else ocount++;
            }
        }

        return ocount+count;
    }
};