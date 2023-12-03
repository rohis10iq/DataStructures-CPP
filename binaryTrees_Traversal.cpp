#include<iostream>
using namespace std;

struct Node{
    int info;
    Node* left;
    Node* right;

    Node(int value){ 
        info = value;
        left = NULL;
        right = NULL;
    }

    void inOrder(struct Node* root){
        if(root==NULL){
            return;
        }

        inOrder(root->left);
        cout<<root->info<<" ";
        inOrder(root->right);
    }
    void preOrder(struct Node* root){
        if(root==NULL){
            return;
        }

        cout<<root->info<<" ";
        preOrder(root->left);
        preOrder(root->right);

    }
    void postOrder(struct Node* root){
        if(root==NULL){
            return;
        }
        
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->info<<" ";

    }

    bool childNoChild(struct Node* root){
        if(root == NULL || root->left == NULL || root->right == NULL){
            return true;
        }
        if(root->right && root->left != NULL){
            return false;
        }

        return childNoChild(root->left) && childNoChild(root->right);
    }
};

    

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"PreOrder Traversal"<<endl;
    root->preOrder(root);

    cout<<endl<<"InOrder Traversal"<<endl;
    root->inOrder(root);

    cout<<endl<<"PostOrder Traversal"<<endl;
    root->postOrder(root);

    if(root->childNoChild(root)){
        cout<<endl<<"Bool = True"<<endl;
    }
    else{
        cout<<endl<<":("<<endl;
    }

    return 0;
}