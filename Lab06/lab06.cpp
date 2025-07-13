#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int main(){

    ifstream inputFile("numbers.txt");

    if (!inputFile) {
        cout << "Error: Can't open the file" << std::endl;
        return 1;
    }

    unordered_set<int> us;
    
    int num;

    while (inputFile >> num) {
        us.insert(num);
    }

    inputFile.close();

    ofstream outputFile("new_numbers.txt");

    if (!outputFile) {
        cout << "Error: Can't open output file" << std::endl;
        return 1;
    }

   for(auto it = us.begin(); it != us.end(); it++){
        outputFile << *it << " ";       
    }

    outputFile.close();

    cout << "Removing Duplicates Completed." << endl;

    return 0;
}
