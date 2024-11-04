class Solution {
public:
    int countPartitions(vector<int> &nums, int mid) {
        int n=nums.size();
         int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + nums[i] <= mid) {
            
            subarraySum += nums[i];
        }
        else {
            
            partitions++;
            subarraySum = nums[i];
        }
    }
    return partitions;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartitions(nums, mid);
        if (partitions > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
    }
};