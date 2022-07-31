class Solution {
public:
    bool solve(string s, string t){
        unordered_map<char, char> mpp ;
        
        for(int i=0; i<s.size(); i++){
            if(mpp.find(t[i]) != mpp.end()){
                //in the map
                if(mpp[t[i]] != s[i])
                    return false ;
            }
            else{
                mpp[t[i]] = s[i] ;
            }
        }
        
        return true ;
    }
    
    bool isIsomorphic(string s, string t) {
        return solve(s,t) && solve(t,s) ;
    }
};