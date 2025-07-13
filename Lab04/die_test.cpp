#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "die.hpp"

using namespace std;

int main(){

    srand(time(0));

    Die d1(6);
    Die d2(6);

    cout << "Testing Die class" << endl;
    cout << "Dice 1: " << d1.roll() << endl;
    cout << "Dice 2: " << d1.roll() << endl;


    return 0;
}