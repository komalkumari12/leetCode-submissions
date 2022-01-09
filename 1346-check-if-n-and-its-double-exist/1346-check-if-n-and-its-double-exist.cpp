class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        for(int i=0; i<arr.size(); i ++){
            
            for(int j=i+1; j<arr.size(); j++){
                
                if(2*arr[j]==arr[i])
                    return true ;
                
                else if((double)arr[j]/2==(double)arr[i])
                    return true ;
            }
        }
        return false;
    }
};