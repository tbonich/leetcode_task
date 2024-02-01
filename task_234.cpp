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
    bool isPalindrome(ListNode* head) {
        ListNode* node_f = head;
        ListNode* node_s = head;
        while (node_f != NULL && node_f->next != NULL) {
            node_s = node_s->next;
            node_f = node_f->next->next;
        }
        ListNode* node_prev = node_s;
        node_s = node_s->next;
        node_prev->next =NULL;
        ListNode* node_tmp;
        while(node_s != NULL) {
            node_tmp = node_s->next;
            node_s->next = node_prev;
            node_prev = node_s;
            node_s = node_tmp;
        }
        node_s = node_prev;
        node_f = head;
        while(node_s != NULL) {
            if (node_f->val == node_s->val) {
                node_f = node_f->next;
                node_s = node_s->next;
            } else {
                return false;
            }
        }
        return true;
    }
};