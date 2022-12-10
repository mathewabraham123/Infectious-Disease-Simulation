// Mathew Abraham mga2267

#include "infect_lib.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
using std::ofstream;
using std::cout;
using std::cin;
using std::setw;

int main() {
    int pop_size;
    double proportion_vaccinated;
    pop_size = 10000;
    double probability_of_transfer = .2;
    int n_people_unvaccinated;
    ofstream myFile ("herdimmunity_data.out");
    for (int i = 0; i < 100; i+=1) {
        probability_of_transfer = i / 100.0;
        for (int j = 0; j < 100; j+=1) {
            Population population(pop_size);    
            population.set_probability_of_transfer(probability_of_transfer);
            proportion_vaccinated = j / 100.0;  
            n_people_unvaccinated = pop_size - int(pop_size * proportion_vaccinated);  
            population.vaccinate(proportion_vaccinated);
            population.random_infection();
            bool nobody_infected = false;
            while (!(nobody_infected)) {
                if (population.count_infected() == 0) nobody_infected = true;
                population.update();
            }
            if (population.count_affected() < int(n_people_unvaccinated * .05)) break;
        }
        myFile << probability_of_transfer << " " << proportion_vaccinated << '\n';
    }


    return 0;
}