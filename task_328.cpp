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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* tail = head;
        ListNode* node = head;
        int cnt = 0;
        if (head == NULL) 
            return head;
        while (tail->next != NULL) {
            tail = tail->next;
            cnt++;
        }
        if (tail == head || tail == head->next) 
            return head;
        while (cnt>0) {
            ListNode* tmp = node->next;
            node->next = node->next->next;
            node = node->next;
            tmp->next = NULL;
            tail->next = tmp;
            tail = tail->next;
            cnt = cnt - 2;
        }
        return head;
    }
};