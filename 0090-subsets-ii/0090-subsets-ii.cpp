class Solution {
public:

    void help(vector<int>&nums,vector<int>&res, vector<vector<int>>&ans, int i)
    {
         ans.push_back(res);
        for(int j=i;j<nums.size();j++)
        {
            if(j!=i && nums[j]==nums[j-1]) continue;
            res.push_back(nums[j]);
            help(nums,res,ans,j+1);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        vector<vector<int>>ans;
        help(nums,res,ans,0);
        return ans;
    }
};