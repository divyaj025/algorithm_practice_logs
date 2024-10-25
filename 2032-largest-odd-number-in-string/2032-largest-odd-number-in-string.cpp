class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        string ans="";
        for(int i=n-1;i>=0;i--)
        {
            int check=int(num[i]);
            if(check%2!=0)
            {
                ans=num.substr(0,i+1);
                break;
            }
        }

        return ans;
    }
};