
class Solution {
public:
    int count =0 ;
    
    void solve(int node, vector<bool>& vis, vector<vector<int>>& graph, set<int>& st){
        vis[node] =true ;
        
        if(st.find(node) != st.end()) return ;
        
        for(auto it : graph[node]){
            if(!vis[it]){
                solve(it, vis, graph, st) ;
            }
        }
        
        count++ ;
    }
        
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> vis(n, false) ;
        vector<vector<int>> graph(n) ;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;
            
            graph[u].push_back(v) ;
            graph[v].push_back(u) ;
        }
        
        set<int> st ;
        for(int i=0; i<restricted.size(); i++){
            st.insert(restricted[i]) ;
        }
        
        solve(0, vis, graph, st) ;
        return count ;
    }
};
