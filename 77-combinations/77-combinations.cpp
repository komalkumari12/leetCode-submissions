class Solution {
public:
    void help(int index ,int k ,int n,vector<vector<int>>& ans ,vector<int>& ds){
        if(ds.size()==k){
                ans.push_back(ds) ;
            return ;
        }
        
        for(int i=index ;i<=n ;i++){
            ds.push_back(i) ;
            help(i+1 , k ,n,ans ,ds) ;
            
            ds.pop_back() ;
        }
    }
      
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans ;
        vector<int> ds ;
        
        help(1,k, n,ans,ds) ;
        
        return ans ;  
    }
};
