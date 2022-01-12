class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int size=matrix.size() ;
        vector<vector<int>> ans(matrix[0].size(), vector<int>(matrix.size(), -1)) ;
        
        for(int i=0 ;i<size ; i++){
            for(int j=0; j<matrix[i].size() ;j++){
                ans[j][i]=matrix[i][j] ;
            }
        }
        
        return ans ;
    }
};
