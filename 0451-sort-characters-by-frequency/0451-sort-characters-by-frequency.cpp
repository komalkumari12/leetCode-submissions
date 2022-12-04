class Solution {
public:
    string frequencySort(string s) {
        int n = s.size() ;
        
        map<char, int> mapFreq ;
        for(int i=0; i<n; i++)
            mapFreq[s[i]]++ ;
        
        priority_queue<pair<int, char>> freqHeap ;
        for(auto it: mapFreq){
            char ch = it.first ;
            int freq = it.second ;
            
            freqHeap.push({freq, ch}) ;
        }
        
        // while(!freqHeap.empty()){
        //     cout<<freqHeap.top().first<<"  "<<freqHeap.top().second ;
        //     cout<<endl ;
        //     freqHeap.pop() ;
        // }
        
        string str = "" ;
        while(!freqHeap.empty()){
            int freq = freqHeap.top().first ;
            char ch = freqHeap.top().second ;
            
            for(int i=0; i<freq; i++){
                str += ch ;
            }
            freqHeap.pop() ;
        }
        
        return str ;
    }
};