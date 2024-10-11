class Solution {
public:
    void solve(vector<int>&nums, int i, vector<int>&res, vector<vector<int>>&ans)
    {
        if(i==nums.size())
        {
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        solve(nums,i+1,res,ans);

        res.pop_back();
        solve(nums,i+1,res,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res;
        vector<vector<int>>ans;
        solve(nums,0,res,ans);
        return ans;
    }
};