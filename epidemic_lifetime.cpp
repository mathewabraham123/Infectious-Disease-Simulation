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
    double avg_steps;
    pop_size = 100000; // population of a city like Austin, TX
    // run simulations where transmission probability is .2
    double probability_of_transfer = .2;
    ofstream myFile1 ("vac_vs_steps1.out");
    for (int i = 0; i < 100; i+=1) {
        avg_steps = 0;
        for (int j = 0; j < 5; j++) {
            Population population(pop_size);    
            population.set_probability_of_transfer(probability_of_transfer);
            proportion_vaccinated = i / 100.0;    
            population.vaccinate(proportion_vaccinated);

            population.random_infection();
            int step = 0;
            bool nobody_infected = false;
            while (!(nobody_infected)) {
                step++;     
                if (population.count_infected() == 0) nobody_infected = true;
                population.update();
            }
            avg_steps += step;
        }
        avg_steps = avg_steps / 5;
        myFile1 << proportion_vaccinated << " " << avg_steps << '\n';
        // myFile1 << proportion_vaccinated << " " << step << '\n';
        cout << i << '\n';
    }

    probability_of_transfer = .4;
    ofstream myFile2 ("vac_vs_steps2.out");
    for (int i = 0; i < 100; i+=1) {
        avg_steps = 0;
        for (int j = 0; j < 5; j++) {
            Population population(pop_size);    
            population.set_probability_of_transfer(probability_of_transfer);
            proportion_vaccinated = i / 100.0;    
            population.vaccinate(proportion_vaccinated);

            population.random_infection();
            int step = 0;
            bool nobody_infected = false;
            while (!(nobody_infected)) {
                step++;     
                if (population.count_infected() == 0) nobody_infected = true;
                population.update();
            }
            avg_steps += step;
        }
        avg_steps = avg_steps / 5;
        myFile2 << proportion_vaccinated << " " << avg_steps << '\n';
        // myFile2 << proportion_vaccinated << " " << step << '\n';

        cout << i << '\n';

    }
    
    probability_of_transfer = .6;
    ofstream myFile3 ("vac_vs_steps3.out");
    for (int i = 0; i < 100; i+=1) {
        avg_steps = 0;
        for (int j = 0; j < 5; j++) {
            Population population(pop_size);    
            population.set_probability_of_transfer(probability_of_transfer);
            proportion_vaccinated = i / 100.0;    
            population.vaccinate(proportion_vaccinated);

            population.random_infection();
            int step = 0;
            bool nobody_infected = false;
            while (!(nobody_infected)) {
                step++;     
                if (population.count_infected() == 0) nobody_infected = true;
                population.update();
            }
            avg_steps += step;
        }
        avg_steps = avg_steps / 5;
        myFile3 << proportion_vaccinated << " " << avg_steps << '\n';
        // myFile3 << proportion_vaccinated << " " << step << '\n';

        cout << i << '\n';
    }

    probability_of_transfer = .8;
    ofstream myFile4 ("vac_vs_steps4.out");
    for (int i = 0; i < 100; i+=1) {
        avg_steps = 0;
        for (int j = 0; j < 5; j++) {
            Population population(pop_size);    
            population.set_probability_of_transfer(probability_of_transfer);
            proportion_vaccinated = i / 100.0;    
            population.vaccinate(proportion_vaccinated);

            population.random_infection();
            int step = 0;
            bool nobody_infected = false;
            while (!(nobody_infected)) {
                step++;     
                if (population.count_infected() == 0) nobody_infected = true;
                population.update();
            }
            avg_steps += step;
        }
        avg_steps = avg_steps / 5;
        myFile4 << proportion_vaccinated << " " << avg_steps << '\n';
        // myFile4 << proportion_vaccinated << " " << step << '\n';
        cout << i << '\n';
    }


    return 0;
}