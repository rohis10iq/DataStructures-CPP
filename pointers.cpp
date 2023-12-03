#include<iostream>
#include<cstring>

using namespace std;

int main(){

    int *intptr = new int;
    char *charptr = new char[8];

    *intptr = 360;
    strcpy(charptr, "datastructure");

    for(int i = 0; i< sizeof(*charptr); i++){
        cout<<*charptr;
        charptr++;
    }
    
    delete intptr;
    delete charptr;

    return 0;
}