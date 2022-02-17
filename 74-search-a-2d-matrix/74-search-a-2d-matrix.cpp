class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n= mat.size();
        int m=mat[0].size() ;
        
        int i=0;
        int j=m-1 ;
        
        while(i<n && j>=0){
            if(target == mat[i][j]) return true ;
            else if(target < mat[i][j]) j=j-1 ;
            else if(target > mat[i][j]) i=i+1 ;
        }
        
        return false ;
    }
};