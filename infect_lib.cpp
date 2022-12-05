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

void Person::vaccinate() {
    state_ = -2;
}

// -------------------------------
// Population class implementation
// -------------------------------

Population::Population(int npeople) {
    npeople_ = npeople;
    population_.resize(npeople);
    probability_of_transfer_ = 0;
}

void Population::random_infection() {
    std::random_device r;
    std::uniform_int_distribution<int> distribution(0,npeople_-1);
    bool infection_failed = true;
    int random_person;
    while (infection_failed) {
        random_person = distribution(r);
        if (population_[random_person].is_vaccinated()) continue;
        population_[random_person].infect(5);
        infection_failed = false;
    }
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
    std::random_device r;
    std::uniform_real_distribution<float> distribution(0.,1.);
    vector<int> people_to_infect;
    for (int i = 0; i < npeople_; i++) {
        if (population_[i].is_susceptible()) {
            if (!(distribution(r) <= probability_of_transfer_)) continue;
            if (i==0) {
                if (population_[i+1].is_sick()) people_to_infect.push_back(i);
            }
            else if (i == npeople_-1) {
               if (population_[i-1].is_sick()) people_to_infect.push_back(i);
            }
            else if (population_[i-1].is_sick() || population_[i+1].is_sick()) people_to_infect.push_back(i);
        }
        else if (population_[i].is_sick()) population_[i].update();
    }
    for (int j = 0; j < people_to_infect.size(); j++) {
            population_[people_to_infect[j]].infect(5);
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
        if (person.is_vaccinated()) std::cout << " V";
        
    }
}

void Population::set_probability_of_transfer(double probability) {
    // if probability is not between 0 and 1 exit
    if (probability < 0.0 || probability > 1.0) {
        std::cout << "[Error]: please enter a probability between 0 and 1" << '\n';
        exit(1);
    }
    probability_of_transfer_ = probability;
}

void Population::vaccinate(double proportion) {
    // if proportion is not between 0 and 1 exit
    if (proportion < 0.0 || proportion > 1.0) {
        std::cout << "[Error]: please enter a proportion between 0 and 1" << '\n';
        exit(1);
    }
    int npeople_vaccinated = int(proportion * npeople_);
    int count = 0;
    int random_person;
    std::random_device r;
    std::uniform_int_distribution<int> distribution(0,npeople_-1);
    while (count < npeople_vaccinated) {
        random_person = distribution(r);
        if (population_[random_person].is_vaccinated()) continue;
        population_[random_person].vaccinate();
        count++;
    }
}