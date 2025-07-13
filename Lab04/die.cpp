#include <iostream>
#include "die.hpp"

using namespace std;

Die::Die(){
    sides = 6;
}

Die::Die(int num_sides){
    sides = num_sides;
}

int Die::roll() {
    int result = rand() % sides + 1;
    return result;
}