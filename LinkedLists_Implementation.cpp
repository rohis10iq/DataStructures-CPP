#include<iostream>

using namespace std;

class Node{
    private:
        int info;
        Node* next;
    public:
        Node(int value){
            this->info=value;
            next = NULL;
        }
    friend class LinkedList;
};

class LinkedList(){
    private:
        Node* head=NULL;
    public:
        LinkedList(){
            head=NULL;   
        }
    void addNode(int value){
        Node* newNode = new Node(value);
        if(head==NULL){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void deleteNode(int value){
        if(temp->next!=NULL)
    }
};
