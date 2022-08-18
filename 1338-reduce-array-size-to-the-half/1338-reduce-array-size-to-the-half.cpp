class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mpp ;
        for(int i=0; i<arr.size(); i++){
            mpp[arr[i]]++ ;
        }
        
        vector<int> freq ;
        for(auto it : mpp){
            int freqEle = it.second ;
            freq.push_back(freqEle) ;
        }
        
        sort(freq.begin(), freq.end()) ;
        reverse(freq.begin(), freq.end()) ;

        int count =0 , miniSize = arr.size() /2, i;
        for(i=0; i<freq.size(); i++){
            if(count < miniSize)  count += freq[i] ;
            else break ;
        }
        
        return i ;
    }
};