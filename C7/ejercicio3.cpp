// Problem 3: AVL Playlist Manager
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int val, height;
    Node* left;
    Node* right;
    Node(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};

// Utility functions
int getHeight(Node* node) {
    return node ? node->height : 0;
}

void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

// TODO: Complete the Playlist Functions
void AddSong(Node*& root, int score) {
    // TODO: Implement AVL insertion log
    if (!root) root = new Node(score);
    if (score < root->val)
        AddSong(root->left, score);
    else if (score > root->val)
        AddSong(root->right, score);
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getHeight(root->left) - getHeight(root->right);
    if (balance > 1 && score < root->left->val)
        rightRotate(root);
        return;
    if (balance < -1 && score > root->right->val)
        leftRotate(root);
        return;
    if (balance > 1 && score > root->left->val) {
        leftRotate(root->left);
        rightRotate(root);
        return;
    }
    if (balance < -1 && score < root->right->val) {
        rightRotate(root->right);
        leftRotate(root);
        return;
    }
}

void RemoveSong(Node*& root, int score) {
    if (!root) return;
    if (score < root->val)
        RemoveSong(root->left, score);
    else if (score > root->val)
        RemoveSong(root->right, score);
    else{
        Node* temp = root->left ? root->left : root->right;
        if(!temp){
            temp = root;
            root = nullptr;
        } else{
            *root = *temp;
        }
        delete temp;
    }
}

int GetMostPopular(Node* root) {
    if(root->right){
        root = root->right;
    }
    return root->val;
}

int GetKthPopular(Node* root, int k) {
    int count = 0;
    int result = -1;

    // Manual reverse inorder traversal using a stack
    Node* curr = root;
    std::stack<Node*> stack;

    while (!stack.empty() || curr != nullptr) {
        // Desplazarse a la derecha completamente
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->right;
        }

        // Visitar nodo
        curr = stack.top();
        stack.pop();
        count++;

        if (count == k) {
            result = curr->val;
            break;
        }

        // Luego ir a la izquierda
        curr = curr->left;
    }

    return result;
}
// Main function for testing
int main() {
    Node* root = nullptr;
    AddSong(root, 10);
    AddSong(root, 20);
    AddSong(root, 15);
    cout << "Most Popular: " << GetMostPopular(root) << endl;
    cout << "2nd Most Popular: " << GetKthPopular(root, 2) << endl;
    RemoveSong(root, 15);
    cout << "Most Popular after removal: " << GetMostPopular(root) << endl;

    return 0;
}