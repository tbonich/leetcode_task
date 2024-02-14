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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }
        int size_list = 1;
        ListNode* node = head;
        while (node->next != NULL) {
            size_list++;
            node = node->next;
        }
        node->next = head;
        int k_new = k % size_list;
        node = head;
        while (size_list > k_new+1) {
            node = node->next;
            size_list--;
        }
        ListNode* res = node->next;
        node->next = NULL;
        return res;
    }
};