class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        int size = n / k;
        int extra = n % k;

        vector<ListNode*> ans(k, NULL);

        ListNode* curr = head;

        for (int i = 0; i < k; i++) {

            if (curr == NULL)
                break;

            ans[i] = curr;

            int partSize = size;

            if (i < extra)
                partSize++;

            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            ListNode* nextPart = curr->next;

            curr->next = NULL;

            curr = nextPart;
        }

        return ans;
    }
};