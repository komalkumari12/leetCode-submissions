class Solution {
public:
    vector<vector<int>> ans ;
    
    void dfs(int node, int parent, int& timer, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& g){
        
        vis[node] = 1 ;
        tin[node] = low[node] = timer++ ;
        
        for(auto it : g[node]){
            
            if(it == parent) continue ;
            
            if(!vis[it]){
                dfs(it, node, timer, vis, tin, low, g) ;
                low[node] = min(low[node], low[it]) ;
                
                if(low[it] > tin[node]){
//                     vector<int> ds ;
//                     ds.push_back(node) ;
//                     ds.push_back(it) ;
                    
//                     ans.push_back(ds) ;
                    
                    ans.push_back({node, it}) ;
                }
            }
            else{
                low[node] = min(low[node], tin[it]) ;
            }
        }
    }
        
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n+1) ;
        
        for(int i=0; i<connections.size(); i++){
          
            g[connections[i][0]].push_back(connections[i][1]) ;
            g[connections[i][1]].push_back(connections[i][0]) ;
            
        }
       
        int timer =0 ;
        vector<int> vis(n, 0) ;
        vector<int> tin(n, -1) ;
        vector<int> low(n, -1) ;
        
        for(int i=0; i<n ;i++){
            if(!vis[i]){
                dfs(i, -1, timer, vis, tin, low, g) ;
            }
        }
        
        return ans ;
    }
};