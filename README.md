# Infectious-Disease-Simulation
C++ simulation modeling the spread of infectious disease within a population.

## Compilation Instructions
This infectious disease simulation is composed of several main programs that run experiments to test and model different parameters. The compilation line for each test is fairly simple.

To run a simulation that only tracks the spread of the disease throughout the population:
```
icpc -o sim simulation.cpp infect_lib.cpp
./sim
```

To test the number of days the disease runs its course versus the proportion of the population that is vaccinated:
```
icpc -o epidemic_lifetime epidemic_lifetime.cpp infect_lib.cpp
./epidemic_lifetime
```

To test vaccination proportion required for herd immunity:
```
icpc -o herd herdimmunity.cpp infect_lib.cpp
./herd
```

To test vaccination proportion required to prevent mutation:
```
icpc -o mutations mutations.cpp infect_lib.cpp
./mutations
```