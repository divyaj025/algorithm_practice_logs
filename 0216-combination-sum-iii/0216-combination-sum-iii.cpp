class Solution {
public:

    void help(int k, int arr[], int sum,vector<int>&res, set<vector<int>> &ans, int i )
    {
       if(res.size()>k || sum<0) return;
        if(res.size()==k && sum==0)
        {ans.insert(res);}
         if(i>=9) return;

        res.push_back(arr[i]);
        help(k,arr,sum-arr[i],res,ans,i+1);

        res.pop_back();
        help(k,arr,sum,res,ans,i+1);
    }
    vector<vector<int>> combinationSum3(int k, int sum) {
        int arr[9]={1,2,3,4,5,6,7,8,9};
        vector<int>res;
        set<vector<int>>ans;
        help(k,arr,sum,res,ans,0);
        vector<vector<int>>ans1(ans.begin(),ans.end());
        return ans1;
    }
};