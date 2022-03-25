class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        costs.size() ;
        int size=costs.size() ;
        //adding every person to cityA
        int totA=0 ;
        
        for(int i=0 ;i<size ;i++)
            totA+=costs[i][0] ;
        
        //we find refund we will get if we find every person to city 
        vector<int> diff ;
        for(int i=0 ;i<size ;i++){
            diff.push_back(costs[i][1]-costs[i][0]) ;
        }
        sort(diff.begin() , diff.end()) ;
        
        for(int i=0; i<size/2 ;i++){
            totA += diff[i] ;
        }
        
        return totA ;
    }
};