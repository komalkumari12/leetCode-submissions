class Solution {
public:
    bool solve(string& queries, string& pattern, int i, int j){
        if(i >= queries.size() && j >= pattern.size())
            return true ;
        
        if(queries[i] == pattern[j])
            return solve(queries, pattern, i+1, j+1) ;
        else{
            if(queries[i]>='a'  && queries[i]<='z')
                return solve(queries, pattern, i+1, j) ;
            else
                return false ;
        }
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans ;
        
        for(int i=0; i<queries.size(); i++){
            ans.push_back(solve(queries[i], pattern, 0, 0)) ;
        }
        
        return ans ;
    }
};