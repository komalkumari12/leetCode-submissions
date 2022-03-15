class Solution {
    void dfs(int node,int target , vector<int> &path , vector<vector<int>> &ans , vector<vector<int>> &graph){
        path.push_back(node) ;
        if(node==target) ans.push_back(path) ;
       
            for(auto it : graph[node]){
                dfs(it,target,path,ans,graph) ;
            }
        
        path.pop_back() ;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans; 
        vector<int>path ;
        
        dfs(0,graph.size()-1,path, ans, graph) ;
        
        return ans ;
    }
};