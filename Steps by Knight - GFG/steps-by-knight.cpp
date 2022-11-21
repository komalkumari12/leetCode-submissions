//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    bool isValid(int i, int j, int n){
        if(i>=0 && j>=0 && i<=n && j<=n)  return true ;
        return false ;
    }
    
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n)
	{
	    int sourcei = KnightPos[0] ;
	    int sourcej = KnightPos[1] ;
	    
	    int targeti = TargetPos[0] ;
	    int targetj = TargetPos[1] ;
	    
	    queue<pair<int,pair<int,int>>> q ;
	    q.push({0,{sourcei, sourcej}}) ;
	    
	    vector<vector<int>> vis(n+1, vector<int>(n+1, 0)) ;
	    vis[sourcei][sourcej] = 1 ;
	    
	    int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
	    
	    while(!q.empty()){
	        int x = q.front().second.first ;
	        int y = q.front().second.second ;
	        int steps =q.front().first ;
	        q.pop() ;
	        
	        if(x == targeti && y == targetj)
	            return steps ;
	            
	        for(int k=0; k<8; k++){
	            int new_x= x + dx[k] ;
	            int new_y= y + dy[k] ;
	            
	            if(isValid(new_x, new_y, n) && vis[new_x][new_y] == 0){
	                q.push({steps+1, {new_x, new_y}}) ;
	                vis[new_x][new_y] =1 ;
	            }
	        }     
	    }
	    
	    return -1 ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends