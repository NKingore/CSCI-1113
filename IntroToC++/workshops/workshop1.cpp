#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    
    char player1, player2;
    int i = 0;

    cout << "Player 1, enter R, P, or S(Rock, Paper, or Scissors): " << endl;
    cin >> player1;

    while ( i < 30){
        cout << "\n";
        i++;
    }

    cout << "Player 2, enter R, P, or S(Rock, Paper, or Scissors): " << endl;
    cin >> player2;

    if (!(player1 == 'R' || player1 == 'P' || player1 == 'S' || player1 == 'r' || player1 == 'p' || player1 == 's')){
        cout << "Invalid input from Player 1. Please enter R, P, or S." << endl;
        return 0;
    }

    if (!(player2 == 'R' || player2 == 'P' || player2 == 'S' || player2 == 'r' || player2 == 'p' || player2 == 's')){
        cout << "Invalid input from Player 2. Please enter R, P, or S." << endl;
        return 0;
    }

    while (player1 == player2){
        cout << "Tie game. Try again." << endl;
        cout << "Player 1, enter R, P, or S(Rock, Paper, Scissors): " << endl;
        cin >> player1;
        int i = 0;
        while (i < 30){
            cout << "\n";
            i++;
        }
        cout << "Player 2, enter R, P, or S(Rock, Paper, Scissors): " << endl;
        cin >> player2;
    }
    
    if ((player1 == ('R' || 'r') && player2 == ('S' || 's')) || (player1 == ('S' || 's') && player2 == ('P' || 'p')) || (player1 == ('P' || 'p') && player2 == ('R' || 'r'))){
        cout << "Player 1 wins!" << endl << endl;
        cout << "Do you want to play again? (Y/N)" << endl;
        char response;
        cin >> response;
        if (response == ('Y' || 'y')){
            main();
        } else if (response == ('N' || 'n')){
            cout << "Lame. Have some fun." << endl;
            return 0;
        }
    } else {
        cout << "Player 2 wins!" << endl << endl;
        cout << "Do you want to play again? (Y/N)" << endl;
        char response;
        cin >> response;
        if (response == 'Y'){
            main();
        } else if (response == 'N'){
            cout << "Lame. Have some fun." << endl;
            return 0;
        }
    }   

}