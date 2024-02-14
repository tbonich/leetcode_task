/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* node_f = head;
        Node* tmp = new Node(head->val);
        while (node_f != NULL) {
            tmp = new Node(node_f->val);
            tmp->next = node_f->next;
            node_f->next = tmp;
            node_f = node_f->next->next;
        }
        node_f = head;
        while (node_f != NULL) {
            tmp = node_f->next;     
            if (node_f->random != NULL)
                tmp->random = node_f->random->next;
            node_f = node_f->next->next;
        }
        node_f = head;
        tmp = node_f->next;
        Node* head_new = tmp;
        while (node_f != NULL) {
            tmp = node_f->next;
            node_f->next = tmp->next;
            if (tmp->next != NULL)
                tmp->next = tmp->next->next;
            node_f = node_f->next;
        }
        return head_new;
    }
};