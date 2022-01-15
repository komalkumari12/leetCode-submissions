 class Solution {
 public:
     vector<int> nodesBetweenCriticalPoints(ListNode* head){
         int first=-1 ,last=-1 , index=0 ,minDis=INT_MAX ;
        
         ListNode *prev=NULL ;
        
             while(head){
                 
             if(head->next && prev){
                 
                 if((head->val>head->next->val && head->val>prev->val) || (head->val<head->next->val && head->val<prev->val)) 
                {
                     if(first==-1)
                         first=index ;
                     if(last!=-1)
                         minDis=min(minDis , index-last) ;
                     last=index ;
                     
                }      
             }
             index++;
             prev=head ;
             head=head->next ;
         }
                 if(first==last)
                    return {-1,-1} ;
        
         return {minDis, last-first} ;
     }
 };
