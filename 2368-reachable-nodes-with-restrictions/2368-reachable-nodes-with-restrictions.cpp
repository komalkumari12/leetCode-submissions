class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
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
        
        
        queue<int> q ;
        q.push(0) ;
        vector<bool> vis(n, false) ;
        vis[0] = true ;
            
        int count =0 ;
        while(!q.empty()){
            int size = q.size() ;
            
            for(int i=0; i<size; i++){
                int node = q.front() ;
                q.pop() ;
                
                if(st.find(node) != st.end())   continue ;
                count++ ;
                
                for(auto it : graph[node]){
                    if(!vis[it]){
                        q.push(it) ;
                        vis[it] = true ;
                    }
                }
            }
        }
        
        return count ;
    }
};


