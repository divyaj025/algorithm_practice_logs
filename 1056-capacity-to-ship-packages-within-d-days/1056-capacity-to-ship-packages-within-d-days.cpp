class Solution {
public:  bool check(int capacity, int days, vector<int>& weights){
        int n = weights.size();
        int c = capacity;
        int dayCount = 1;
        for(int i=0; i<n;i++){
            if(c>=weights[i]){
                c = c - weights[i];
            }
            else{
                dayCount++; // next day start
                c = capacity;
                c -= weights[i];
            }
        }
        if(dayCount<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
         int sum = 0, max = weights[0];
        for(int i=0; i<n; i++){
            sum += weights[i];
            if(weights[i]>max) max = weights[i];
        }

        int lo = max, hi = sum;
        int mincapacity = sum;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,days,weights)){
                mincapacity = mid;
                hi = mid - 1;
            }
             else lo = mid + 1;
        }
        return mincapacity;
    }
};