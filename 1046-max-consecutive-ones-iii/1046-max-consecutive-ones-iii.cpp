class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi=0,l=0,zeroes=0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]==0) zeroes++;

            if(zeroes>k)
            {
                if(nums[l++]==0) zeroes--;
                
            }
            else maxi=max(maxi,r-l+1);
        }

        return maxi;

        
    }
};