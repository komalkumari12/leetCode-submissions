// hashing

class Solution {
public:
    void find(int col ,int n ,vector<string>&board ,vector<vector<string>>&ans, vector<int>&leftRow, vector<int>&upperDiag, vector<int>&lowerDiag){
        if(col == n){
            ans.push_back(board) ;
            return ;
        }
        
        for(int row=0; row<n ; row++){
            if(leftRow[row]==0  &&  upperDiag[n-1 + col-row]==0  &&  lowerDiag[col+row]==0){
                board[row][col] = 'Q' ;
                leftRow[row] ='Q' ;
                upperDiag[n-1 + col-row] = 'Q' ;
                lowerDiag[col + row] = 'Q' ;
                
                find(col+1 ,n , board, ans ,leftRow, upperDiag, lowerDiag) ;
                
                board[row][col] = '.' ;
                leftRow[row] = 0 ;
                upperDiag[n-1 + col-row] = 0 ;
                lowerDiag[col + row] = 0 ;
            }
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ;
        vector<string>board(n) ;
        string s(n, '.') ;
        
        for(int i=0 ; i<n ;i++)
            board[i] = s;
        
        vector<int>leftRow(n, 0) ;
        vector<int>upperDiag(2*n-1  ,0);
        vector<int>lowerDiag(2*n -1, 0) ;
        
        find(0, n, board ,ans ,leftRow, upperDiag, lowerDiag) ;
        
        return ans ;
    }
};