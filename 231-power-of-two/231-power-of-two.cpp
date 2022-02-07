// TC : O(1)
//Approach  AND of n and n-1 will be 0 if n is power of two

class Solution {
public:
    bool isPowerOfTwo(int n){
        return ( n>0  && !(n& (n-1))) ;
    }
};

