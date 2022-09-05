class Solution {
public:
    string swappedStr(int i, int j, string str){
        swap(str[i], str[j]) ;
        return str ;
    }
        
    int slidingPuzzle(vector<vector<int>>& board) {
        string ans = "123450" ;
        string initial = "" ;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                initial += to_string(board[i][j]) ;
            }
        }
        
        vector<vector<int>> swappingInd ;
        swappingInd.push_back({1,3}) ;
        swappingInd.push_back({0,4,2}) ;
        swappingInd.push_back({1,5}) ;
        swappingInd.push_back({0,4}) ;
        swappingInd.push_back({1,3,5}) ;
        swappingInd.push_back({4,2}) ;
        
        queue<string> q ;
        q.push(initial) ;
        int level =0 ;
        set<string> vis ;
        
        while(!q.empty()){
            int size = q.size() ;
            
            for(int i=0; i<size; i++){
                string str = q.front() ;
                q.pop() ;
                
                if(str == ans)  return level ;
                
                int ind =-1 ;
                for(int i=0; i<str.size(); i++){
                    if(str[i] == '0'){
                        ind= i ;
                        break ;
                    }
                }
                
                for(auto it: swappingInd[ind]){
                    string swapStr = swappedStr(it, ind, str) ;
                    if(vis.find(swapStr) == vis.end()){
                        q.push(swapStr) ;
                        vis.insert(swapStr) ;
                    }
                }   
            }
            level++ ;   
        }
        
        return -1 ;
    }
};