#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* previous;
};

void push(int stack[], int& top, int capacity, int value) {
    if (top == capacity - 1) {
        cout << "Stack Overflow" <<endl;
        return;
    }
    stack[++top] = value;
}

int pop(int stack[], int& top) {
    if (top == -1) {
        cout << "Stack Underflow" <<endl;
        return -1;
    }
    return stack[top--];
}


Node* reverseGroup(Node* head, int k) {
    if (head == nullptr || k <= 1) {
        return head;
    }

    Node* current = head;
    Node* newHead = nullptr;
    Node* prevTail = nullptr;

    
    int* stack = new int[k];
    int top = -1;

    while (current != nullptr) {
        int count = 0;
        Node* groupStart = current;

        
        while (current != nullptr && count < k) {
            push(stack, top, k, current->data);
            current = current->next;
            count++;
        }

        if (count != k) {
            if (prevTail != nullptr) {
                prevTail->next = groupStart;
                groupStart->previous = prevTail;
            } else {
                newHead = groupStart;
            }
        } else {
            if (prevTail != nullptr) {
                prevTail->next = nullptr;
            }
            for (int i = 0; i < k; i++) {
                if (prevTail != nullptr) {
                    prevTail->next = new Node{pop(stack, top), nullptr, nullptr};
                    prevTail->next->previous = prevTail;
                    prevTail = prevTail->next;
                } else {
                    newHead = new Node{pop(stack, top), nullptr, nullptr};
                    prevTail = newHead;
                }
            }
        }
    } 
    while (top >= 0) {
        if (prevTail != nullptr) {
            prevTail->next = new Node{pop(stack, top), nullptr, nullptr};
            prevTail->next->previous = prevTail;
            prevTail = prevTail->next;
        } else {
            newHead = new Node{pop(stack, top), nullptr, nullptr};
            prevTail = newHead;
        }
    }
    delete[] stack;
    return newHead;
}
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout <<endl;
}
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;

    for (int i = 0; i < sizeof(elements) / sizeof(int); i++) {
        Node* newNode = new Node{elements[i], nullptr, nullptr};
        if (tail != nullptr) {
            tail->next = newNode;
            newNode->previous = tail;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    cout <<"Original List: ";
    printList(head);

    head = reverseGroup(head, k);

    cout <<"Reversed List: ";
    printList(head);

    return 0;
}
