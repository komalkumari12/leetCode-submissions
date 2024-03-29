//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        set<pair<int,int>> st ;
        st.insert({0, src}) ;
        vector<int> dist(V, INT_MAX) ;
        dist[src] = 0 ;
        
        while(!st.empty()){
            auto it = *(st.begin()) ; 
            int distance = it.first ;
            int node = it.second ;
            st.erase(it) ;
            
            for(auto it : adj[node]){
                int v = it[0] ;
                int wt = it[1] ;
                
                if(distance + wt < dist[v]){
                    if(dist[v] != INT_MAX)
                        st.erase({dist[v], v}) ;
                        
                    dist[v] = distance + wt ;
                    st.insert({dist[v], v}) ;
                }
            }
        }
        
        return dist ;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends