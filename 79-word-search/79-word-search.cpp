class Solution {
public:
    string str ="" ;
    bool find(int ind, int i, int j, string word, vector<vector<char>>& board){
        if(ind == word.size()) return true ;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[ind]) return false ;
        
        char ch = board[i][j]  ;
        board[i][j] ='0' ;
        
        bool res =find(ind+1, i+1, j, word, board) ||
            find(ind+1, i-1, j, word, board) ||
            find(ind+1, i, j+1, word, board) ||
            find(ind+1, i, j-1, word, board) ;
        
        board[i][j]  = ch ;
        
        return res ;
    }
        
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() ;
        int m = board[0].size() ;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[0] == board[i][j]){
                    if(find(0, i, j, word, board)) return true ;
                }
            }
        }
        
        return false ;
    }
};