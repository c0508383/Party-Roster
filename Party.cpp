#include "Party.h"
using namespace std;

Party::Party(){
    this->date = "";
    this->location = "";
    this->organizer = "";

    this->maxAttendees = 30;
    this->numAttendees = 0;

    attendees = new std::string;
}
Party::Party(std::string date, std::string location, std::string organizer, int maxAttendees){
    this->date = date;
    this->location = location;
    this->organizer = organizer;

    if(maxAttendees > 0)
        this->maxAttendees = maxAttendees;
    else this->maxAttendees = 30;

    this->numAttendees = 0;
    
    attendees = new std::string;
}
Party::Party(const Party& party){
    date = party.getDate();
    location = party.getLocation();
    organizer = party.getOrganizer();
    maxAttendees = party.getMaxAttendees();
    numAttendees = party.getNumAttendees();

    attendees = new std::string;
    *attendees = *(party.attendees);
}
Party::~Party(){
    delete attendees;
}

//Operator fucntions
Party& Party::operator=(const Party& party){
    if (this != &party) {
        date = party.getDate();
        location = party.getLocation();
        organizer = party.getOrganizer();
        maxAttendees = party.getMaxAttendees();
        numAttendees = party.getNumAttendees();

        delete attendees;
        attendees = new std::string;
        *attendees = *(party.attendees);
    }

    return *this;
}
Party& Party::operator+(const Party& party){
    std::string *list2 = party.attendees;
    *attendees += "\n" + *list2;

    this->maxAttendees += party.getMaxAttendees();
    this->numAttendees += party.getNumAttendees();

    if(this->date != party.getDate()){
        this->date = "";
    }
    if(this->location != party.getLocation()){
        this->location = "";
    }
    if(this->organizer != party.getOrganizer()){
        this->organizer = "";
    }

    return *this;
}

//Attendee functions
void Party::addAttendee(std::string name){
    if(numAttendees < maxAttendees){
        if(!Party::findAttendee(name)){
            *attendees += "\n" + name;
            numAttendees++;
        }
    }
    else{
        std::cout << "Your party is already full!" << std::endl;
    }
}
void Party::deleteAttendee(std::string name){
    attendees->erase(attendees->find(name)-1, attendees->find(name) + name.length());
    numAttendees--;
}
bool Party::findAttendee(std::string name){
    if(attendees->find(name) != -1)
        return true;
    else
        return false;
}

//Print function
void Party::print(){
    std::cout << "Party details:" << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Location: " << location << std::endl;
    std::cout << "Organizer: " << organizer << std::endl;

    if(numAttendees == 0)
        std::cout << "List is empty! Invite more people to your party." << std::endl;
    else{
        std::cout << "Attendees list:" ;
        std::cout << *attendees << std::endl;
    }
}

//Mutators
void Party::setDate(std::string date){
    this->date = date;
}
void Party::setLocation(std::string location){
    this->location = location;
}
void Party::setOrganizer(std::string organizer){
    this->organizer = organizer;
}

//Accessors
std::string Party::getDate() const{
    return date;
}
std::string Party::getLocation() const{
    return location;
}
std::string Party::getOrganizer() const{
    return organizer;
}
int Party::getMaxAttendees() const{
    return maxAttendees;
}
int Party::getNumAttendees() const{
    return numAttendees;
}