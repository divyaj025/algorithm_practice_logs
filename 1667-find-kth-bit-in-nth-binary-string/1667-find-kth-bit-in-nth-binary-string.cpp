class Solution {
public:
    char findKthBit(int n, int k) {
        
        return findBit(n, k);
    }

    char findBit(int n, int k) {
       
        if (n == 1) return '0';
        
        
        int length = (1 << n) - 1;  
        
       
        int mid = length / 2 + 1;
        
        if (k == mid) {
           
            return '1';
        } else if (k < mid) {
            
            return findBit(n - 1, k);
        } else {
           
            return invert(findBit(n - 1, length - k + 1));
        }
    }
    char invert(char bit) {
        return bit == '0' ? '1' : '0';
    }
};