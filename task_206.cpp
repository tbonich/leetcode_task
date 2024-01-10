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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* tmp;
        if (node == NULL) 
            return head;
        while (node->next != NULL) {
            tmp = node->next;
            node->next = node->next->next;
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};