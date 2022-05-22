class Solution {
public:
    int countSubstrings(string s) {
        int count=0 ;
        int low, high ;
        
        for(int i=0; i<s.size(); i++){
            low = i ;
            high = i ;
            
            //Odd length cycle
            while(low >= 0 &&  high < s.size()){
                if(s[low--] == s[high++])
                    count++ ;
                
                else
                    break ;
            }
            
            //Even length cycle
            low = i;
            high = i+1 ;
            
            while(low >= 0 &&  high <s.size()){
                if(s[low--] == s[high++])
                    count++ ;
                  
                else
                    break ;
            }
        }
        
        return count ;
    }
};