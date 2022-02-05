class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode(), *cur = dummy;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> min_heap;
        for(auto l: lists) {
            if(l) min_heap.push({l->val, l});
        }
        while(!min_heap.empty()) {
            auto node = min_heap.top(); min_heap.pop();
			// add minimum node to current node
            cur->next = node.second;
            cur = cur->next;
			// check if there is next node after current minimum node
            auto next = node.second->next;
            if(next) min_heap.push({next->val, next});
        }
        return dummy->next;
    }
};

