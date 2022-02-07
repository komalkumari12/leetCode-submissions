/*  
    Approach
      a ^ a = 0
      a ^ 0 = a
      
      ie. 0  0  0
          0  1  0
          1  0  1
          1  1  0
*/          

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0 ;
        
        for(int i=0 ;i< t.size() ;i++) ans ^=t[i] ;
        for(int i= 0; i<s.size() ;i++) ans^=s[i] ;
        
        return ans ;
    }
};