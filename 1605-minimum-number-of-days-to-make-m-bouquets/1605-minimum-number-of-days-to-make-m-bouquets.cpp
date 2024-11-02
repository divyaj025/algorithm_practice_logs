class Solution {
public:
 bool isGoodProp(int propDay, vector<int>& bloomDay, int k, int bqReq){
        int bqCnt = 0, flwrCnt = 0;
        for(auto day : bloomDay){
            if(day <= propDay){
                flwrCnt++;
            }else{
                flwrCnt = 0;
            }
            if(flwrCnt == k){
                flwrCnt = 0;
                bqCnt++;
            }
        }
        return bqCnt >= bqReq;
    }
  int minDays(vector<int>& bloomDay, int m, int k) {
         int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        int left = 0, right = maxDay, minDay = -1;
        while(left <= right){
            int propDay = left + (right - left)/2;
            if(isGoodProp(propDay, bloomDay, k, m)){
                minDay = propDay;
                right = propDay - 1;
            }else{
                left = propDay + 1;
            }
        }
        return minDay;
    }
};