class Solution {
    int dfs(int node , vector<int> &ans , vector<vector<int>> &adjList , vector<int> &quiet){
        int minPerson = node ;
        
        for(auto it: adjList[node]){
            if(ans[it] != -1){
                if(quiet[ans[it]] < quiet[minPerson]){
                    minPerson = ans[it] ;
                }
            }
            
            else{
                int somePerson = dfs(it,ans,adjList,quiet) ;
                if(quiet[somePerson] < quiet[minPerson]){
                    minPerson = somePerson ;
                }
            }
        }
        
        ans[node] = minPerson ;
        return minPerson ;
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n= quiet.size() ;
        vector<vector<int>> adjList(n) ;
        vector<int> ans(n,-1);
        
        for(int i=0; i<richer.size() ;i++){
            int u=richer[i][0] ;
            int v=richer[i][1] ;
            
            adjList[v].push_back(u) ;
        }
        
        for(int i=0; i<adjList.size() ;i++){
            if(ans[i] == -1)
            dfs(i,ans, adjList,quiet) ;
        }
        
        return ans ;
    }
};