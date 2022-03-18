class Solution {
    bool isCyclePresent(int node , vector<int>& vis, vector<int>& dfsVis ,vector<vector<int>>& adjList){
        vis[node]=1 ;
        dfsVis[node]=1 ;
        
        for(auto it: adjList[node]){
            if(vis[it] == 0){
                if(isCyclePresent(it,vis,dfsVis,adjList))
                    return true ;
            }
            else if(dfsVis[it] == 1)
                return true ;
        }
        
        dfsVis[node] = 0;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses ,0) ;
        vector<int> dfsVis(numCourses ,0) ;
        
        vector<vector<int>> adjList(numCourses);
        
        for(int i=0; i<prerequisites.size() ;i++){
            int u= prerequisites[i][0] ;
            int v= prerequisites[i][1] ;
            
            adjList[u].push_back(v) ;
        }
        
        for(int i=0; i<numCourses ;i++){
            if(vis[i] == 0){
                if(isCyclePresent(i,vis, dfsVis ,adjList))
                    return false ;
            }
        }
        
        return true ;
    }
};