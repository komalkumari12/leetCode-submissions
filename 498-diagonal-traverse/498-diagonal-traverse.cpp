class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mpp ;
        int n = mat.size() ;
        int m = mat[0].size() ;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mpp[i+j].push_back(mat[i][j]) ;
            }
        }
        
        // for(auto it: mpp){
        //     int i = it.first ;
        //     cout<<i<<" : " ;
        //     for(auto j : mpp[i]){
        //         cout<<j<<" " ;
        //     }
        //      cout<<endl ;   
        // }
        
        vector<int> ans ;
        bool dir = false ;
        
        for(auto it: mpp){
            vector<int> v ;
            int i = it.first ;
            
            for(auto j : mpp[i]){
                v.push_back(j) ;
            }
            
            if(dir){
                for(int i= 0; i<v.size(); i++){
                    ans.push_back(v[i]) ;
                }
            }
            else{
                for(int i= v.size()-1; i>=0; i--){
                    ans.push_back(v[i]) ;
                }
            }
            
            dir = !dir ;
        }
        
        return ans ;
    }
};