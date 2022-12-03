// Mathew Abraham mga2267

#include "infect_lib.hpp"
using std::to_string;

Person::Person() {
    state_ = 0;
}

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
