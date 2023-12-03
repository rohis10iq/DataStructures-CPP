#include <iostream>
#include <cstring>

using namespace std;

class ArrayList {
private:
    char* data;
    int capacity;
    int size;

public:
    ArrayList(int initialCapacity = 10) {
        capacity = initialCapacity;
        data = new char[capacity];
        size = 0;
    }

    ~ArrayList() {
        delete[] data;
    }

    void insert(char c, int index) {
        if (size == capacity) {
            
            capacity *= 2;
            char* newData = new char[capacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }

        
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }

        
        data[index] = c;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds" <<endl;
            return;
        }

        
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }

        size--;
    }

    void printList() const {
        for (int i = 0; i < size; ++i) {
            cout << data[i];
        }
        cout <<endl;
    }

    char get(int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds" <<endl;
            return '\0'; 
        }

        return data[index];
    }

    int search(char c) const {
        for (int i = 0; i < size; ++i) {
            if (data[i] == c) {
                return i; 
            }
        }

        return -1;
    }

    
};

int main() {
    ArrayList arr;
    const char* target = "fariba";


    cout << "Initial sequence: ";
    arr.printList();


    cout << "Final sequence: ";
    arr.printList();

    return 0;
}
