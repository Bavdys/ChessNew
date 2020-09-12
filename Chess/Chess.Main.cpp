#include<iostream>
#include"Header.Chess.h"
using namespace std;
int main()
{
	Board game;
	bool case_player = true;
	while (game.menu_board(case_player))
		case_player = !case_player;
	if (case_player)
		cout << "\n\n\tWINNER WHITE!!!\n\n\n";
	cout << "\n\n\tWINNER BLACK!!!\n\n\n";
	system("PAUSE");
	return 0;
}