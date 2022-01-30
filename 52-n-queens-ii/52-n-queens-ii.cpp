class Solution {
public:
    int count=0 ;
    
    bool check(int row, int col, int n ,vector<string>&board){
        int temp_row=row ;
        int temp_col=col ;
        
        while(row>=0  &&  col>=0){
            if(board[row][col]=='Q')
                return false;
            col--;
            row--;
        }
        
        row=temp_row ;
        col=temp_col ;
        while(col>=0){
            if(board[row][col]=='Q')
                return false ;
            col--;
        }
        
        row=temp_row ;
        col=temp_col ;
        while(row<n  &&  col>=0){
            if(board[row][col]=='Q')
                return false ;
            row++;
            col-- ;
        }
        return true ;
    }
    
    void solve(int col ,int n, vector<string>&board){
        if(col==n){
            count++ ;
            return ;
        }
        
        for(int row= 0 ; row< n; row++){
            if(check(row,col ,n,board)){
                board[row][col]='Q' ;
                solve(col+1,n ,board) ;
                board[row][col]='.' ;
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n) ;
        string s(n,'.') ;
        
        solve(0, n ,board) ;
        
        return count ;
    }
};