class Solution {
public:
    int maxProfit(vector<int>& p) {
        int max_profit= 0, minimal=INT_MAX;
        
        for(int i= 0; i<p.size();i++){
            minimal=min(minimal,p[i]) ;
            max_profit=max(max_profit,p[i]-minimal) ;
        }
          
        return  max_profit ;
    }
};