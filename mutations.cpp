#include "infect_lib.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
using std::ofstream;
using std::cout;
using std::cin;
using std::setw;

int main() {
    int pop_size = 1000;
    double proportion_vaccinated = .4;
    double probability_of_transfer = .4;
    double avg_steps;
    int mutation_rate;

    ofstream myFile ("mutationrate_vs_steps.out");
    for (int i = 1000; i > 0; i-=1) {
        avg_steps = 0;
        Virus virus;
        mutation_rate = i;
        virus.set_mutation_rate(i);
        for (int j = 0; j < 10; j++) {
            Population population(pop_size, virus);    
            population.set_probability_of_transfer(probability_of_transfer);
            population.vaccinate(proportion_vaccinated);

            population.random_infection();
            int step = 0;
            bool nobody_infected = false;
            while (!(nobody_infected)) {
                step++;     
                if (population.count_infected() == 0) nobody_infected = true;
                population.update();
                if (i == 599) {
                    cout << population.count_infected() << '\n';
                }
            }
            avg_steps += step;            
        }
        avg_steps = avg_steps / 10;
        myFile << mutation_rate << " " << avg_steps << '\n';
        cout << mutation_rate << " " << avg_steps << '\n';
    }


    
    return 0;
}