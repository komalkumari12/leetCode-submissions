class Solution {
    bool bfs(int src ,vector<int>& color ,vector<vector<int>>& graph){
        queue<int> q ;
        q.push(src) ;
        
        color[src]=1 ;
        
        while(!q.empty()){
            int node= q.front() ;
            q.pop() ;
            
            for(auto it: graph[node]){
                if(color[it] == -1){
                    color[it] = 1-color[node] ;
                    q.push(it) ;
                }
                else if(color[it] == color[node])
                    return false ;
            }
        }
        return true ;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>  graph(n+1) ;
        vector<int> color (n+1 ,-1) ;
        
        for(int i=0; i<dislikes.size() ;i++){
            int u= dislikes[i][0] ;
            int v= dislikes[i][1] ;
            
            graph[u].push_back(v) ;
            graph[v].push_back(u) ;
        }
        
        for(int i=1 ;i<=n ;i++){
            if(color[i] == -1){
                if(! bfs(i,color,graph))
                    return false ;
            }
        }
        return true ;
    }
};
