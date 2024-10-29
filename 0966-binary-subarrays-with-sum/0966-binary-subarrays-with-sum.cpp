class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       /* if(goal<0) return 0;
        int n=nums.size();
        int l=0,r=0,sums=0,maxi=0;
        while(r<n)
        {
            sums+=nums[r];
            while(sums>goal)
            {
                sums-=nums[l];
                l++;
            }
            maxi=maxi+(r-l+1);
            r++;
        }
        return maxi;*/
         unordered_map<int,int> mpp;

        int sum = 0;

        int cnt = 0;

        for(auto i:nums)
        {
            sum+=i;

            if(sum==goal) cnt++;

            if(mpp.find(sum-goal)!=mpp.end())
            {
                cnt+=mpp[sum-goal];
            }

            mpp[sum]++;
        }

        return cnt;


    }
};