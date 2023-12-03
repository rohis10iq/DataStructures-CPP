#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value; 
        next = NULL;
    }
};

class Stack {
    Node* top;
    int limit;
    int length;

public:
    Stack(int limit) {
        this->limit = limit;
        top = NULL;
        length = 0;
    } 

    ~Stack() {
        cout<<endl<<"*Deleting Stack from Memory*"<<endl;
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        if(top == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull() {
        if(length == limit){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int value) {
        if (!isFull()) {
            Node* temp = new Node(value);
            temp->next = top;
            top = temp;
            length++;
            cout << "Element " << value << " is Pushed" << endl;
        }
        else {
            cout << "Stack Overflow!" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            Node* temp = top;
            int valuePop = top->value;
            top = top->next;
            delete temp;
            temp = NULL;
            length--;
            cout << "Element " << valuePop << " is Popped!" << endl;
            return valuePop;
        }
        else{
            cout<<"Stack Underflow!"<<endl;
        }
    }

    void display() {
        if (!isEmpty()) {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    Stack stack(2);

    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout<<"Swapping..."<<endl<<endl;
    stack.push(num1); 
    stack.push(num2); 

    num1 = stack.pop();
    num2 = stack.pop();

    stack.push(num2);
    stack.push(num1);
    cout<<"Numbers after Swap:"<<endl;
    stack.display();

    /* num1 = stack.pop();
    num2 = stack.pop();

    cout << "After swapping, the numbers are: "<<endl << num1 << endl << num2 << endl;

    return 0;
    */
}
