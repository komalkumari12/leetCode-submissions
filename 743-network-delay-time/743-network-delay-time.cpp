class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vector<pair<int,int>>> graph(n+1) ;
        
        for(int i=0; i<times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]}) ;
        }
        
        // for(auto it: times){
        //     graph[it[0]].push_back({it[1], it[2]}) ;
        // }
        
        vector<int> dist(n+1, 1e9) ;
        dist[src] =0 ;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq ;
        pq.push({0,src}) ;       // distance , node
        
        while(!pq.empty()){
            int node = pq.top().second ;
            int srcDist = pq.top().first ;
            pq.pop() ;
            
            for(auto it: graph[node]){
                int adjNode = it.first ;
                int weight = it.second ;
                
                if(srcDist + weight < dist[adjNode]){
                    dist[adjNode] = srcDist + weight  ;
                    pq.push({dist[adjNode] ,adjNode}) ;
                }
            }
        }
        
        int maxTime =0 ;
        for(int i=1; i<dist.size(); i++){
            if(dist[i] == 1e9) return -1 ;
            maxTime = max(maxTime, dist[i]) ;
        }
        
        return maxTime ;
    }
};