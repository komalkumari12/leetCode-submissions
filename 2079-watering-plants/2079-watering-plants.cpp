class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps =0 ,index=-1 ;
        int cap=capacity ;
        
        for(int i=0; i <plants.size(); i ++){
            int back_steps=0,forward_steps=0;
            
            if(plants[i]>capacity){
                steps+= i ;
                steps+=i+1 ;
                capacity=cap ;
            }
            else{
                steps++ ;
            }
            capacity=capacity-plants[i] ;
            cout<< steps<<" " ;
        }
        
        return steps ;
    }
};