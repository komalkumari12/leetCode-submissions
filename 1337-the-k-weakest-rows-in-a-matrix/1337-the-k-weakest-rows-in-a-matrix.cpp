class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        vector<int> ans ;
        vector<int> v ;
        
        for(int i=0; i<mat.size(); i++){
            int NoOfOnes=0;
            for(int j=0; j<mat[i].size();j++){
                if(mat[i][j]==1){
                    NoOfOnes++ ;
                }
            }
            ans.push_back(NoOfOnes) ;
        }  
        
        int minimum=INT_MAX;
        while(k--)
        {
            for(int i=0;i<ans.size();i++)
            {
                minimum=min(minimum,ans[i]);
            }
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i]==minimum)
                {
                    v.push_back(i);
                    ans[i]=INT_MAX;
                    minimum=INT_MAX;
                    break;
                }
            }
        }
        
        return v;   
    }
};
