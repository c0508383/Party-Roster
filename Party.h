#ifndef PARTY_H
#define PARTY_H
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Party{
    public:
        //Constructors and destructor
        Party();
        Party(std::string date, std::string location, std::string organizer, int maxAttendees);
        Party(const Party& party);
        ~Party();

        //Operator fucntions
        Party& operator=(const Party& party);
        Party& operator+(const Party& party);
        
        //Attendee functions
        void addAttendee(std::string name);
        void deleteAttendee(std::string name);
        bool findAttendee(std::string name);
        
        //Print function
        void print();

        //Mutators
        void setDate(std::string date);
        void setLocation(std::string location);
        void setOrganizer(std::string organizer);
        //Accessors
        std::string getDate() const;
        std::string getLocation() const;
        std::string getOrganizer() const;
        int getMaxAttendees() const;
        int getNumAttendees() const;

    private:
        std::string date; // use format mm/dd/yyyy
        std::string location;
        std::string organizer;
        int maxAttendees;
        int numAttendees;
        std::string *attendees;   // holds a list of attendees with `maxAttendees` entries, out of which `numAttendees` are filled
};

#endif