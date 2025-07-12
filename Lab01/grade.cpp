#include <iostream>

using namespace std;

int main(){

    int percentage;
    cout << "Enter the percentage of your grade: ";
    cin >> percentage;


    if (percentage < 0 || percentage > 100){

        cout << "Invalid Value" << endl;

        return 0;
    }
    

    
    char grade;

    int firstNumber = percentage/10;
    int secondNumber = percentage % 10;
    

    switch(firstNumber){

        case 10: 
            grade = 'A';
            cout << "You grade is:" << grade << "+" << endl;
            return 0;

        case 9: 
            grade = 'A';
            break;

        case 8: 
            grade = 'B';
            break;

        case 7: 
            grade = 'C';
            break;

        case 6: 
            grade = 'D';
            break;

        default:
            grade = 'F';
            cout << "Your grade is: " << grade << endl;
            return 0;
    }

    switch(secondNumber) {      
        case 8:
        
        case 9:
            if (firstNumber != 'F') {
                cout << "You grade is:" << grade << "+" << endl;
            }
            break;

        case 0:

        case 1:

        case 2:
            if (firstNumber != 'F') {
                cout << "Your grade is: " << grade << "-" << endl;
               
        default:
            cout << "Your grade is: " << grade << endl;
            break;     
    }

}
return 0;
}
