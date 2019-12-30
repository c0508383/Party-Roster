#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include "Party.h"
using namespace std;

int main(){
    std::string filename, date, location, organizer, s;
    int maxAttendees;
    std::cin >> filename;
    std::ifstream input(filename);

    std::getline(input,s);
    date = s;

    std::getline(input,s);
    location = s;

    std::getline(input,s);
    organizer = s;

    std::getline(input,s);
    maxAttendees = stoi(s);

    Party p(date,location,organizer,maxAttendees);

    while(getline(input,s)){
        p.addAttendee(s);
    }

    p.print();

    return 0;
}