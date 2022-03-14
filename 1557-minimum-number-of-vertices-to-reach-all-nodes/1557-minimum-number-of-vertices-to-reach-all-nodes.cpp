class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        //convert adj matrix to adj list 
        vector<vector<int>> adjList(n) ;
        int u, v ;
        
        for(int i=0; i<edges.size() ;i++){
            u=edges[i][0] ;
            v=edges[i][1] ;
            
             adjList[u].push_back(v) ;
        }
       
        //store indegree of every node 
        vector<int> indegree(n,0) ;
        
        for(int i=0; i<n ;i++){
            for(auto it: adjList[i])
                indegree[it]++ ;
        }
        
        vector<int> result ;
        for(int i=0; i<indegree.size() ;i++){
            if(indegree[i] == 0)
                result.push_back(i) ;
        }
        
        return result ;
    }
};