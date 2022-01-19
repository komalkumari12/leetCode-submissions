class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans( n , vector<int>(n) ) ;
        if(n < 2) return {{1}};
        
        int top = 0 , down = n-1 ;
        int left =0 , right = n-1 ;
        int val =1 ;
        
        while(top<=down && top<=right){
                for(int i=left; i<=right ;i++){
                    ans[top][i] = val++ ;
                }
                top++ ;
            
            
                for(int i=top ;i<=down ;i++){
                    ans[i][right] = val++ ;
                }
                right-- ;
            
            
                for(int i=right ;i>=left ;i--){
                    ans[down][i] = val++  ;
                }
                down-- ;
            
            
                for(int i=down ;i>=top ;i--){
                    ans[i][left] = val++  ;
                }
                left++ ;
        
        }
        return ans ;
    }
};