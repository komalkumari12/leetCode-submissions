//BFS

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q ;
        vector<int>indegree(numCourses ,0) ;
        // vector<vector<int>>  adjList(numCourses+1) ;
        vector<int> adjList[numCourses+1];
        
        for(int i=0; i<prerequisites.size() ;i++){
            int u=prerequisites[i][0] ;
            int v=prerequisites[i][1] ;
            
            adjList[v].push_back(u) ;
        }
        
        for(int i=0; i<numCourses ;i++){
            for(auto it: adjList[i])
                indegree[it]++ ;
        }
        
        for(int i=0; i<indegree.size() ;i++)
            if(indegree[i] == 0)
                q.push(i) ;
        
        int cnt=0 ;
        vector<int>topo ;
        
        while(!q.empty()){
            int node=q.front() ;
            q.pop() ;
            
            topo.push_back(node); 
            cnt++ ;
            
            for(auto it: adjList[node]){
                indegree[it]-- ;
                
                if(indegree[it] == 0)
                    q.push(it) ; 
            }
        }
        
        cout<<cnt<<"  " ;
        if(cnt == numCourses) return topo ;
        return {} ;
    }
};