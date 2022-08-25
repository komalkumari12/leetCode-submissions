class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n) ;
        vector<vector<int>> graph(n) ;
        
        for(int i=0; i<paths.size(); i++){
            int u = paths[i][0] ;
            int v = paths[i][1] ;
            
            graph[u-1].push_back(v-1) ;
            graph[v-1].push_back(u-1) ;
        }
        
        for(int i=0; i<n; i++){
            vector<int> color(5, 0) ;
            
            for(auto it: graph[i]){
                color[ans[it]] = 1 ;
            }
            for(int k =4; k>0; k--){
                if(color[k] == 0)
                    ans[i]= k ;
            }
        }
        return ans ;
    }
};