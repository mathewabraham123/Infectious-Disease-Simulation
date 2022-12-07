# Infectious-Disease-Simulation
C++ simulation modeling the spread of infectious disease within a population.

## Compilation Instructions
This infectious disease simulation is composed of several main programs that run experiments to test and model different parameters. The compilation line for each test is fairly simple.

To test the number of days the disease runs its course versus the proportion of the population that is vaccinated:
```
icpc -o sims simulations.cpp infect_lib.cpp
./sims
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