class Solution {
    void rev(string &s , int i, int j){
        while(i<=j){
            swap(s[i] ,s[j]) ;
            j--;
            i++ ;
        }
    }
        
public:
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        
        while(j <= s.size()){
            if(s[j] == ' '  ||   j == s.size()){
                rev(s, i, j-1) ;
                i=j+1 ;
            }
            j++ ;
        }
        return s ;
    }
};