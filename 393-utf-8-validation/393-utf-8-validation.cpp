class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int n = data.size();
        vector<int> vec = {127, 191, 223, 239, 247};
        
        for(int i=0; i<n; i++)
        {
            int pos = lower_bound(vec.begin(), vec.end(), data[i]) - vec.begin();        
            if(pos==5 || pos==1)
                return 0;
            
            if(pos==0)
                continue;
            
            pos--;
            i++;
            while(pos--)
            {
                if(i>=n)
                    return 0;
                
                int tmp = lower_bound(vec.begin(), vec.end(), data[i]) - vec.begin();
                
                if(tmp!=1)
                    return 0;
                
                i++;
            }
            i--;
        }
        
        return 1;
    }
};