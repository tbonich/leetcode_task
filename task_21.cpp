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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* headA = list1;
        ListNode* headB = list2;
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        ListNode* headres = headA;
        if (headA->val < headB->val) {
            headres = headA;
            headA = headA->next;
        } else {
            headres = headB;
            headB = headB->next;
        }
        ListNode* tmp = headres;
        while (headA != NULL && headB != NULL) {
            if (headA->val < headB->val) {
                tmp->next = headA;
                headA = headA->next;
            } else {
                tmp->next = headB;
                headB = headB->next;
            }
            tmp = tmp->next;
        }
        if (headA != NULL) {
            tmp->next = headA;
        }
        if (headB != NULL) {
            tmp->next = headB;
        }
        return headres;
    }
};