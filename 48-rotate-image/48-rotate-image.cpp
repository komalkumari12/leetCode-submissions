class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*Approach
         step 1. transpose of a matrix
         step 2. reverse the matrix
         */
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<i ;j++){
                swap(matrix[i][j], matrix[j][i]) ;
            }
        }
        
        for(int i=0; i<matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end()) ;
        }
    }
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         