#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *next=NULL;
    

    Node(int value){
        this->value = value;
    }
};

class PlayList{
    public:
    Node *head;
    int length;

    PlayList(){
        head=NULL;
        length=0;
    }

    void insert(int position, int value){
        if(position<1 || position >(length+1)){
            cout<<"Invalid Poistion";
        }
        else{
            if(position==1){
                Node *temp = new Node(value);
                temp->next=head;
                head=temp;
                length++;
            }
            else{
                Node *curr = head;
                for(int i=1;i<position-1;i++){
                    curr=curr->next;
                }
                Node *temp=new Node(value);
                temp->next=curr->next;
                curr->next=temp;
                 
            }
            length++;
        }
    }

    void printList(){
        Node *curr=head;
        while(curr!=NULL){
            cout<<curr->value<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
};

int main(){
    PlayList List;
    List.insert(1,5);
    List.printList();

    List.insert(2,4);
    List.printList();
    List.insert(3,8);
    List.printList();
    List.insert(2,7);
    List.printList();

}