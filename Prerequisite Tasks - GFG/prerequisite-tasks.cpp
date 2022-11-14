//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& dfsVis, vector<vector<int>>& graph){
        vis[node] = 1 ;
        dfsVis[node] =1 ;
        
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, dfsVis, graph))
                return true ;
            }
            else if(dfsVis[it])
            return true ;
        }
        
        dfsVis[node] = 0 ;
        return false ;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    int n = prerequisites.size() ;
	    vector<vector<int>> graph(N) ;
	    
	    for(int i=0; i<n; i++){
	        int u = prerequisites[i].first ;
	        int v = prerequisites[i].second ;
	        
	        graph[u].push_back(v) ;
	    }
	    
	    vector<int> vis(N, 0) ;
	    vector<int> dfsVis(N, 0) ;
	    
	    for(int i=0; i<N; i++){
	        if(!vis[i]){
	            if(dfs(i, vis, dfsVis, graph))
	            return false ;
	        }
	    }
	    
	    return true ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends