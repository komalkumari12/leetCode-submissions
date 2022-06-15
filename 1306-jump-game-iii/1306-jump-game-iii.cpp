class Solution {
public:
    bool solve(int ind, vector<int>& arr){
        if(arr[ind] == -1) return false ;
        if(arr[ind] == 0) return true ;
        
        int left = ind - arr[ind];
        int right = ind + arr[ind] ;
        
        arr[ind] = -1 ;
        
        return (left >= 0 && solve(left, arr)) || (right < arr.size() && solve(right, arr)) ;
    }
        
    bool canReach(vector<int>& arr, int start) {
        return solve(start, arr) ;
    }
};
