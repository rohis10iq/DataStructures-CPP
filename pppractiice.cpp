#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char *str) {
    int length = strlen(str);
    char *start = str;
    char *end = str + length - 1;

    while (start < end) {
        if (*start != *end) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int countCharacter(char *str, char target) {
    int count = 0;
    while (*str != '\0') {
        if (*str == target) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char input[100];
    cout << "Enter a string without spaces: ";
    cin >> input;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Check if the string is palindrome.\n";
        cout << "2. Count the frequency of a certain character.\n";
        cout << "3. Exit.\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        char target;
        int frequency;

        switch (choice) {
            case 1:
                if (isPalindrome(input)) {
                    cout << "The entered string is a palindrome.\n";
                } else {
                    cout << "The entered string is not a palindrome.\n";
                }
                break;

            case 2:
                cout << "Enter the character to count: ";
                cin >> target;
                frequency = countCharacter(input, target);
                cout << "Frequency of '" << target << "' in the string: " << frequency << endl;
                break;

            case 3:
                cout << "Exiting the program.\n";
                
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    }
    return 0;
}
