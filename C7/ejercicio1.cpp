[11:48 AM, 5/9/2025] Leonel(CS): // Problem 3: AVL Playlist Manager
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
    Node* y = x->r…
[11:53 AM, 5/9/2025] Favian(Electronica): #include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val, height, size;
    Node* left;
    Node* right;
    Node(int x) : val(x), height(1), size(1), left(nullptr), right(nullptr) {}
};

// Utility functions
int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getSize(Node* node) {
    return node ? node->size : 0;
}

void updateHeightAndSize(Node* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        node->size = 1 + getSize(node->left) + getSize(node->right);
    }
}

// K-th Smallest function using subtree sizes
int findKthSmallest(Node* root, int k) {
    if (!root) return -1;  // Verifica que el nodo raíz exista; si no, devuelve -1 

    int leftSize = getSize(root->left); // Obtiene el tamaño del subárbol izquierdo 

    if (k == leftSize + 1)  
        // Si k es igual al tamaño del subárbol izquierdo + 1, el nodo actual es el k-ésimo menor
        return root->val;
    else if (k <= leftSize)  
        // Si k está dentro del subárbol izquierdo, busca recursivamente en el hijo izquierdo
        return findKthSmallest(root->left, k);
    else   
        // Si k es mayor, busca en el subárbol derecho ajustando k (Se le quita los nodos de la izquierda y root)
        return findKthSmallest(root->right, k - leftSize - 1);
}


// AVL Insertion (without rebalancing for simplicity here)
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);

    updateHeightAndSize(node);
    return node;
}

// Main function for testing
int main() {
    
    Node* root = nullptr;

    /*
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);
    */

    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    

    for (int k = 1; k <= 7; ++k) {
        cout << "The " << k << "-th smallest element is: " 
             << findKthSmallest(root, k) << endl;
    }

    return 0;
}