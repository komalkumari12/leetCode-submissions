class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int low=0, high = tokens.size()-1 ;
        int max_score =0, score=0 ;
        
        sort(tokens.begin(), tokens.end()) ;
        
        while(low <= high){
            
            if(tokens[low] <= power){
                score++ ;
                power -= tokens[low++] ;
                max_score = max(max_score, score) ;
            }
            else if(score>=1){
                score-- ;
                power += tokens[high--] ;
            }
            else{
                break ;
            }
        }
        
        return max_score ;
        
    }
};