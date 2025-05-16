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
    Node* curr = head;

    while (curr) {
        if (curr->child) {
            Node* next = curr->next;
            Node* child = flatten(curr->child);

            curr->next = child;
            child->prev = curr;
            curr->child = nullptr;

            while (curr->next) {
                curr = curr->next;
            }

            curr->next = next;
            if (next) next->prev = curr;
        }

        curr = curr->next;
    }

    return head;
}
};