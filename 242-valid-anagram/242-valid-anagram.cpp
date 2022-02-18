class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false ;
        
        vector<int> sHash(256 ,0) ; 
        vector<int> tHash(256 ,0) ; 
        
        for(int i=0; s[i] != '\0' ;i++){
            sHash[s[i] - 'a']++ ;
            tHash[t[i] - 'a']++ ;
        }
        
        return sHash == tHash ? true : false ; 
    }
};