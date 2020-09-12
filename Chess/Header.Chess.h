#ifndef ChessData
#define ChessData
#include<vector>
#include<string>
using namespace std;
const int transfer_to_int = 65;
const size_t size_weight_squer = 3;
const size_t size_lenght_squer = 6;
const size_t size_board = 8;
const size_t cnt_figure = 16;
const char squer_white = '.';
const char squer_black = (char)' ';
class Figure abstract {
protected:
	int x;
	int y;
	string name;
public:
	virtual bool Step(const int&, const int&) = 0;
	const int get_x() { return x; }
	const int get_y() { return y; }
	const string get_name() { return name; }
};
class King : public Figure {
public:
	King(const int&, const int&, const string&);
	virtual bool Step(const int&, const int&)override;
};
class Queen : public Figure {
public:
	Queen(const int&, const int&, const string&);
	virtual bool Step(const int&, const int&)override;
};
class Bishop : public Figure {
public:
	Bishop(const int&, const int&, const string&);
	virtual bool Step(const int&, const int&)override;
};
class Knight : public Figure {
public:
	Knight(const int&, const int&, const string&);
	virtual bool Step(const int&, const int&)override;
};
class Rook : public Figure {
public:
	Rook(const int&, const int&, const string&);
	virtual bool Step(const int&, const int&)override;
};
class Pawn : public Figure {
	bool stan;
	bool vect;
public:
	Pawn(const int&, const int&, const string&,const bool &);
	virtual bool Step(const int&, const int&)override;
};
class Board {
	vector<Figure*>white;
	vector<Figure*>black;
	bool check_board(const size_t&,size_t&)const;
public:
	Board();
	Board(const Board&);
	~Board();
	void paint_board();
    bool menu_board(const bool&);
};
bool moving(const vector<Figure*>&,vector<Figure*>&);
const int check_moving(const vector<Figure*>&, const int&, const int&);
bool check_step(int, int, int, int);
#endif