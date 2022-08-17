class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char, string> mpp ;
        mpp['a'] = ".-" ;    mpp['b'] =  "-..." ;   mpp['c'] =  "-.-.";   mpp['d'] = "-.." ;
        mpp['e'] = "." ;     mpp['f'] = "..-." ;    mpp['g'] = "--." ;    mpp['h'] = "...." ;
        mpp['i'] =  ".." ;   mpp['j'] = ".---" ;    mpp['k'] = "-.-" ;    mpp['l'] = ".-.." ;
        mpp['m'] = "--" ;    mpp['n'] = "-." ;      mpp['o'] = "---" ;    mpp['p'] = ".--." ;
        mpp['q'] = "--.-" ;  mpp['r'] = ".-." ;     mpp['s'] = "..." ;    mpp['t'] = "-" ;
        mpp['u'] = "..-" ;   mpp['v'] = "...-" ;    mpp['w'] = ".--" ;    mpp['x'] = "-..-" ;
        mpp['y'] = "-.--" ;  mpp['z'] = "--.." ;
        
        set<string> count ;
        int ans =0 ;
        
        for(int i=0; i<words.size(); i++){
            string str = words[i] ;
            string deCodedString = "" ;
            
            for(int j=0; j<str.size(); j++){
                deCodedString += mpp[str[j]] ;
            }
            
            if(count.find(deCodedString) == count.end()){
                count.insert(deCodedString) ;
                ans++ ;
            }   
        }
        
        return  ans;
    }
};