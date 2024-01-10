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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tail_a = headA;
        while (tail_a->next != NULL) {
            tail_a = tail_a->next;
        }
        tail_a->next = headA;
        ListNode* node_f = headB;
        ListNode* node_s = headB;
        while (node_f != NULL && node_f->next != NULL) {
            node_s = node_s->next;
            node_f = node_f->next->next;
            if (node_f == node_s) {
                node_f = headB;
                while (node_f != node_s) {
                    node_f = node_f->next;
                    node_s = node_s->next;
                }
                tail_a->next = NULL;
                return node_f;
            }
        }
        tail_a->next = NULL;
        return NULL;
    }
};