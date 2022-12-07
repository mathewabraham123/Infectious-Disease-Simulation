// Mathew Abraham mga2267

#include <string>
#include <vector>
#pragma once
using std::string;
using std::vector;

class Virus
{
public:
    Virus();                                                    // constructor
    int get_infection_period();                                 // returns infection period
    void update();                                              // update transmission count and/or variant count
    void set_mutation_rate(int mutation_rate);                  // set mutation rate to a different number of transmissions
    int get_variant();                                          // get variant count
private:
    int infection_period_;                                      // number of days person is infected for
    int variant_;                                               // number representing variant
    int transmissions_;                                         // number of transmissions of the variant
    int mutation_rate_;                                         // number of transmissions required for mutation
};

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
    bool is_immune(int variant);                                // check if person is immune to variant
    void infect(Virus &virus);                                  // infect person with virus information
private:
    int state_;                                                 // person's state represented by an integer
    int recovered_variants_;                                    // number of variants the person has recovered from
};


class Population
{
public:
    Population(int npeople, Virus virus);                       // constructor
    void random_infection();                                    // infect a random person
    int count_infected();                                       // return number of people infected
    void update();                                              // update all persons in population
    void print();                                               // print out population
    void set_probability_of_transfer(double probability);       // set probability of disease transmission upon contact
    void vaccinate(double proportion);                          // set a proportion of the population's states to vaccinated
    int count_affected();                                       // returns number of people ever infected
    Virus pop_virus;                                            // virus infecting the population
private:  
    int npeople_;                                               // number of people in the population
    vector<Person> population_;                                 // vector of persons representing the population
    double probability_of_transfer_;                            // probability of disease transmission upon contact
    int random_int(int max);                                    // return random integer between 0 and max
    double random_fraction();                                   // return random fraction as a decimal
    int naffected_;                                             // number of people ever infected
    int ninfected_;                                             // number of people currently infected
};

