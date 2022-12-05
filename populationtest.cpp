// Mathew Abraham mga2267

#include "infect_lib.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;

int main() {
    int pop_size;
    double probability_of_transfer;
    double proportion_vaccinated;
    cout << "Enter a population size:" << '\n';
    cin >> pop_size;
    cout << "Enter a number between 0 and 1 for the probability of transmission by contact:" << '\n';
    cin >> probability_of_transfer;
    cout << "Enter a number between 0 and 1 for the proportion of the population that is vaccinated:" << '\n';
    cin >> proportion_vaccinated;
    Population population(pop_size);    
    cout << "Size of population = " << pop_size << '\n';
    population.random_infection();
    population.set_probability_of_transfer(probability_of_transfer);
    population.vaccinate(proportion_vaccinated);
    int step = 1;
    for ( ; ; step++) {

        cout << "In step " << setw(5) << step << " #sick: " << setw(5) << population.count_infected();
        population.print();
        cout << '\n';
        if (population.count_infected() == 0) break;
        population.update();
    }
}