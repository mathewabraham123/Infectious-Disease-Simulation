// Mathew Abraham mga2267

#include <string>
#pragma once
using std::string;

class Person
{
public:
    Person();                           // constructor
    string status_string();             // return description of person's state as a string
    void update();                      // update person's status to next day
    void infect(int n);                 // infect person so that disease runs for n days
    bool is_stable();                   // check whether or not person has been sick and is recovered
private:
    int state_;                         // person's state represented by an integer
    bool is_susceptible();              // check if person is susceptible
    bool is_sick();                     // check if person is sick
    bool is_vaccinated();               // check if person is vaccinated
};