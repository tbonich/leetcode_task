class MyLinkedListNode {
public: 
    int val;
    MyLinkedListNode* next;
    MyLinkedListNode* prev;
    MyLinkedListNode(int v) {
        this->val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyLinkedList {
public:
    MyLinkedListNode* head;
    MyLinkedListNode* tail;
    MyLinkedList() {
        head = NULL;
        tail = NULL;
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
        if (head != NULL) {
            node->next = head;
            head->prev = node;
            head = node;
        } else {
            head = node;
            tail = node;
        }
    }
    
    void addAtTail(int val) {
        MyLinkedListNode* node = new MyLinkedListNode(val);
        if (tail == NULL) {
            head = node;
            tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedListNode* node = new MyLinkedListNode(val);
        MyLinkedListNode* tmp = head;
        if (index == 0) {
            if (tail == NULL) {
                head = node;
                tail = head;
            } else {
                node->next = tmp;
                tmp->prev = node;
                head = node;
            }
        } else {
            while (index>1 && tmp != NULL) {
                tmp = tmp->next;
                index--;
            }
            if (tmp != NULL && tmp->next != NULL) {
                node->next = tmp->next;
                node->prev = tmp;
                tmp->next->prev = node;
                tmp->next = node;
            } else if (tmp != NULL){
                tmp->next = node;
                node->prev = tmp;
                tail = node;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        MyLinkedListNode* tmp = head;
        if (index == 0) {
            if (tail == head) {
                tail = NULL;
                head = NULL;
            } else {
                head = head->next;
                head->prev = NULL;
            }
        } else {
            while (index>1 && tmp != NULL) {
                tmp = tmp->next;
                index--;
            } 
            if (tmp != NULL && tmp->next != NULL) {
                if (tmp->next == tail) {
                    tail = tmp;
                    tmp->next = NULL;
                } else {
                    tmp->next = tmp->next->next;
                    tmp->next->prev = tmp;
                }
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