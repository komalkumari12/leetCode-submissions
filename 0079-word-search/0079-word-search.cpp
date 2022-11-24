class Solution {
public:
    bool wordSearch(int i, int j, int ind, int n, int m, string word, vector<vector<char>>& board){
        if(i<0 || j<0 || i>=n || j>=m || word[ind] != board[i][j])
            return false ;
    
        if(ind == word.size()-1)    return true ;
        char ch = board[i][j] ;
        board[i][j] = '0' ;
        
        bool ans = wordSearch(i+1, j, ind+1, n, m, word, board) || 
            wordSearch(i-1, j, ind+1, n, m, word, board) || 
            wordSearch(i, j+1, ind+1, n, m, word, board) || 
            wordSearch(i, j-1, ind+1, n, m, word, board) ;
        
        board[i][j] = ch ;
        
        return ans ;
    }
        
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() ;
        int m = board[0].size() ;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(wordSearch(i, j, 0, n, m, word, board))
                        return true ;
                }
            }
        }
        
        return false ;
    }
};