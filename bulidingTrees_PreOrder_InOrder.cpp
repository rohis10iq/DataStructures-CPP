#include<iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;

    Node(int value) { 
        info = value;
        left = NULL;
        right = NULL;
    }
};

void inOrderPrint(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderPrint(root->left);
    cout << root->info << " ";
    inOrderPrint(root->right);
}

int searchFunction(int inOrder[], int start, int end, int current) {
    for (int i = start; i <= end; i++) {
        if (inOrder[i] == current) {
            return i;
        }   
    }
    return -1; // Return -1 if the element is not found
}

Node* buildTree(int preOrder[], int inOrder[], int& index, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int current = preOrder[index];
    index++;
    
    Node* node = new Node(current);

    if (start == end) {
        return node;
    }

    int position = searchFunction(inOrder, start, end, current);

    node->left = buildTree(preOrder, inOrder, index, start, position - 1);
    node->right = buildTree(preOrder, inOrder, index, position + 1, end);

    return node;
}

int main() {
    int inOrder[] = {1, 2, 4, 3, 5};
    int preOrder[] = {4, 2, 1, 5, 3};

    int index = 0;  // Initialize index
    Node* root = buildTree(preOrder, inOrder, index, 0, 4);
    inOrderPrint(root);

    return 0;
}
