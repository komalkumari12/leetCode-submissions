class Solution {
public:
    bool checkIfMatch(string s1, int i, string s2, int j){
        for(int k=0; k<s2.size(); k++){
            if(s1[i+k] != s2[k])
                return false ;
        }
        return true ;
    }
        
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0 ;
        if(haystack.size() < needle.size()) return -1 ;
        
        for(int i=0; i<haystack.size(); i++){
            if(haystack[i] == needle[0]){
                if(checkIfMatch(haystack, i, needle, 0))
                    return i ;
            }
        }
        
        return -1 ;
    }
};