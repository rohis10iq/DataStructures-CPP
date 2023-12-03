#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};


Node* insert(Node* head, int value, int position) {
    Node* newNode = new Node();
    newNode->info = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode; 
        
        Node* current = head;
        while (current->next != head) {
            current= current->next;
        }
        current->next = newNode;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}
Node* deleteNode(Node* head, int position) {
    if (head == nullptr) {
        return head;
    }

    if (position == 1) {
        Node* temp = head;
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        head = head->next;
        current->next = head;
        delete temp;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        if (current->next != head) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    return head;
}
void update(Node* head, int oldValue, int newValue) {
    Node* current = head;
    do {
        if (current->info == oldValue) {
            current->info = newValue;
            cout << "Value Updated Successfully." <<endl;
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "Value Not Found In The List." <<endl;
}


bool isPalindrome(Node* head) {
    if (head == nullptr) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* secondHalf = slow->next;
    slow->next = head;

    Node* prev = nullptr;
    Node* current = secondHalf;
    Node* next;

    while (current != head) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    secondHalf = prev;

    Node* firstHalf = head;
    while (secondHalf != head) {
        if (firstHalf->info != secondHalf->info) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}
void displayList(Node* head) {
    if (head == nullptr) {
        cout <<"List is empty." <<endl;
        return;
    }
    Node* current = head;
    do {
        cout <<current->info <<" ";
        current = current->next;
    } while (current != head);
    cout <<endl;
}

void menuDrive(){
    Node* head = nullptr;
    int choice;

        cout << "\nCircular Linked List Menu:\n";
        cout << "1. Insert a value\n";
        cout << "2. Delete a value\n";
        cout << "3. Update a value\n";
        cout << "4. Check if palindrome\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            
                int value, position;
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position (1 for beginning): ";
                cin >> position;
                head = insert(head, value, position);
                menuDrive();
        }
        else if(choice == 2){
            int deletePosition;
                cout << "Enter the position of the value to delete: ";
                cin >> deletePosition;
                head = deleteNode(head, deletePosition);
                menuDrive();
        }  
        else if(choice == 3){
            int oldValue, newValue;
                cout << "Enter the old value: ";
                cin >> oldValue;
                cout << "Enter the new value: ";
                cin >> newValue;
                update(head, oldValue, newValue);
                menuDrive();
        } 
        else if(choice == 4){
            if (isPalindrome(head)) {
                    cout << "The list is a palindrome." <<endl;
                } else {
                    cout << "The list is not a palindrome." <<endl;
                }
                menuDrive();
        }   
        else if(choice == 5){
            displayList(head);
            menuDrive();
        }
        else{
            cout << "Invalid choice. Please try again." <<endl;
            menuDrive();
        }

}


int main() {
    
    menuDrive();
    return 0;
}
