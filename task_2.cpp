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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* headA = l1;
        ListNode* headB = l2;
        int k = 0;
        ListNode* headres;
        if (l1->val + l2->val > 9) {
            headres = new ListNode(l1->val + l2->val - 10);
            k++;
        } else {
            headres = new ListNode(l1->val + l2->val);
        }
        headA = headA->next;
        headB = headB->next;
        ListNode* tmp = headres;
        while (headA != NULL && headB != NULL) {
            if (headA->val + headB->val + k > 9) {
                tmp->next = new ListNode(headA->val + headB->val + k - 10);
                k = 1;
            } else {
                tmp->next = new ListNode(headA->val + headB->val + k);
                k = 0;
            }
            tmp = tmp->next;
            headA = headA->next;
            headB = headB->next;
        }
        while (headA != NULL) {
            if (headA->val + k > 9) {
                tmp->next = new ListNode(headA->val + k - 10);
                k = 1;
            } else {
                tmp->next = new ListNode(headA->val + k);
                k = 0;
            }
            tmp = tmp->next;
            headA = headA->next;
        }
        while (headB != NULL) {
            if (headB->val + k > 9) {
                tmp->next = new ListNode(headB->val + k - 10);
                k = 1;
            } else {
                tmp->next = new ListNode(headB->val + k);
                k = 0;
            }
            tmp = tmp->next;
            headB = headB->next;
        }
        if (k != 0){
            tmp->next = new ListNode(k);
            tmp = tmp->next;
        }
        return headres;
    }
};