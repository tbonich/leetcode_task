/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node_f = head;
        ListNode* node_s = head;
        for (int i = 0; i<n; i++) {
            node_f = node_f->next;
        }
        if (node_f == NULL)
            return head->next;
        while(node_f->next != NULL) {
            node_f = node_f->next;
            node_s = node_s->next;
        }
        node_s->next = node_s->next->next;
        return head;
    }
};