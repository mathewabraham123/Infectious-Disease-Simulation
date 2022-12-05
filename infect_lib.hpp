// Mathew Abraham mga2267

#include <string>
#include <vector>
#pragma once
using std::string;
using std::vector;

class Person
{
public:
    Person();                                                   // constructor
    string status_string();                                     // return description of person's state as a string
    void update();                                              // update person's status to next day
    void infect(int n);                                         // infect person so that disease runs for n days
    bool is_stable();                                           // check whether or not person has been sick and is recovered
    bool is_susceptible();                                      // check if person is susceptible
    bool is_sick();                                             // check if person is sick
    bool is_vaccinated();                                       // check if person is vaccinated
    void vaccinate();                                           // set state of person to vaccinated
private:
    int state_;                                                 // person's state represented by an integer
};

class Population
{
public:
    Population(int npeople);                                    // constructor
    void random_infection();                                    // infect a random person
    int count_infected();                                       // return number of people infected
    void update();                                              // update all persons in population
    void print();                                               // print out population
    void set_probability_of_transfer(double probability);       // set probability of disease transmission upon contact
    void vaccinate(double proportion);                          // set a proportion of the population's states to vaccinated
private:  
    int npeople_;                                               // number of people in the population
    vector<Person> population_;                                 // vector of persons representing the population
    double probability_of_transfer_;                            // probability of disease transmission upon contact
};