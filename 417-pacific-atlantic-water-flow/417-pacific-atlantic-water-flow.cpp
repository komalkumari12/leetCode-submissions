class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& heights, bool& atlantic, bool&  pacific, int prev){
        if(i<0 || j<0){
            pacific = true ;
            return ;
        }
        if(i>=heights.size() || j>=heights[0].size()){
            atlantic = true ;
            return ;
        }
        
        if(prev < heights[i][j])    return ;
        if(atlantic && pacific)   return  ;
        
        int num = heights[i][j] ;
        heights[i][j] = INT_MAX ;
        
        solve(i+1, j, heights, atlantic, pacific, num) ;
        solve(i, j+1, heights, atlantic, pacific, num) ;
        solve(i-1, j, heights, atlantic, pacific, num) ;
        solve(i, j-1, heights, atlantic, pacific, num) ;   
        
        heights[i][j] = num ;
    }
        
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m= heights[0].size() ;
        vector<vector<int>> ans ;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                vector<int> v ;
                bool atlantic = false ;
                bool pacific = false ;
                int prev = INT_MAX ;
                
                solve(i, j, heights, atlantic, pacific, prev) ;
                if(atlantic && pacific){
                    v.push_back(i) ;
                    v.push_back(j) ;
                    ans.push_back(v) ;
                }
            }
        }
        
        return ans ;
    }
};