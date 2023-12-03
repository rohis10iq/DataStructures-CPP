#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Node{
    public:
    string value;
    Node *next=NULL;
    

    Node(string value){
        this->value = value;
    }
};

class PlayList{
    private:
    Node *head;
    int length;
    public:
    PlayList(){
        head=NULL;
        length=0;
    }

    void insertSong(int position, string value){
        Node *newNode = new Node(value);
        if(head == NULL)
        {
            head = newNode;
        }
        else 
        {
            Node *current = head;
            while(current->next != NULL)
                {
                    current = current->next;
                }
                current->next = newNode;
        }
        
    /*This function works fine when inserting the first song but 
    then if you wanna add the song at the 1st position again then the first song is overridden.
    And then in the menuDrive() Function if the user wants to add te song to the last position of the playlist then there is a problem in this code 
    And then if the user selects to the position of the song there is an issue there aswell.*/
    }
    void Start(string value){
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            head->value = value;
        }
    }

    void End(string value){
        Node *newNode = new Node(value);
        if (head == NULL)
        { 
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void deleteSong(int position){
        if (position < 1 || position > length) {
            cout << "Invalid Position";
        }
        else {
            if (position == 1) {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            else {
                Node *curr = head;
                for (int i = 1; i < position - 1; i++) {
                    curr = curr->next;
                }
                Node *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            length--;
        }
    
    }

    void searchSong(string value){
        
        bool found=false;
        Node *curr=head;
        while(curr!=NULL)
        {
            if(curr->value==value){
                cout<<"Song found"<<endl;
                found=true;
            }
            curr=curr->next;
        }
        if(found==false)
        {
            cout<<"Song not found"<<endl;
        }
        
    }

    void updateSong(int position, string value){
        if (position < 1 || position > length) {
            cout << "Invalid Position";
        }
        else {
            Node *curr = head;
            for (int i = 1; i < position; i++) {
                curr = curr->next;
            }
            curr->value = value;
        }
    }

    void printList(){
        Node *curr=head;
        while(curr!=NULL){
            cout<<curr->value<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }

    void playPlayList(PlayList& playlist) {
        if (playlist.head == nullptr) {
            cout << "Playlist is empty. Add songs to play." << endl;
            return;
        }

        Node* currentSong = playlist.head;
        bool playing = true;

        while (playing) {
            cout << "Now playing: " << currentSong->value << endl;
            cout << "Playback Options:" << endl;
            cout << "1) Next Song" << endl;
            cout << "2) Pause" << endl;
            cout << "3) Quit Playlist" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                if (currentSong->next != nullptr) {
                    currentSong = currentSong->next;
                }
                else {
                    cout << "End of playlist reached. Restarting." << endl;
                    currentSong = playlist.head;
                }
                break;

            case 2:
                cout << "Playback paused. Press any key to resume." << endl;
                cin.ignore();
                cin.get(); 
                break;

            case 3:
                cout << "Quitting playlist." << endl;
                playing = false;
                break;

            default:
                cout << "Invalid option. Please choose a valid option." << endl;
                break;
            }
        }
    }

};

void menuDrive(){

    PlayList Song;
    int choice;
    int songPosition;
    string songName;
    
    cout<<"Select Option:(1 to 6)"<<endl;
    cout<<"1) Add Song."<<endl;
    cout<<"2) Delete Song."<<endl;
    cout<<"3) Print Playlist."<<endl;
    cout<<"4) Search for Song in Playlist."<<endl;
    cout<<"5) Play the Playlist."<<endl;
    cout<<"6) Update."<<endl;

    cin>>choice;

    if(choice<1 || choice>6){
        cout<<"Invalid Option(Please Select from 1 to 6)"<<endl;
        menuDrive();
    }
    else if(choice==1){
        
        
        cout<<"Enter Song Name: ";
        cin.ignore();
        getline(cin, songName);
        cout<<"How much do you like this song?(Choose from 1 to 3)"<<endl;
        cout<<"1) My Top Favorite."<<endl;
        cout<<"2) My Least Favorite."<<endl;
        cout<<"3) In Between(Let me choose position)."<<endl;

        cin>>songPosition;
        cin.ignore();
    
        if(songPosition==1){
            Song.Start(songName);
        }
        else if(songPosition==2){
            Song.End(songName);
        }
        else if(songPosition==3){
            int positionMiddle;
            cout<<"Choose position";
            cin>>positionMiddle;
            Song.insertSong(positionMiddle, songName);
        }
        Song.printList();
    }
    
    else if(choice==2){
        int deletePosition;
        cout<<"Enter the position of the song you wanna Delete: ";
        cin>>deletePosition;
        Song.deleteSong(deletePosition);
        Song.printList();
        
        Song.printList();

    }
    else if(choice==3){
        Song.printList();
    }
    else if(choice==4){
        cout<<"Enter Song Name: ";
        cin>>songName;
        Song.searchSong(songName);
        Song.printList();
    }
    else if(choice==5){
        Song.playPlayList(Song);
    }
    else if(choice==6){
        int updatePosition;
        string newSongName;
        cout<<"Enter Position: ";
        cin>>updatePosition;
        cout<<"Enter Song Name: ";
        cin>>newSongName;
        Song.updateSong(updatePosition, newSongName);
        Song.printList();
    }
    menuDrive();
    cout<<endl;
}

int main(){
    cout<<"Welcome To Spotify from Daraz!"<<endl;
    menuDrive();
    
}