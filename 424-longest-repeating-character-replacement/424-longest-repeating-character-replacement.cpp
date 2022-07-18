class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0) ;
        int left=0, right=0 ;
        int freq=0, maxLen=0 ;
        
        while(right < s.size()){
            hash[s[right]-'A']++ ;
            freq = max(freq, hash[s[right]-'A']) ;
            
            if((right - left +1) - freq > k){
                hash[s[left]-'A']-- ;
                left++ ;
            }
            
            maxLen = max(maxLen, right - left +1) ;
            right++ ;
        }
        
        return maxLen ;
    }
};