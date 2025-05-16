class MyLinkedList {
private:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int v) : val(v), prev(nullptr), next(nullptr) {}
    };
    Node* sentinel;
    int size;


public:
    MyLinkedList() {
        sentinel = new Node(0);
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
        size = 0;
    }


    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = sentinel->next;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->val;
    }
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        Node* prevNode = sentinel;
        for (int i = 0; i < index; ++i) {
            prevNode = prevNode->next;
        }
        Node* nextNode = prevNode->next;
        Node* newNode = new Node(val);
        newNode->prev = prevNode;
        newNode->next = nextNode;
        prevNode->next = newNode;
        nextNode->prev = newNode;
        ++size;
    }


    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* curr = sentinel->next;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        Node* prevNode = curr->prev;
        Node* nextNode = curr->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete curr;
        --size;
    }
};
//El nodo centinela elimina condiciones borde para insertar o eliminar al inicio o final y al ser circular, nunca hay punteros nulos en prev o next.




/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
