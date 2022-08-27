class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        queue<int> q;
        int count =0 ;
        
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == '0' && s[i+1] == '1')
                // mpp[s[i]] =true ;
                q.push(i) ;
        }
        
        while(!q.empty()){
            count++ ;
            int size = q.size() ;
            
            for(int i=0; i<size; i++){
                int ind = q.front() ;
                q.pop() ;
               
                s[ind] = '1' ;
                s[ind+1] = '0' ;
            }
            
            for(int i=0; i<s.size()-1; i++){
                if(s[i] == '0' && s[i+1] == '1')
                    q.push(i) ;
            }
        }
        
        return count ;
    }
};