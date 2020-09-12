#include<iostream>
#include"Header.Chess.h"
extern bool board[8][8];
King::King(const int& _x, const int& _y,const string &_name) {
	x = _x;
	y = _y-65;
	name = _name;
}
bool King::Step(const int& _x, const int& _y)
{
	if (!(((x == _x && y - _y == -1) || (x == _x && y - _y == 1)) || ((y == _y && x - _x == -1) || (y == _y && x - _x == 1)) || ((x - _x== -1 && y - _y == -1) || (x - _x == 1 && y - _y == 1))
		|| ((x - _x == 1 && y - _y == -1) || (x - _x == -1 && y - _y == 1))) || !(check_step(x, y, _x, _y)))
		return 0;
	x = _x;
	y = _y;
	return 1;
}
Queen::Queen(const int& _x, const int& _y, const string &_name) {
	x = _x;
	y = _y - 65;
	name = _name;
}
bool Queen::Step(const int& _x, const int& _y)
{
	if (!((_x == x || (int)_y == (int)y) || (_x - x == (int)_y - (int)y) || ((_x - x) + ((int)_y - (int)y) == 0))|| !(check_step(x, y, _x, _y)))
		return 0;
	x = _x;
	y = _y;
	return 1;
}
Bishop::Bishop(const int& _x, const int& _y, const string &_name) {
	x = _x;
	y = _y - 65;
	name = _name;
}
bool Bishop::Step(const int& _x, const int& _y)
{
	if(!((_x - x == (int)_y - (int)y) || ((_x - x) + ((int)_y - (int)y) == 0)) || !(check_step(x, y, _x, _y)))
		return 0;
	x = _x;
	y = _y;
	return 1;
}
Knight::Knight(const int& _x, const int& _y, const string &_name) {
	x = _x;
	y = _y - 65;
	name = _name;
}
bool Knight::Step(const int& _x, const int& _y)
{
	if (!(((x - _x == 2 || x - _x == -2) && (y - _y == 1 || y - _y == -1)) || ((x - _x == 1 || x - _x == -1) && (y - _y == 2 || y - _y == -2))))
		return 0;
	x = _x;
	y = _y;
	return 1;
}
Rook::Rook(const int& _x, const int& _y, const string &_name) {
	x = _x;
	y = _y - 65;
	name = _name;
}
bool Rook::Step(const int& _x, const int& _y)
{
	if(!(_x == x || _y == y) && !(check_step(x, y, _x, _y)))
		return 0;
	x = _x;
	y = _y;
	return 1;
}
Pawn::Pawn(const int& _x, const int& _y, const string &_name,const bool &_vect) {
	x = _x;
	y = _y - 65;
	name = _name;
	stan = true;
	vect = _vect;
}
bool Pawn::Step(const int& _x, const int& _y)
{
	if (stan)
	{
		stan = false;
		if (x < _x)
		{
			if (!((((x - _x == -1 || x - _x == -2) && y == _y) ||(x-_x==-1&&(y-_y==1||y-_y==-1)&& board[_x - 1][_y] == true))&&vect==false) || !(check_step(x, y, _x, _y)))
				return 0;
		}
		else
		{
			if (!((((x - _x == 1 || x - _x == 2) && y == _y) || (x - _x == 1 && (y - _y == 1 || y - _y == -1) && board[_x - 1][_y] == true))&&vect==true) || !(check_step(x, y, _x, _y)))
				return 0;
		}
	}
	else
	{
		if (x < _x)
		{
			if (!(((x - _x == -1 && y == _y)|| (x - _x == -1 && (y - _y == 1 || y - _y == -1) && board[_x - 1][_y] == true))&&vect==false) || !(check_step(x, y, _x, _y)))
				return 0;
		}
		else
		{
			if (!(((x - _x == 1 && y == _y)|| (x - _x == 1 && (y - _y == 1 || y - _y ==-1) && board[_x - 1][_y] == true))&&vect==true) || !(check_step(x, y, _x, _y)))
				return 0;
		}
	}
    x = _x;
	y = _y;
	return 1;
}
