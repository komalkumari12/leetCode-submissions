class Solution {
public:
    int maxPower(string s) {
        int maxP = INT_MIN ;
        int left =0, right =0 ;
        
        for(int i=0; i<s.size(); i++){
            set<char> st ;
            
            for(int i=left; i<= right; i++){
                st.insert(s[i]) ;
            
            }
            
            if(st.size() == 1){
                maxP = max(maxP, right- left+1) ;
            }
            else{
                left++ ;
            }
          
            right++ ;
        }
        
        return maxP ;
    }
};