#include <iostream>

using namespace std;

const int gridSize = 3;

void printGrid(char grid[][gridSize]) {
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout <<endl;
    }
}

int main() {
    
    char grid[gridSize][gridSize];

    
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (i == gridSize / 2 && j == gridSize / 2) {
                grid[i][j] = 'o'; 
            } else {
            
                grid[i][j] = (rand() % 2 == 0) ? '-' : 'x';
            }
        }
    }


    printGrid(grid);

    int positionX = gridSize / 2;
    int positionY = gridSize / 2; 
    int *ptrX = &positionX;
    int *ptrY = &positionY;


    while (true) {
        int move;
        int *ptrMove = &move;
        cout<<"Current Position = o"<<endl;
        cout << "Choose a move. You are standing in the middle of the grid. "<<endl;
        cout << "If You hit x you'll Lose."<<endl;
        cout<<"1). Top"<<endl;
        cout<<"2). Bottom"<<endl;
        cout<<"3). Left"<<endl;
        cout<<"4). Right"<<endl;
        cin >> *ptrMove;

        char newPosition = 'o'; 
        char *ptrPosition = &newPosition; 

        
        if (*ptrMove == 1 && *ptrX > 0) {
            *ptrPosition = grid[*ptrX - 1][*ptrY];
            *ptrX--;
        } else if (*ptrMove == 2 && *ptrX < gridSize - 1) {
            *ptrPosition = grid[*ptrX + 1][*ptrY];
            *ptrX++;
        } else if (*ptrMove == 3 && *ptrY > 0) {
            *ptrPosition = grid[*ptrX][*ptrY - 1];
            *ptrY--;
        } else if (*ptrMove == 4 && *ptrY < gridSize - 1) {
            *ptrPosition = grid[*ptrX][*ptrY + 1];
            *ptrY++;
        }

        
        if (*ptrPosition == '-') {
            cout << "Yayy, you WIN!" <<endl;
            cout<<"You moved to: "<<*ptrPosition<<endl;
            break;
        } else if (*ptrPosition == 'x') {
            cout << "COLLISION! You LOSE!" <<endl;
            cout<<"You moved to:"<<*ptrPosition<<endl;
            break;
        }

        
        grid[*ptrX][*ptrY] = *ptrPosition;

        
        printGrid(grid);

        ptrY = NULL;
        ptrX = NULL;
        ptrPosition = NULL;
        ptrMove = NULL;
    }

    return 0;
}
