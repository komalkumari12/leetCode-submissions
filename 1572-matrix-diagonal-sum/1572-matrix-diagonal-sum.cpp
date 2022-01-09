class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int primarySum=0,secondarySum;
        
        for(int i=0;i<mat.size();i++){
            primarySum+=mat[i][i] ;
            secondarySum+=mat[i][mat.size()-1-i] ;
        }
        //return secondarySum ;
        if(mat.size()%2==0)
            return primarySum +  secondarySum ;
        else
            return primarySum +  secondarySum - mat[(mat.size()-1)/2][(mat.size()-1)/2];
    }
};