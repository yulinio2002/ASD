// Problem 2: Merge Two AVL Trees (Intersection - Only Common Values)
#include <iostream>
#include <vector>
#include <algorithm>
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

// AVL Insertion
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);

    updateHeight(node);
    return node;
}

// Recolectar valores de los nodos
void inorder(Node* node, vector<int>& values){
    if (!node) return;
    inorder(node->left, values);
    values.push_back(node->val);
    inorder(node->right, values);
}

// TODO: Complete the Merge Intersection Function
Node* mergeIntersectionAVL(Node* root1, Node* root2) {
    vector<int> values1, values2;
    inorder(root1, values1);
    inorder(root2, values2);

    // Recolectar valores comunes
    vector<int> commonValues;
    set_intersection(values1.begin(), values1.end(), values2.begin(), values2.end(), back_inserter(commonValues));

    // Insertar esos valores en un nuevo arbol
    Node* mergedRoot = nullptr;
    for (int val : commonValues){
        mergedRoot = insert(mergedRoot, val);
    }

    return mergedRoot;
}

// Funcion para imprimir
void printInOrder(Node* node){
    if (!node) return;
    printInOrder(node->left);
    cout << node->val << " ";
    printInOrder(node->right);
}

// Main function for testing
int main() {
    Node* root1 = nullptr;
    root1 = insert(root1, 10);
    root1 = insert(root1, 20);
    root1 = insert(root1, 30);
    root1 = insert(root1, 40);
    root1 = insert(root1, 50);

    Node* root2 = nullptr;
    root2 = insert(root2, 15);
    root2 = insert(root2, 20);
    root2 = insert(root2, 35);
    root2 = insert(root2, 40);
    root2 = insert(root2, 60);
    
    Node* mergedRoot = mergeIntersectionAVL(root1, root2);

    printInOrder(mergedRoot);
    cout << endl;
    return 0;
}
