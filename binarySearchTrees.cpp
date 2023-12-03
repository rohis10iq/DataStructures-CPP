#include<iostream>

using namespace std;

struct Node{
    int info;
    Node* left;
    Node* right;

    Node(int value){
        right = NULL;
        left = NULL;
        info = value;
    }
};

Node* insertNode(Node* root, int value){
    if(root == NULL){
        return new Node(value);
    }
    if(value > root->info){

        root->right = insertNode(root->right, value);
    }
    else if(value < root->info){

        root->left = insertNode(root->left, value);
    }
    else{
        cout<<"duplicate Value"<<endl;
    }

    return root;
}

Node* searchNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->info == key){
        return root;
    }
    if(root->info > key){
        return searchNode(root->left, key);
    }
    
    return searchNode(root->right, key);
    
}

Node* inOrderSuccessor(Node* root){
    Node* current = root;
    while(current && current->left !=NULL){
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key < root->info){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->info){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{

            Node* temp = inOrderSuccessor(root->right);
            root->info = temp->info;
            root->right = deleteNode(root->right, temp->info);
        }
        
    }

    return root;
    
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->info<<" ";
    inOrder(root->right);
}

int main(){
    Node* root = NULL;

    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 7);
    insertNode(root, 6);
    insertNode(root, 8);

    inOrder(root);

    int key;

    cout<<endl<<"Enter Key to Search in BST: ";
    cin>>key;

    /*if(searchNode(root, key) == NULL){
        cout<<endl<<"key doesn't exist"<<endl;
    }
    else{
        cout<<"key exists"<<endl;
    }
    */
    
    root = deleteNode(root, key);
    inOrder(root);
    



    return 0;
}