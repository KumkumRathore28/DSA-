class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;

        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        ListNode* second = head;
        ListNode* curr = first;

        while (curr->next) {
            curr = curr->next;
            second = second->next;
        }

        swap(first->val, second->val);

        return head;
    }
};