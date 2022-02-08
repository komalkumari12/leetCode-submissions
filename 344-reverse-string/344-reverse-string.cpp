class Solution {
public:
    void rev(vector<char>&s ,int start ,int end){
        if(start > end) return  ;
        
        swap(s[start] , s[end]) ;
        return rev(s ,start+1 ,end-1) ;
    }
        
    void reverseString(vector<char>& s) {
        rev(s ,0 ,s.size()-1) ;
    }
};