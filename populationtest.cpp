// Mathew Abraham mga2267

#include "infect_lib.hpp"
#include <iostream>
using std::cout;

int main() {
    int pop_size = 15;
    Population population(pop_size);    
    cout << "Size of population = " << pop_size << '\n';
    population.random_infection();
    int step = 1;
    for ( ; ; step++) {

        cout << "In step " << step << " #sick: " << population.count_infected();
        population.print();
        cout << '\n';
        if (population.count_infected() == 0) break;
        population.update();
    }
}