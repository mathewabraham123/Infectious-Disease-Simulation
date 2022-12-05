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
    cout << '\n';
    cout << "Size of population: " << pop_size << '\n';
    population.set_probability_of_transfer(probability_of_transfer);
    population.vaccinate(proportion_vaccinated);
    population.random_infection();
    int step = 0;
    bool nobody_infected = false;
    while (!(nobody_infected)) {
        step++;
        if (pop_size < 51) {
            cout << "In step " << setw(5) << step << " #sick: " << setw(5) << population.count_infected();
            population.print();
            cout << '\n';
        }        
        if (population.count_infected() == 0) nobody_infected = true;
        population.update();
    }
    cout << "Contacts per day: 6" << '\n';
    cout << "Probability of transmission: " << probability_of_transfer << '\n';
    cout << "Percentage of population vaccinated: " << proportion_vaccinated << '\n';
    cout << "Total steps: " << step << '\n';
    cout << '\n';
    
    return 0;
}