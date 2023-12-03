#include<iostream>
#include<cstring>
using namespace std;

bool checkPalindrome(char *str){
    int length = strlen(str);
    char *start = str;
    char *end = str + length - 1;

    while(start < end){
        if(*start != *end){
            return false;
        }
        start++;
        end--;
    }
}

int checkFrequency(char *str, char target){
    int count = 0;
    while(*str !='\0'){
        if(*str == target){
            count++;
        }
        str++;
    }
    return count;
}

int main(){
    char input[100];
    cout<<"Enter a String without spaces: ";
    cin>> input;

    while(true){
        cout<<"1. Check if the string is palindrome."<<endl;
        cout<<"2. Count the frequency of a certain character."<<endl;
        cout<<"3. Exit Program"<<endl;

        int choice;
        cin>> choice;

        int frequency;
        char target;
        switch(choice) {
            case 1: 
                if(checkPalindrome(input)){
                    cout<<"The entered string is a Palindrome."<<endl;
                }
                else{
                    cout<<"The entered string is not a Palindrome."<<endl;
                }
                break;

            case 2:
                cout<<"Enter Character to count: "<<endl;
                cin>>target;
                frequency = checkFrequency(input, target);
                cout<<"The Frequency of "<<target<<" is "<<frequency<<"."<<endl;
                break;
            case 3:
                cout<<"Exiting Program."<<endl;
                return 0;
                break;

            default:
                cout<<"Inavlid Input(Enter only 1 2 or 3)"; 
                break;
        }       
    }
}