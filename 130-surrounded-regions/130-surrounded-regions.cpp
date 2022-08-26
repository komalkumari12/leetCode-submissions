class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != 'O')
            return  ;
        
        board[i][j] = 'A' ;
        
        dfs(i+1, j, board) ;
        dfs(i-1, j, board) ;
        dfs(i, j+1, board) ;
        dfs(i, j-1, board) ;
    }
        
    void fun(int i, int j, vector<vector<char>>& board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == 'X')
            return  ;
        
        board[i][j] = 'X' ;
        
        fun(i+1, j, board) ;
        fun(i-1, j, board) ;
        fun(i, j+1, board) ;
        fun(i, j-1, board) ;
    }
        
    void solve(vector<vector<char>>& board) {
        int n = board.size() ;
        int m = board[0].size() ;
        
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O')
                dfs(i, 0, board) ;
            if(board[i][m-1] == 'O')
                dfs(i, m-1, board) ;
        }
        
        for(int i=0; i<m ;i++){
            if(board[0][i] == 'O')
                dfs(0, i, board) ;
            if(board[n-1][i] == 'O')
               dfs(n-1, i, board) ;
        }
  
        //print
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<board[i][j]<<" " ;
            }
            cout<<endl ;
        }  
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O')
                    fun(i, j, board) ;
            }
        }
        
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'A')
                    board[i][j] = 'O' ;
            }
        }
    }
};