class Solution {
    bool bfs(int src, vector<int>& color , vector<vector<int>>& adjList){
        queue<int> q ;
        q.push(src) ;
        color[src] = 1 ;
        
        while(!q.empty()){
            int node= q.front() ;
            q.pop() ;
            
            for(auto it: adjList[node]){
                if(color[it] == -1){
                    color[it] = 1-color[node] ;
                    q.push(it) ;
                }
                if(color[it] == color[node])
                    return false ;
            }
        }
        
        return true ;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size()  ;
        vector<int> color(n+1 , -1) ;
        
        vector<vector<int>> adjList(n+1) ;
        
//         for(int i=0; i<graph.size() ;i++){
//             int u= graph[i][0] ;
//             int v= graph[i][1] ;
            
//             adjList[u].push_back(v) ;
//             adjList[v].push_back(u) ;
//         }
        
        for(int i=0; i<graph.size() ;i++){
            if(color[i] == -1){
                if(! bfs(i, color,graph)) 
                    return false ;
            }
        }
        
        return true ;
    }
};