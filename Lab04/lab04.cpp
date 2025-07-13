#include <iostream>
#include <cstdlib>
#include <ctime>
#include "die.hpp"

using namespace std;

int gameMenu(){

    int playerChoice;
    cout << "What do you want to do?" << endl;
    cout << "1: roll" << endl;
    cout << "2: hold (end turn)" << endl;
    cout << "0: quit game" << endl;

    cin >> playerChoice;

    return playerChoice;
}

int playerTurn(Die &d1, Die &d2) {
    int playerPoints = 0;

    int dice1 = d1.roll();
    int dice2 = d2.roll();

    cout << "Player Rolling: " << endl;
    cout << "D1: " << dice1 << " D2: " << dice2 << endl;

    if(dice1 == 1 && dice2 == 1){
        cout << "Congrats you rolled two ones! +25 points!" << endl;
        playerPoints = playerPoints + 25;
    } else if ((dice1 == 1 && dice2 != 1) || (dice1 != 1 && dice2 == 1)){
        cout << "Busted. Turn Over! :(" << endl;
        cout << "Roll Result: " << playerPoints << endl;
        cout << "Player's Turn Over" << endl;
    } else if (dice1 == dice2) {
        cout << "Congrats! Double points!" << endl;
        int doublePoints = (dice1 + dice2) * 2;
        playerPoints = playerPoints + doublePoints;
    } else {
        int total = dice1 + dice2;
        playerPoints = playerPoints + total;
    }

    cout << "Current Turn Score for Player: " << playerPoints << endl;

    return playerPoints;
    
    }

int computerTurn(Die &d1, Die &d2){
    int computerPoints = 0;
    int rollCount = 0;

    while(rollCount < 4){
        int dice1 = d1.roll();
        int dice2 = d2.roll();
        rollCount = rollCount + 1;

        cout << "Computer Rolling: " << endl;
        cout << "D1: " << dice1 << " D2: " << dice2 << endl;

        if(dice1 == 1 && dice2 == 1){
            cout << "The computer rolled two ones." << endl;
            computerPoints = computerPoints + 25;
        } else if((dice1 == 1 && dice2 != 1) || (dice1 != 1 && dice2 == 1)){
            cout <<  "The computer rolled a one. Turn Over." << endl;
            cout << "Current Turn Score for Computer: " << computerPoints << endl;
            cout << "Computer's Turn Over" << endl;
            return computerPoints;
        } else if (dice1 == dice2){
            int doublePoints = (dice1 + dice2) * 2;
            computerPoints = computerPoints + doublePoints;
            cout << "The computer rolled doubles. 25+ Points." << endl;
        } else {
            int normalTurn = dice1 + dice2;
            computerPoints = computerPoints + normalTurn; 
        }

        cout << "Current Turn Score for Computer: " << computerPoints << endl;

        if(rollCount >= 4){
            cout << "Computer's Turn Over." << endl;
            cout << rollCount << endl;
        }
    }
     
    return computerPoints;
}

void displayScores(int playerScore, int computerScore){
    cout << "Total Score for Player: " << playerScore << endl;
    cout << "Total Score for Computer: " << computerScore << endl;
}

int main(){

    srand(time(0));

    Die d1(6);
    Die d2(6);

    int playerScore = 0;
    int computerScore = 0; 
    bool playerRound = true;
    bool computerRound = true;
    bool gameDone = false; 


    cout << "Welcome to Two-Dice Pig!" << endl;
    cout << "First player to reach 100 points wins." << endl;

    while (!gameDone && (playerScore < 100) && (computerScore < 100)){
        while(playerRound){
            
            int choice = gameMenu();

            if(choice == 0){
                playerRound = false;
                computerRound = false;
                gameDone = true;
            } else if (choice == 1){
                int playerRoll = playerTurn(d1,d2);
                playerScore = playerScore + playerRoll; 
                displayScores(playerScore,computerScore);

                if(playerRoll == 0){
                    playerRound = false;
                    computerRound = true;
                }
            } else if (choice == 2){
                playerRound = false; 
                computerRound = true;
            } else {
                cout << "Invaild Value. Try again." << endl;
            }

            if (playerScore >= 100) {
                cout << "Congratulations! You won! " << playerScore << " points! " << endl;
                playerRound = false;
                gameDone = true;
                
            }
        }

        while(computerRound){
            int computerRoll = computerTurn(d1,d2);
            computerScore = computerScore + computerRoll;
            displayScores(playerScore,computerScore);

            if(computerRoll == 0){
                playerRound = true;
                computerRound = false;
            }
            computerRound = false;
            playerRound = true; 

            if(computerScore >= 100) {
                cout << "Computer Wins!" << endl;
                computerRound = false;
                gameDone = true;
            }

        } 

    }

    return 0;
}
