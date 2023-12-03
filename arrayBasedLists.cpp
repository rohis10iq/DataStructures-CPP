#include<iostream>
#include<string>

using namespace std;

class ArrayList{
    int size;
    int length;
    int *current;
    int *arr;

    public:
        ArrayList(int size){
            this->size=size;
            length=0;
            arr= new int[10];
            current=nullptr;
        }
    
    void start(){
        current=arr;
    }
    void tail(){
        current=arr+length-1;
    }
    void back(){
        current--;
    }
    void next(){
        current++;
    }

    void insertFun(int value, int position){
        if(size==length){
            cout<<"List is Full"<<endl;
        }
        else if(position<1 || position>length+1){
            cout<<"Invalid Position"<<endl;
        }
        else{
            tail();
            for(int i=length; i>=position; i++){
                *(current+1)=*current;
                back();
            }
            *(current+1)=value;
            length++;
        }
    } 
};

int main(){
    ArrayList L(5);
    L.insertFun(2,1);
    L.insertFun(4,2);
    L.insertFun(3,2);
    L.insertFun(3,3);
    L.insertFun(1,4);
}