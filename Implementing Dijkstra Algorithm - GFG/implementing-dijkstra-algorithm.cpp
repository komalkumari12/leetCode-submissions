//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> graph[], int src)
    {
        // vector<vector<int>> graph(V) ;
        // for(int u=0; u<V; u++){
        //     for(auto it: graph[u]){
        //         int v = graph[u][0] ;
        //         int wt = graph[u][1] ;
                
        //         graph[u].push_back({v, wt}) ;
        //         graph[v].push_back({u, wt}) ;
        //     }
        // }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q ;
        q.push({0, src}) ;
        
        vector<int> dist(V, INT_MAX) ;
        dist[src] = 0 ;
        
        while(!q.empty()){
            int parentDist = q.top().first ;
            int parentNode = q.top().second ;
            q.pop() ;
            
            for(auto it: graph[parentNode]){
                int v = it[0] ;
                int wt = it[1] ;
                
                if(parentDist + wt < dist[v]){
                    dist[v] = parentDist + wt ;
                    q.push({dist[v], v}) ;
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