class Solution {
public:
    void help(int col, vector<string>&board, vector<vector<string>>&ans,int n, vector<int>&lr,vector<int>&uc,vector<int>&lc)
    {
        if(col>=n)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++)
        {
            if(lr[row]==0 && uc[n-1+col-row]==0 && lc[row+col]==0)
            {
                board[row][col]='Q';
                lr[row]=1;
                uc[n-1+col-row]=1;
                lc[row+col]=1;
                help(col+1,board,ans,n,lr,uc,lc);
                board[row][col]='.';
                lr[row]=0;
                uc[n-1+col-row]=0;
                lc[row+col]=0;
            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>ans;
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>lr(n,0);
        vector<int>uc(2*n-1,0);
        vector<int>lc(2*n-1,0);
        help(0,board,ans,n,lr,uc,lc);
        return ans;
    }
};