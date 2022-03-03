class Solution {
public:
    void path(int label ,vector<int>& labelPath){
        if(label==1){
            labelPath.push_back(1) ;
            return ;
        }
        
        labelPath.push_back(label) ;
        
        int height = (int)log2(label) ;
        int element = label/2 ;
        
        height-- ;
        
        int startEle=0;
        
        int endEle = pow(2,height) ;          //value of right most element in next level 
        startEle += endEle ;
        startEle += pow(2,(height+1)) -1 ;    //value of left most element in next level
         
        path(startEle-element , labelPath) ;
        
    }
        
    vector<int> pathInZigZagTree(int label) {
        vector<int> labelPath ;
        
        path(label , labelPath) ;
        reverse(labelPath.begin() ,labelPath.end()) ;
        
        return labelPath ;
    }
};
