class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        long long int ans=0;
        for(int i=0;i<k;i++)
        {
            ans+=pq.top();
            long long int m=pq.top();
            pq.pop();
            pq.push((m+2)/3);
        }
        return ans;
    }
};