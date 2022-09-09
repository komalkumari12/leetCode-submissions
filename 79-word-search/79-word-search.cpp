class Solution {
public:
    bool searchWord(int i, int j, int ind, string word, vector<vector<char>>& board){
        if(i>=board.size() || j>=board[0].size() || i<0 || j<0 || board[i][j] != word[ind])
            return false ;
        
        if(ind == word.size()-1)    return true ;
        char ch = board[i][j] ;
        board[i][j] = '1' ;
        
        bool ans = searchWord(i+1, j, ind+1, word, board) || searchWord(i-1, j, ind+1, word, board) || searchWord(i, j+1, ind+1, word, board) || searchWord(i, j-1, ind+1, word, board) ;
        
        board[i][j] = ch ;
        
        return ans ;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size() ;
        
        for(int i=0; i<n ;i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0])
                    if(searchWord(i, j ,0, word, board))
                        return true ;
            }
        }
        
        return false ;
    }
};