class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> graph ;
        set<int> visBusStopNo ;
        set<int> visBusNo ;
        
        // bus Stop No --> Bus No
        for(int i=0; i<routes.size(); i++){
            for(auto it: routes[i]){
                graph[it].push_back(i) ;
            }
        }
        
        queue<int> q ;
        q.push(source) ;
        
        int level =0 ;
        while(!q.empty()){
            int size = q.size() ;
            
            
            for(int i=0; i<size; i++){
                int node = q.front() ;
                q.pop() ;
                
                if(node == target)
                    return level ;
                
                for(auto it: graph[node]){
                    if(visBusNo.find(it) == visBusNo.end()){
                        //if Bus No not visited 
                        
                        visBusNo.insert(it) ;
                        
                        for(auto jt: routes[it]){
                            //if bus sto no is not visited
                            
                            if(visBusStopNo.find(jt) == visBusStopNo.end()){
                                visBusStopNo.insert(jt) ;
                                
                                q.push(jt) ;
                            }
                        }
                    }
                }
            }
            
            level++ ;
        }
        
        return -1 ;
    }
};