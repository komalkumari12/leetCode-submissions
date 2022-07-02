// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    vector<string> ans ;
    
    public:
    void paths(int i, int j, int n, string str, vector<vector<int>> &mat, vector<vector<int>>& vis){
        if(i>=mat.size() || j>=mat[0].size() || i<0 || j<0 || mat[i][j] == 0 || vis[i][j] == 1) return ;
        if(i==n-1 && j==n-1){
            ans.push_back(str) ;
            return ;
        }
        
        vis[i][j] = 1 ;
        
        paths(i+1, j, n, str+"D", mat, vis) ;
        paths(i-1, j, n, str+"U", mat, vis) ;
        paths(i, j+1, n, str+"R", mat, vis) ;
        paths(i, j-1, n, str+"L", mat, vis) ;
        
        vis[i][j]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        string str= "" ;
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0) return {} ;
        
        vector<vector<int>> vis(n, vector<int>(n, 0)) ;
        paths(0, 0, n, str, mat, vis) ;
        return ans ;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends