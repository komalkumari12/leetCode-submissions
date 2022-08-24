class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0) ;
        
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0] ;
            int v = roads[i][1] ;
            
            indegree[u]++ ;
            indegree[v]++ ;
        }
        
        int maxiNetwork = 0 ;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                
                if(indegree[i] + indegree[j] > maxiNetwork){
                    maxiNetwork = indegree[i] + indegree[j] ;
                    
                    for(int k=0; k<roads.size(); k++){
                        int u = roads[k][0] ;
                        int v = roads[k][1] ;
                        
                        if((i == u && j == v) || (i == v && j == u))
                            maxiNetwork--  ;
                        }     
                    }
                }
            }
        
        
        return maxiNetwork ;
    }
};