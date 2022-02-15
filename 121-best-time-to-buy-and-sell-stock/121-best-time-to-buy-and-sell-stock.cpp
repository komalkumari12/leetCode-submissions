class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minEle = INT_MAX;
        int profit =0;
        
        for(int i=0; i<prices.size() ;i++){
            minEle = min(minEle , prices[i]) ;
            profit = max(profit , prices[i] - minEle) ;
        }
        
        return profit ;
    }
};