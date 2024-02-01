/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }
        Node* node = head;
        while (node != NULL) {
            if (node->child != NULL) {
                Node* tmp = node->next;
                Node* child_tail = node->child;
                while (child_tail->next != NULL) {
                    child_tail = child_tail->next;
                }
                node->next = node->child;
                node->child->prev = node;
                node->child = NULL;
                child_tail->next = tmp;
                if (tmp != NULL) {
                    tmp->prev = child_tail;
                }
                node->child = NULL;
            }
            node = node->next;
        }
        return head;
    }
};