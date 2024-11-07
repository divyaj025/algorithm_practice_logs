class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high)
        {
            int maxr=0;
            int mid=(low+high)>>1;
            for(int row=0;row<n;row++)
            {
                if(mat[row][mid]>mat[maxr][mid]) maxr=row;
            }
            int left=-1,right=-1;
            if(mid-1>0){
                left=mat[maxr][mid-1];
            }

            if(mid+1<m){
                right=mat[maxr][mid+1];
            }
            if(mat[maxr][mid]>left && mat[maxr][mid]>right) return {maxr,mid};
            else if(mat[maxr][mid]>right) high=mid-1;
            else low=mid+1;

        }

        return {-1,-1};
    }

};