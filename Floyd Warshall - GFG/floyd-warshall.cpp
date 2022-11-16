//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size() ;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9 ;
	            }
	            
	            if(i == j)
	                matrix[i][j] = 0 ;
	        }
	    }
	    
	    for(int via=0; via<n; via++){
	        for(int i=0; i<n ;i++){
	            for(int j=0; j<n ; j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]) ;
	            }
	        }
	    }
	    
	    //To detect cycles in the graph
	    for(int i=0; i<n ;i++){
	        if(matrix[i][i] < 0){
	            cout<<"Cycle present in the graph " ;
	        }
	    }
	    
	    // Dijkstra does not work if negative cycles are present so, If there is no negative is present Dijkstra could be implemented to find shortest distance form every node to every other node.
	    // Dijkstra can be immplemented for every node. 
	    
	    for(int i=0; i<n ; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == 1e9)
	                matrix[i][j] = -1 ;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends