/* Approach
    1.convert adj matrix to adj list
    2. apply dfs on adj list
*/    

class Solution {
public:
    void dfs(int node, vector<bool> &vis , vector<vector<int>> &adjList){
        vis[node] = true ;
        
        for(auto it: adjList[node]){
            if(!vis[it]){
                dfs(it, vis, adjList) ;
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n) ;
        int u,v ;
        
        for(int i=0; i<edges.size() ;i++){
            u=edges[i][0] ;
            v=edges[i][1] ;
            
            adjList[u].push_back(v) ;
            adjList[v].push_back(u) ;
        }
        
        vector<bool> vis(n+1 ,false) ;
        
        dfs(source, vis, adjList) ;
        
        return vis[destination] ? true : false ; 
    }
};