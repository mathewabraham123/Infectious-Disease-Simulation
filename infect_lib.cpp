// Mathew Abraham mga2267

#include "infect_lib.hpp"
#include <random>
#include <iostream>
using std::to_string;
using std::cout;


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


Population::Population(int npeople) {
    npeople_ = npeople;
    population_.resize(npeople);
    probability_of_transfer_ = 0;
    naffected_ = 0;
    ninfected_ = 0;
}

int Population::random_int(int max) {
    static std::default_random_engine static_engine; 
    std::uniform_int_distribution<> ints(0,max); 
    return ints(static_engine);
}

double Population::random_fraction() {
    static std::default_random_engine static_engine; 
    std::uniform_real_distribution<> real_distribution(0.,1.);
    return real_distribution(static_engine);
}

void Population::random_infection() {
    bool infection_failed = true;
    int random_person;
    while (infection_failed) {
        random_person = random_int(npeople_-1);
        if (population_[random_person].is_vaccinated()) continue;
        population_[random_person].infect(5);
        infection_failed = false;
    }
    naffected_++;
    ninfected_++;
}

int Population::count_infected() {
    return ninfected_;
}

void Population::update() {
    int random_person;
    vector<int> originally_sick_people;
    for (int i = 0; i < npeople_; i++) {
        if (population_[i].is_sick()) originally_sick_people.push_back(i);
    }
    for (int j = 0; j < originally_sick_people.size(); j++) {
        for (int k = 0; k < 6; k++) {
            random_person = random_int(npeople_-1);
            if (population_[random_person].is_susceptible()) {
                if (random_fraction() <= probability_of_transfer_) {
                    population_[random_person].infect(5);
                    naffected_++;
                    ninfected_++;
                }
            }
        }
        population_[originally_sick_people[j]].update();
        if (population_[originally_sick_people[j]].is_stable()) ninfected_--;
    }
}

void Population::print() {
    if (npeople_ > 50) return;
    for (int i = 0; i < npeople_; i++) {
        Person person = population_[i];
        if (person.is_susceptible()) std::cout << " ?";
        if (person.is_sick()) std::cout << " +";
        if (person.is_stable()) std::cout << " -";
        if (person.is_vaccinated()) std::cout << " V";
        
    }
}

void Population::set_probability_of_transfer(double probability) {
    if (probability < 0.0 || probability > 1.0) {
        std::cout << "[Error]: please enter a probability between 0 and 1" << '\n';
        exit(1);
    }
    probability_of_transfer_ = probability;
}

void Population::vaccinate(double proportion) {
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

int Population::count_affected() {
    return naffected_;
}