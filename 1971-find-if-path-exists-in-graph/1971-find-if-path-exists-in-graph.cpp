/* approach 
    1.convert adj matrix to adj list
    2.apply bfs or dfs on adjlist
*/    

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adjList(n) ;
        int u ,v ;
        
        for(int i=0; i<edges.size() ;i++){
            u=edges[i][0] ;
            v=edges[i][1] ;
            
            adjList[u].push_back(v) ;
            adjList[v].push_back(u) ;
        }
        
        
        vector<bool> vis(n+1 , false) ;
        queue<int> q;
        q.push(source) ;
        
        vis[source] = true ;
        
        while(!q.empty()){
            int currNode= q.front() ;
            q.pop() ;
            
            for(auto it : adjList[currNode]){
                if(!vis[it]){
                    q.push(it) ;
                    vis[it] = true ;
                }
            }
        }
        
        return vis[destination] ? true : false ;
    }
};