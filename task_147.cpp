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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* node_s = head;
        ListNode* node_i = head->next;
        while (node_i != NULL) {
            node_s = head;
            while (node_i != node_s) {
                if (node_i->val < node_s->val) {
                    swap(node_i->val, node_s->val);
                }
                node_s = node_s->next;
            }
            node_i = node_i->next;
        }
        return head;
    }
};