class Solution {
public:
    string str ="" ;
    bool find(int ind, int i, int j, string word, vector<vector<char>>& board, vector<vector<bool>>& vis){
        if(ind == word.size()) return true ;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[ind]) return false ;
        if(vis[i][j] == true) return false ;
        
        vis[i][j] = true ;
        
        bool down =find(ind+1, i+1, j, word, board, vis) ;
        bool up =find(ind+1, i-1, j, word, board, vis) ;
        bool right =find(ind+1, i, j+1, word, board, vis) ;
        bool left =find(ind+1, i, j-1, word, board, vis) ;
        
        vis[i][j] =false ;
        
        return up || down || left || right ;
    }
        
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() ;
        int m = board[0].size() ;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[0] == board[i][j]){
                    vector<vector<bool>> vis(n, vector<bool>(m, false)) ;
                
                    if(find(0, i, j, word, board, vis)) return true ;
                }
            }
        }
        
        return false ;
    }
};