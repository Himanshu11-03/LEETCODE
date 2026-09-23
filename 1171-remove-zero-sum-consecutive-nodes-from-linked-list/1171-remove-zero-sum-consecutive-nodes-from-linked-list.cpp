class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int, ListNode*> mp;
        int prefixSum = 0;
        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            prefixSum += curr->val;
            mp[prefixSum] = curr;
        }
        prefixSum = 0;
        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            prefixSum += curr->val;
            curr->next = mp[prefixSum]->next;
        }
        
        return dummy->next;
    }
};