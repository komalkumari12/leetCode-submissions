class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mag(26,0) ;
        
        for(int i=0; magazine[i] != '\0' ;i++){
            mag[magazine[i] - 'a']++ ;
        }
        
        for(int i=0; ransomNote[i] != '\0' ;i++){
           if( mag[ransomNote[i] - 'a'] ==0) return false ;
            mag[ransomNote[i] - 'a']-- ;
        }
        
        return true ;
        
    }
};