class Solution {
public:
    bool isCycle(int node, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& dfsVis, vector<bool>& safeNodes){
        
        vis[node] = true;
        dfsVis[node] = true ;
        
        for(auto it: graph[node]){
            if(!vis[it]){
                if(!isCycle(it, graph, vis, dfsVis, safeNodes))
                    return safeNodes[node] = false ;
            }
            else if(dfsVis[it]){
                return safeNodes[node] = false ; 
            }
        }
        
        dfsVis[node] = false ;  // cycle not pesent
        return safeNodes[node] ;
    }
        
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> ans ;
        vector<bool> vis(n, false) ;
        vector<bool> dfsVis(n, false) ;
        vector<bool> safeNodes(n, true) ;
        
        for(int i=0; i<n; i++){
            if(!vis[i])
                isCycle(i, graph, vis, dfsVis, safeNodes) ;
        }
        
        for(int i=0; i<safeNodes.size(); i++){
            if(safeNodes[i])
                ans.push_back(i) ;
        }
    
        return ans ;
    }
};