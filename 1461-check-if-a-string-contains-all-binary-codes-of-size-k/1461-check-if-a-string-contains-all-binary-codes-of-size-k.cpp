class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k) return false ;
        
        set<string> st ;
        
        int num = pow(2, k) ;
        for(int i = 0; i <= s.size()-k; i++){
            st.insert(s.substr(i, k)) ;
        }
        
        if(st.size() == num) return true ;
        return false ;
    }
};

