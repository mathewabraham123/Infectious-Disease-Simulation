// Mathew Abraham mga2267

#include "infect_lib.hpp"
#include <random>
#include <iostream>
using std::to_string;

// ---------------------------
// Person class implementation
// ---------------------------

Person::Person() : state_(0) {};

string Person::status_string() {
    if (is_susceptible()) return "susceptible";
    if (is_vaccinated()) return "vaccinated";
    if (is_stable()) return "recovered";
    if (is_sick()) return "sick (" + to_string(state_) + " to go)";
}

void Person::update() {
    if (is_sick()) {
        state_--;
        if (state_ == 0) state_--;
    }
}

void Person::infect(int n) {
    if (is_susceptible()) {
        state_ = n;
    }
}

bool Person::is_stable() {
    return state_ == -1;
}
 
bool Person::is_susceptible() {
    return state_ == 0;
}

bool Person::is_sick() {
    return state_ > 0;
}

bool Person::is_vaccinated() {
    return state_ == -2;
}

// -------------------------------
// Population class implementation
// -------------------------------

Population::Population(int npeople) {
    npeople_ = npeople;
    population_.resize(npeople);
}

void Population::random_infection() {
    std::random_device r;
    std::uniform_int_distribution<int> distribution(0,npeople_-1);
    int random_person = distribution(r);
    population_[random_person].infect(5);
}

int Population::count_infected() {
    int ninfected = 0;
    for (int i = 0; i < npeople_; i++) {
        Person person = population_[i];
        if (person.is_sick()) ninfected++;
    }
    return ninfected;
}

void Population::update() {
    for (int i = 0; i < npeople_; i++) {
        population_[i].update();
    }
}

void Population::print() {
    // if population size is large do not print
    if (npeople_ > 20) return;
    for (int i = 0; i < npeople_; i++) {
        Person person = population_[i];
        if (person.is_susceptible()) std::cout << " ?";
        if (person.is_sick()) std::cout << " +";
        if (person.is_stable()) std::cout << " -";
    }
}