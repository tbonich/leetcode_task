/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* node_f = head;
        ListNode* node_s = head;
        while (node_f != NULL && node_f->next != NULL) {
            node_s = node_s->next;
            node_f = node_f->next->next;
            if (node_f == node_s) {
                node_f = head;
                while (node_f != node_s) {
                    node_f = node_f->next;
                    node_s = node_s->next;
                }
                return node_f;
            }
        }
        return NULL;
    }
};