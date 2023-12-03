#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Employee {
public:
    int ID;
    string name; 
    string designation; 
    Employee* right;
    Employee* left;
    int height;

    Employee(int ID, string name, string designation) {
        this->ID = ID;
        this->name = name;
        this->designation = designation;
        this->height = 1;

        this->right = NULL;
        this->left = NULL;
    }
};

Employee* newNode(int ID, string name, string designation) {
    Employee* root = new Employee(ID, name, designation);
    return root;
}

int heightFunction(Employee* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int maxHeightFunction(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int balanceFactor(Employee* node) {
    if (node == NULL) {
        return 0;
    }
    return heightFunction(node->left) - heightFunction(node->right);
}

Employee* rightRotate(Employee* NodeY) {
    Employee* NodeX = NodeY->left;
    Employee* NodeT = NodeX->right;

    NodeX->right = NodeY;
    NodeY->left = NodeT;

    NodeY->height = maxHeightFunction(heightFunction(NodeY->left), heightFunction(NodeY->right)) + 1;
    NodeX->height = maxHeightFunction(heightFunction(NodeX->left), heightFunction(NodeX->right)) + 1;

    return NodeX;
}

Employee* leftRotate(Employee* NodeX) {
    Employee* NodeY = NodeX->right;
    Employee* NodeT = NodeY->left;

    NodeY->left = NodeX;
    NodeX->right = NodeT;

    NodeX->height = maxHeightFunction(heightFunction(NodeX->left), heightFunction(NodeX->right)) + 1;
    NodeY->height = maxHeightFunction(heightFunction(NodeY->left), heightFunction(NodeY->right)) + 1;

    return NodeY;
}

Employee* addEmployee(Employee* root, int ID, string name, string designation) {
    if (root == NULL) {
        return newNode(ID, name, designation);
    }
    if (ID < root->ID) {
        root->left = addEmployee(root->left, ID, name, designation);
    } else if (ID > root->ID) {
        root->right = addEmployee(root->right, ID, name, designation);
    } else {
        return root; 
    }

    root->height = 1 + maxHeightFunction(heightFunction(root->left), heightFunction(root->right));

    int balance = balanceFactor(root);

    if (balance > 1 && ID < root->left->ID) {
        return rightRotate(root);
    }
    if (balance > 1 && ID > root->left->ID) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && ID > root->right->ID) {
        return leftRotate(root);
    }
    if (balance < -1 && ID < root->right->ID) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Employee* searchEmployees(Employee* root, int key) {
    if (root == NULL || root->ID == key) {
        return root;
    }
    if (root->ID > key) {
        return searchEmployees(root->left, key);
    }
    if (root->ID < key) {
        return searchEmployees(root->right, key);
    }
}

void modifyEmployee(Employee* root, int key) {
    Employee* employee = searchEmployees(root, key);
    if (employee != NULL) {
        cout << "Enter new Name for Employee (ID: " << key << "): ";
        cin.ignore(); 
        getline(cin, employee->name);
        cout << "Enter new Designation for Employee (ID: " << key << "): ";
    
        getline(cin, employee->designation);
        cout << "Employee information modified successfully." << endl;
    } else {
        cout << "Employee not found." << endl;
    }
}

Employee* findMinNode(Employee* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


Employee* removeEmployee(Employee* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->ID) {
        root->left = removeEmployee(root->left, key);
    } else if (key > root->ID) {
        root->right = removeEmployee(root->right, key);
    } else {
        if (root->left == NULL) {
            Employee* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Employee* temp = root->left;
            delete root;
            return temp;
        }

        Employee* temp = findMinNode(root->right);
        root->ID = temp->ID;
        root->name = temp->name;
        root->designation = temp->designation;  

        root->right = removeEmployee(root->right, temp->ID);
    }

    root->height = 1 + maxHeightFunction(heightFunction(root->left), heightFunction(root->right));

    int balance = balanceFactor(root);

    if (balance > 1 && balanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && balanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void displayChart(Employee* root) {
    
        if(root==NULL){
            return;
        }

        displayChart(root->left);
        displayChart(root->right);
        cout<<root->ID<<", "<<root->name<<", "<<root->designation<<endl;


    
}

void menuDrive(Employee*& root) {
    int choice;

    cout << "Hierarchy System!" << endl;
    do {
        cout << "Select an Option!" << endl;
        cout << "1) Add an Employee:" << endl;
        cout << "2) Search for Employee:" << endl;
        cout << "3) Remove an Employee:" << endl;
        cout << "4) Modify an Employee:" << endl;
        cout << "5) Display Organizational Chart:" << endl;
        cout << "6) Exit" << endl;

        cout << endl << "Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int ID;
                string name;
                string designation;
                cout << "Enter Employee ID: ";
                cin >> ID;
                cout << "Enter Employee Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Employee Designation: ";
                getline(cin, designation);
                root = addEmployee(root, ID, name, designation);
                break;
            }
            case 2: {
                int key;
                cout << "Enter Employee ID to Search: ";
                cin >> key;
                Employee* result = searchEmployees(root, key);
                if (result != NULL) {
                    cout << "Employee Found - ID: " << result->ID << ", Name: " << result->name << ", Designation: " << result->designation << endl;
                } else {
                    cout << "Employee not found." << endl;
                }
                break;
            }
            case 3: {
                int key;
                cout << "Enter Employee ID to Remove: ";
                cin >> key;
                root = removeEmployee(root, key);
                break;
            }
            case 4: {
                int key;
                cout << "Enter Employee ID to Modify: ";
                cin >> key;
                modifyEmployee(root, key);
                break;
            }
            case 5: {
                cout << "Organizational Chart:" << endl;
                displayChart(root);
                break;
            }
            case 6: {
                break;
            }
            default:
                cout << "Invalid Choice. Please try again." << endl;
        }
    } while (choice != 6);
}

int main() {
    Employee* root = NULL;

    menuDrive(root);

    return 0;
}
