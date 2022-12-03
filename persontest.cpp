#include "infect_lib.hpp"
#include <iostream>
using std::cout;

int main() {
    Person joe; 
    
    srand(time(0));
    int step = 1;
    for ( ; ; step++) {
        
        joe.update();
        float bad_luck = (float) rand()/(float)RAND_MAX; 
        if (bad_luck>.95) joe.infect(5);
        
        cout << "On day " << step << ", Joe is " << joe.status_string() << '\n';
        if (joe.is_stable()) break;
    }
}