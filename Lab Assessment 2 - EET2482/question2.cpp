/*
    RMIT University Vietnam
    Course: EEET2482 Software Engineering Design
    Semester: 2022A
    Lab Assessment: 1
    Author: Dao Kha tuan
    ID: s3877347
    Compiler used: gcc 8.1.0
    Created  date: 07/05/2022
    Acknowledgement: None
*/

#include <iostream>

using std::string;

class City {
    private:
        string name;
        double days;
        City *nextCity = NULL;    
    public:
        City(){}
        City(string name, double days) {
            this->name = name;
            this->days = days;
        }

        // function to link the current city to next city
        void linkNextCity(City *nextCity) {
            this->nextCity = nextCity;
        }

        void showInfo() {
            std::cout << name << ": ";

            // show "days" if the number of days is greater than 1
            if (days > 1) {
                std::cout << days << " days" << std::endl;
            } else {
                std::cout << days << " day" << std::endl;
            }
        }

        friend void displayTripPlan(City *&head);
        friend void showLongestShortestTime(City *&head);
        friend bool insertCity(City *&head, City *newCity, City *latterCity);
};

// function to display the whole trip plan
void displayTripPlan(City *&head) {
    City *temp = head;

    // move to the next city until the end of linkedlist
    while (temp != NULL) {
        temp->showInfo();
        temp = temp->nextCity;
    }
}

void showLongestShortestTime(City *&head) {
    City *temp = head;

    // if there is only 1 ciy, show this message
    if (temp->nextCity == NULL) {
        std::cout << "Only 1 city with total day is: " << temp->days << std::endl;
    }

    double longestTime = temp->days + temp->nextCity->days;
    double shortestTime = longestTime;

    // city with the total days of the next city that is longest
    City *longestTimeCity = temp;

    // city with the total days of the next city that is shortest
    City *shortestTimeCity = temp;

    while (temp->nextCity != NULL) { // iterate if the current has the next city
        double totalTime = temp->days + temp->nextCity->days;

        // if the total time of the current city and the next city is larger than the longest time, assign to longest time
        if (totalTime > longestTime) {
            longestTime = totalTime;
            longestTimeCity = temp; // update the city 
        }

        // if the total time of the current city and the next city is shorter than the shorter time, assign to shortest time
        if (totalTime < shortestTime) {
            shortestTime = totalTime;
            shortestTimeCity = temp; // update the city
        }

        temp = temp->nextCity; // move to next city
    }

    // display the result
    std::cout << "2 adjacent citites with total longest time: " << longestTime << " days are "
              << longestTimeCity->name <<  " and " << longestTimeCity->nextCity->name << std::endl; 

    std::cout << "2 adjacent citites with total shortest time: " << shortestTime << " days are "
              << shortestTimeCity->name <<  " and " << shortestTimeCity->nextCity->name << std::endl;    
}

bool insertCity(City *&head, City *newCity, City *latterCity) {

    if (head == latterCity) { // if the latter city is the head node, replace the head node with the new city
        newCity->linkNextCity(head);
        head = newCity;
        return true;
    }

    City *priorCity = head;
    while (priorCity->nextCity != NULL) {
        if (priorCity->nextCity == latterCity) {
            newCity->linkNextCity(priorCity->nextCity); // link the new city to the latter city
            priorCity->linkNextCity(newCity); // link the prior city to the new city
            return true;
        }

        priorCity = priorCity->nextCity;
    }

    return false;
}

int main(){
    City hue("Hue", 2.5), daNang("Da Nang", 1.5), nhaTrang("Nha Trang", 4), daLat("Da Lat", 2), canTho("Can Tho", 1);

    City *head = &hue;
    hue.linkNextCity(&daNang);
    daNang.linkNextCity(&nhaTrang);
    nhaTrang.linkNextCity(&daLat);
    daLat.linkNextCity(&canTho);
    City *tail = &canTho;

    // question a
    std::cout << "Trip plan: " << std::endl;
    displayTripPlan(head);

    // question b
    std::cout << std::endl;
    showLongestShortestTime(head);

    // question c
    City saiGon("Sai Gon", 2);
    insertCity(head, &saiGon, &canTho);

    std::cout << "\nTrip plan after inserting Sai Gon before Can Tho: " << std::endl;
    displayTripPlan(head);
    return 0;
}