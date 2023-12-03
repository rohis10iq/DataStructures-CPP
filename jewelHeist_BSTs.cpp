#include <iostream>
#include <string>
using namespace std;

struct Gem {
    string name;
    int power;
    Gem* left;
    Gem* right;

    Gem(const string& n, int p) : name(n), power(p), left(nullptr), right(nullptr) {}
};

int X = 100;

Gem* insertGem(Gem* root, const string& name, int power) {
    if (root == nullptr) {
        return new Gem(name, power);
    }
    if (power < root->power) {
        root->left = insertGem(root->left, name, power);
    } else if (power > root->power) {
        root->right = insertGem(root->right, name, power);
    }
    return root;
}


void displayGems(Gem* root, int order) {
    if (root == nullptr) {
        return;
    }
    if (order == 1) 
    {
        displayGems(root->left, 0);
        cout <<"["<< root->name << " (" << root->power << ")] ";
        displayGems(root->right, 0);
    } else if (order == 2) 
    {
        cout <<"["<< root->name << " (" << root->power << ")] ";
        displayGems(root->left, 1);
        displayGems(root->right, 1);
    } else 
    {
        displayGems(root->left, 2);
        displayGems(root->right, 2);
        cout <<"["<< root->name << " (" << root->power << ")] ";
    }
}


Gem* searchGem(Gem* root, int power) {
    if (root == nullptr || root->power == power) {
        return root;
    }
    if (power < root->power) {
        return searchGem(root->left, power);
    }
    return searchGem(root->right, power);
}


Gem* findMaxPowerGem(Gem* root) {
    if (root == nullptr || root->right == nullptr) {
        return root;
    }
    return findMaxPowerGem(root->right);
}


Gem* pluckGem(Gem* root, int power, int& bagPower, bool& bagFull) {
    
    if (root == nullptr) {
        return nullptr;
    }

    if (power < root->power) {
        root->left = pluckGem(root->left, power, bagPower, bagFull);
    } else if (power > root->power) {
        root->right = pluckGem(root->right, power, bagPower, bagFull);
    } else {
        bagPower += root->power;
        if (bagPower <= X) {
            cout << "You added " << root->name << " (" << root->power << ") to your bag." <<endl;
        }
        else {
            bagFull = true;
            cout << "You LOST! Your bag burst. Now RUN and save yourself from the WITCH!" <<endl;
            return nullptr;
        }
        return nullptr;
    }

    return root;
}



int main() {
    Gem* root = nullptr;
    root = insertGem(root, "Diamond", 50);
    root = insertGem(root, "Ruby", 30);
    root = insertGem(root, "Sapphire", 70);
    root = insertGem(root, "Pearl", 40);
    root = insertGem(root, "Opal", 10);
    root = insertGem(root, "Garnet", 60);
    root = insertGem(root, "Zircon", 20);
    root = insertGem(root, "Jade", 5);

    int bagPower = 0;
    bool bagFull = false;

    while (bagPower < X) {
        cout << "Your current bag power: " << bagPower<<endl;
        cout << "1. Display the magical tree" <<endl;
        cout << "2. Search for a gem by specifying its power" <<endl;
        cout << "3. Find the gem with the highest magical power" <<endl;
        cout << "4. Pluck (remove) a gem from the BST and put it in your bag" <<endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int order;
                cout << "Select order to display (1: In-order, 2: Pre-order, 3: Post-order): ";
                cin >> order;
                if(order==1) {
                    cout<<"Magical Tree (In-Order): "<<endl;
                }
                else if(order==2) {
                    cout<<"Magical Tree (Pre-Order): "<<endl;
                }
                else {
                    cout<<"Magical Tree (Post-Order): "<<endl;
                }
                displayGems(root, order);
                cout <<endl;
                break;
            }
            case 2: {
                int power;
                cout << "Enter the power of the gem you want to search: ";
                cin >> power;
                Gem* gem = searchGem(root, power);
                if (gem) {
                    cout << "Found gem: " << gem->name << " (" << gem->power << ")" <<endl;
                } else {
                    cout << "Gem not found!" <<endl;
                }
                break;
            }
            case 3: {
                Gem* maxPowerGem = findMaxPowerGem(root);
                cout << "Gem with the highest power: [" << maxPowerGem->name << " (" << maxPowerGem->power << ")]" <<endl;
                break;
            }
            case 4: {
                int power;
                cout << "Enter the power of the gem you want to pluck: ";
                cin >> power;
                root = pluckGem(root, power, bagPower, bagFull);
                break;
            }
            default:
                cout << "Invalid choice. Try again." <<endl;
                break;
        }

        if (bagFull) {
            break;
        }
    }

    if (bagPower == X) {
        cout<<"You WIN! Now RUN! The WITCH is after You!"<<endl;
    }

    return 0;
}
