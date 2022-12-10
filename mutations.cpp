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
    int pop_size = 10000;
    double proportion_vaccinated;
    double probability_of_transfer = .4;
    int mutation_rate;

    ofstream myFile ("vac_vs_mutationrate.out");
    for (int i = 1; i < 10000; i+=100) {
        for (int j = 100; j > 0; j--) {
            Virus virus;
            mutation_rate = i;
            virus.set_mutation_rate(mutation_rate);
            Population population(pop_size, virus);    
            population.set_probability_of_transfer(probability_of_transfer);
            proportion_vaccinated = j / 100.0;    
            population.vaccinate(proportion_vaccinated);

            population.random_infection();
            bool nobody_infected = false;
            bool virus_mutated = false;
            while (!(nobody_infected)) {
                if (population.count_infected() == 0) nobody_infected = true;
                population.update();
                if (population.pop_virus.get_variant() > 0) {
                    virus_mutated = true;
                    break;
                }
            }
            if (virus_mutated) break;
        }
        myFile << mutation_rate << " " << proportion_vaccinated << '\n';
    }


    
    return 0;
}