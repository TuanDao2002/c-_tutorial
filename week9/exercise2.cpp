#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm> // find
using std::string;
using std::vector;
class Facebooker{
    public:
        string name;
        vector<Facebooker*> friends;

        Facebooker(string name, vector<Facebooker*> friends) {
            this->name = name;
            this->friends = friends;
        }

        void printFriendName() {
            for (Facebooker* f : friends) {
                std::cout << f->name << std::endl;
            }

            std::cout << std::endl;
        }

        void addFriend(Facebooker &f) {
            // do not add itself
            if (this == &f) return;

            // if f is already a friend, do not need to ask
            if (std::find(friends.begin(), friends.end(), &f) != friends.end()) return;

            // add friend at both side
            friends.push_back(&f);
            f.friends.push_back(this);
        }
        
        void findMutual(Facebooker &f) {
            for (Facebooker* fr : f.friends) {
                if (std::find(friends.begin(), friends.end(), fr) != friends.end()) {
                    std::cout << fr->name << std::endl;
                }
            }

            std::cout << std::endl;
        }
};

int main(){
    Facebooker f1("tuan1", vector<Facebooker*>());
    Facebooker f2("tuan2", vector<Facebooker*>());
    Facebooker f3("tuan3", vector<Facebooker*>());
    Facebooker f4("tuan4", vector<Facebooker*>());

    f1.addFriend(f2);
    f1.addFriend(f3);
    f1.addFriend(f4);
    std::cout << "Friends of f1:" << std::endl;
    f1.printFriendName();

    f2.addFriend(f3);
    f2.addFriend(f4);
    std::cout << "Friends of friends of f1:" << std::endl;
    for (Facebooker* f : f1.friends) {
        std::cout << "Friends of " << f->name << std::endl;
        f->printFriendName();
    }

    std::cout << "Mutual friends between f1 and f4:" << std::endl;
    f2.findMutual(f4);
    return 0;
}