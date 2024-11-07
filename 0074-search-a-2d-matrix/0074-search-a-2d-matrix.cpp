class Solution {
public:
    bool check(vector<vector<int>>& matrix,int target, int i)
    {
        int m=matrix[i].size();
        int low=0,high=m-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[i][mid]==target) return true;
            else if(matrix[i][mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        if(target>matrix[n-1][m-1] || target<matrix[0][0]) return false;
        for(int i=0;i<n;i++)
        {
            if(target==matrix[i][0] || target==matrix[i][m-1]) return true;
            else if(target>matrix[i][0] && target<matrix[i][m-1]) return check(matrix,target,i);
        }

        return false;
    }
};