class Solution {
    bool dfs(int node , vector<int>& color , vector<vector<int>>& graph){
        if(color[node] == -1) color[node] = 1 ;
        
        for(auto it: graph[node]){
            if(color[it] == -1){
                color[it] = 1-color[node] ;
                if(! dfs(it, color, graph))
                    return false ;
            }
            else if(color[it] == color[node])
                return false ;
        }
        return true ;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1 , -1) ;
        vector<vector<int>> graph(n+1);
        
        for(auto i: dislikes) {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        for(int i=1 ; i<=n ;i++){
            if(color[i] == -1){
                if(! dfs(i, color, graph))
                    return false ;
            }
        }
        return true ;
    }
};