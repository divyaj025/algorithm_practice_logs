class Solution {
public:
int FirstOccurance(vector<int>& arr , int n , int k){
   int ans =-1;
  
    int start = 0;
    int End = n -1;
   int  mid = start + ( End - start )/ 2;
    while (start <= End){
        if (k ==  arr[mid]){
            ans = mid;
            End = mid -1;
        }
        else if (k > arr[mid]){
            start = mid +1;
        }
        else{
            End = mid -1;
        }
mid = start + ( End - start )/ 2;

    }
return ans ;
}
int LastOccurance(vector<int>& arr , int n , int k){
      int ans =-1;
    
    int start = 0;
    int End = n -1;
    int mid = start + ( End - start )/ 2;
    while (start <= End){
        if (k ==  arr[mid]){
            ans = mid;
        start = mid + 1;
        }
        else if (k > arr[mid]){
            start = mid +1;
        }
        else{
            End = mid -1;
        }
mid = start + ( End - start )/ 2;

    }
return ans ;


}
    vector<int> searchRange(vector<int>& nums, int target) {

int n = nums.size();
    
   int First   = FirstOccurance(nums , n ,target);
 int Last = LastOccurance(nums , n ,target);

   return {First , Last};

    }
};