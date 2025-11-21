#include <iostream>
#include "board.h"
#include "player.h"

int main() {
	Board myboard;
	//DEBUG - SET STARTING POSITION
	//myboard.set_position(1);
	
	std::string name_in;
	std::cout << "Enter Player 1's name: " << std::endl;
	getline(std::cin, name_in);
	
	Player player1(name_in, -1);
	
	std::cout << "Enter Player 2's name: " << std::endl;
	getline(std::cin, name_in);
	
	Player player2(name_in, 1);
	
	int turn = -1;
	
	myboard.print();
	
	std::string move;

	std::cout << player1.get_name() << ", enter move: " << std::endl;
	std::cin >> move;
	
	while (move != "end") {
		if(turn == 1) {
			myboard.make_move(move, player2);
			myboard.print();
			std::cout << player1.get_name();
		} else {
			myboard.make_move(move, player1);
			myboard.print();
			std::cout << player2.get_name();
		}
		std::cout << ", enter move: " << std::endl;
		std::cin >> move;
		turn = turn * -1;
	}
}