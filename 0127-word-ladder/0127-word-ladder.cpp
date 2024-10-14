class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
        queue<pair<string,int>>q;
        unordered_set<string>s(wordlist.begin(),wordlist.end());
        q.push({beginword,1});
        s.erase(beginword);
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endword) return steps;
            for(int i=0;i<word.size();i++)
            {
                char ch=word[i];
                for(char it='a';it<='z';it++)
                {
                    word[i]=it;
                    if(s.find(word)!=s.end())
                    {
                        q.push({word,steps+1});
                        s.erase(word);
                    }
                }
                            word[i]=ch;
            }

        }
        return 0;
    }
};