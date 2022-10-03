class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int cost=0;
        for(int i=0;i<colors.length()-1;i++)
        {
            if(colors[i]==colors[i+1])
            {
                if(neededTime[i]>neededTime[i+1])
                {
                    cost+=neededTime[i+1];
                    neededTime[i+1]=neededTime[i];
                } 
                else 
                {
                    cost+=neededTime[i];
                    
                }
            }
        }
        return cost;
    }
};