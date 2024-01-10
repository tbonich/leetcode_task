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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node = head;
        ListNode* node_prev = NULL;
        while (node != NULL) {
            if (node->val == val) {
                if (node_prev != NULL) {
                    node = node->next;
                    node_prev->next = node;
                } else {
                    head = head->next;
                    node = head;
                }
            } else {
                node_prev = node;
                node = node->next;
            }
        }
        return head;
    }
};