class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mag(26,0) ;
        vector<int> ran(26,0) ;
        
        for(int i=0; magazine[i] != '\0' ;i++){
            mag[magazine[i] - 'a']++ ;
        }
        
        for(int i=0; ransomNote[i] != '\0' ;i++){
            ran[ransomNote[i] - 'a']++ ;
        }
        
        
        for(int i=0; i<26 ;i++){
            if(mag[i] < ran[i]) return false ;
        }
        return true ;
        
    }
};