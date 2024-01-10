class MyLinkedListNode {
public: 
    int val;
    MyLinkedListNode* next;
    MyLinkedListNode(int v) {
        this->val = v;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    MyLinkedListNode* head;
    MyLinkedList() {
        head = NULL;
    }
    
    int get(int index) {
        MyLinkedListNode* tmp = head;
        while (index>0 && tmp != NULL) {
            tmp = tmp->next;
            index--;
        }
        if (tmp == NULL) 
            return -1;
        return tmp->val;
    }
    
    void addAtHead(int val) {
        MyLinkedListNode* node = new MyLinkedListNode(val);
        if (head != NULL) 
            node->next = head;
        head = node;
    }
    
    void addAtTail(int val) {
        MyLinkedListNode* node = new MyLinkedListNode(val);
        if (head == NULL) {
            head = node;
        } else {
            MyLinkedListNode* tmp = head;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = node;
        }
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedListNode* node = new MyLinkedListNode(val);
        MyLinkedListNode* tmp = head;
        if (index == 0) {
            node->next = head;
            head = node;
        } else {
            while (index>1 && tmp != NULL) {
                tmp = tmp->next;
                index--;
            }
            if (tmp != NULL && tmp->next != NULL) {
                node->next = tmp->next;
                tmp->next = node;
            } else if (tmp != NULL){
                tmp->next = node;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        MyLinkedListNode* tmp = head;
        if (index == 0) {
            head = head->next;
        } else {
            while (index>1 && tmp != NULL) {
                tmp = tmp->next;
                index--;
            } 
            if (tmp != NULL && tmp->next != NULL) {
                tmp->next = tmp->next->next;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */