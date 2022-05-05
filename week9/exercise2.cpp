#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm> // find
using std::string;
using std::vector;
class Facebooker{
    public:
        string name;
        vector<Facebooker*> friends = {};

        Facebooker(string name) {
            this->name = name;
        }

        void printFriendName() {
            std::cout << "All friends of " << this->name << ":" << std::endl;
            for (Facebooker* f : friends) {
                std::cout << f->name << std::endl;
            }

            std::cout << std::endl;
        }

        void addFriend(Facebooker &f) {
            // do not add itself
            if (this == &f) return;

            // if f is already a friend, do not need to add
            if (std::find(friends.begin(), friends.end(), &f) != friends.end()) return;

            // add friend at both side
            friends.push_back(&f);
            f.friends.push_back(this);
        }
        
        void findMutual(Facebooker &f) {
            std::cout << "Mutual friends between " << this->name << " and " << f.name << ":" << std::endl;
            for (Facebooker* fr : f.friends) {
                if (std::find(friends.begin(), friends.end(), fr) != friends.end()) {
                    std::cout << fr->name << std::endl;
                }
            }

            std::cout << std::endl;
        }

        void findFriendsOfFriend() {
            std::cout << "Friends of friends of: " << this->name << std::endl;
            for (Facebooker* eachFriend : friends) {
                for (Facebooker* fof : eachFriend->friends) {
                    if (fof != this) {
                        std::cout << fof->name << std::endl;
                    }
                }
            }

            std::cout << std::endl;
        }
};

int main(){
    Facebooker harry("Harry"), peter("Peter"), john("John"), luna("Luna");
    harry.addFriend(peter);
    harry.addFriend(john);
    peter.addFriend(luna);
    peter.addFriend(john);

    harry.printFriendName();
    luna.printFriendName();

    harry.findFriendsOfFriend();

    harry.findMutual(peter);
    
    return 0;
}