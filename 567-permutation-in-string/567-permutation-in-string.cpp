class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false ;
        
        vector<char> mpp1(26 ,0) ;
        vector<char> mpp2(26 , 0) ;
        int i ;
        
        for(i=0; i<s1.size() ;i++){
            mpp1[s1[i] - 'a']++ ;
            mpp2[s2[i] - 'a']++ ;
        }
        if(mpp1 == mpp2) return true ;
        
        int start = 0,  end = i ;
        
        while( end < s2.size()){
            mpp2[s2[start++] - 'a']-- ;
            mpp2[s2[end++] - 'a']++ ;
            
            if(mpp1 == mpp2) return true ;
        }
        return false ;
    }
};