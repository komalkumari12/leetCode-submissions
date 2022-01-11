class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        //rotation by 90 degree
        for(int k=0; k<4 ; k++){
        for(int i =0; i <mat.size(); i++){
            for(int j=0 ; j<i ; j++){
                swap(mat[i][j], mat[j][i]) ;
            }
        }
            
            for(int i=0 ; i<mat.size(); i++){
                reverse(mat[i].begin(), mat[i].end()) ;
            }
            
            if(mat==target)
                return true ;
        }
            return false;
        }
    
};