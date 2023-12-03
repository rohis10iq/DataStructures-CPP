#include <iostream>
#include <string>
using namespace std;
class Song {
public:
    string title;
    Song* next;

    Song(const sstring& title) : title(title), next(nullptr) {}
};

class CircularLinkedList {
private:
    Song* currentSong;

public:
    CircularLinkedList() : currentSong(nullptr) {}

    ~CircularLinkedList() {
        if (!isEmpty()) {
            Song* current = currentSong->next;
            while (current != currentSong) {
                Song* temp = current;
                current = current->next;
                delete temp;
            }
            delete currentSong;
        }
    }

    bool isEmpty() const {
        return currentSong == nullptr;
    }

    void addSong(const string& title) {
        Song* newSong = new Song(title);
        if (isEmpty()) {
            currentSong = newSong;
            currentSong->next = currentSong; // Point to itself in a circular manner
        } else {
            newSong->next = currentSong->next;
            currentSong->next = newSong;
        }
    }

    void playCurrentSong() const {
        if (!isEmpty()) {
            cout << "Playing: " << currentSong->title <<endl;
        }
    }

    void playNextSong() {
        if (!isEmpty()) {
            currentSong = currentSong->next;
            playCurrentSong();
        }
    }
};

int main() {
    CircularLinkedList musicPlayer;

    musicPlayer.addSong("Song 1");
    musicPlayer.addSong("Song 2");
    musicPlayer.addSong("Song 3");

    musicPlayer.playCurrentSong(); // Play Song 1

    musicPlayer.playNextSong(); // Play Song 2
    musicPlayer.playNextSong(); // Play Song 3

    // Play the next song after the last song (Song 3), which should start from the beginning (Song 1)
    musicPlayer.playNextSong(); // Play Song 1

    return 0;
}
