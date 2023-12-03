#include <iostream>

// Define a structure for a node in the linked list
struct Node {
    int info;
    Node* next;
};

class SortedLinkedList {
private:
    Node* head;

public:
    // Constructor
    SortedLinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~SortedLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to add a new node to the sorted linked list
    void add(int value) {
        Node* newNode = new Node;
        newNode->info = value;
        newNode->next = nullptr;

        // If the list is empty or the new node should be inserted at the beginning
        if (head == nullptr || value < head->info) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            Node* previous = nullptr;

            // Find the appropriate position to insert the new node
            while (current != nullptr && current->info <= value) {
                previous = current;
                current = current->next;
            }

            // Insert the new node in the middle or at the end of the list
            newNode->next = current;
            previous->next = newNode;
        }
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->info << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SortedLinkedList list;

    // Add elements to the sorted linked list
    list.add(5);
    list.add(2);
    list.add(8);
    list.add(1);
    list.add(4);
    list.add(3);

    // Display the sorted linked list
    list.display();

    return 0;
}
