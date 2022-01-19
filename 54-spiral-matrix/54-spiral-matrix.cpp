/*Approach
  dir==0 : left   to  right  -> top++
  dir==1 : top    to  down   -> right--
  dir==2 : right  to  left   -> down--
  dir==3 : down   to  top    -> left++
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ans ;
        int top = 0 , down = m.size()-1 ;
        int left = 0 , right = m[0].size()-1 ;
        int dir=0 ;
        
        while(top<=down && left<=right){
            
            if(dir==0){
                for(int i=left; i<=right ;i++){
                    ans.push_back(m[top][i]) ;    
                }
                top++ ;
            }
            
            else if(dir==1){
                for(int i=top ;i<=down ;i++){
                    ans.push_back(m[i][right]) ;
                }
                right-- ;
            }
            
            else if(dir==2){
                for(int i=right ;i>=left ;i--){
                    ans.push_back(m[down][i]) ;
                }
                down-- ;
            }
            
            else if(dir==3){
                for(int i=down ;i>=top ;i--){
                    ans.push_back(m[i][left]) ;
                }
                left++ ;
            }
            
            dir=(dir+1) %4 ;
        }
        
        return ans ;
    }
};