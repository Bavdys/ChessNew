#include<iostream>
#include"Header.Chess.h"
using namespace std;
bool board[8][8];
Board::Board() {
	white.push_back(new King(8, 'E', "(Kg)"));
	white.push_back(new Queen(8, 'D', "(Qn)"));
	white.push_back(new Bishop(8, 'C', "(Bp)"));
	white.push_back(new Bishop(8, 'F', "(Bp)"));
	white.push_back(new Knight(8, 'B', "(Kt)"));
	white.push_back(new Knight(8, 'G', "(Kt)"));
	white.push_back(new Rook(8, 'A', "(Rk)"));
	white.push_back(new Rook(8, 'H', "(Rk)"));
	black.push_back(new King(1, 'E', "Kg"));
	black.push_back(new Queen(1, 'D', "Qn"));
	black.push_back(new Bishop(1, 'C', "Bp"));
	black.push_back(new Bishop(1, 'F', "Bp"));
	black.push_back(new Knight(1, 'B', "Kt"));
	black.push_back(new Knight(1, 'G', "Kt"));
	black.push_back(new Rook(1, 'A', "Rk"));
	black.push_back(new Rook(1, 'H', "Rk"));
	char symbol = 'A';
	for (int i = 0; i < 8; i++)
	{
		white.push_back(new Pawn(7, symbol, "(Pn)",true));
		black.push_back(new Pawn(2, symbol++, "Pn",false));
	}
}
Board::~Board() {
	size_t i = 0;
	while ((!white.empty()) || (!black.empty()))
	{
		if (!white.empty())
		{
			delete white[i];
			white.erase(white.begin());
		}
		if (!black.empty())
		{
			delete black[i];
			black.erase(black.begin());
		}
	}
}
Board::Board(const Board& obj)
{
	vector<Figure*>white_=obj.white;
	vector<Figure*>black_=obj.black;
}
void Board::paint_board()
{
	system("cls");
	cout << "\t\t\t\t\t\t\b\b\bCHESS\n\t\t\t";
	for (size_t i = 0; i < size_board * size_lenght_squer+1; i++) 
	{
		cout << "#";
	}
	cout << '\n';
	char symbol = '1';  
	size_t place_symbol = size_weight_squer / 2; 
	for (size_t i = 0; i < size_board; i++) 
	{
		for (size_t j = 0; j < size_weight_squer; j++) 
		{
			cout << "\t\t\t" << char('#');
			if (j == place_symbol)
				cout << "\b\b\b" << (char)symbol++ << " #";
			size_t cnt = 0;                                  
			while (++cnt < size_board * size_lenght_squer)
			{
				if (j == 1 && check_board(i, cnt))      
				{
					board[i][cnt / size_lenght_squer]=true;
					continue;
				}
				if (i % 2 == 0)                         
				{
					if ((cnt / size_lenght_squer) % 2 == 0)
						cout << (char)squer_black;
					else
						cout << (char)squer_white;
				}
				else                                    
				{
					if ((cnt / size_lenght_squer) % 2 == 0)
						cout << (char)squer_white;
					else
						cout << (char)squer_black;;
				}
			}
			cout << char('#') << '\n';
		}
	}
	cout << "\t\t\t\b ";
	for (int i = 0; i < size_board * size_lenght_squer+1; i++) 
	{
		cout << "#";
	}
	cout << "\n\t\t\t ";
	symbol = 'A';
	place_symbol = size_lenght_squer / 2;
	for (int i = 0; i < size_board * size_lenght_squer; i++) 
	{
		if (i == place_symbol - 1)
		{
			cout << (char)symbol++;
			place_symbol += size_lenght_squer;
		}
		else
			cout << " ";
	}
}
bool Board::check_board(const size_t& i, size_t& cnt)const
{
	for (int j = 0; j < white.size() || j < black.size(); j++)
	{
		if (j < white.size() && white[j]->get_x() - 1 == i && white[j]->get_y() * 6 + 1 == cnt)
		{
			cout << white[j]->get_name();
			cnt += 3;
			return 1;
		}
		if (j < black.size() && black[j]->get_x() - 1 == i && black[j]->get_y() * 6 + 2 == cnt)
		{
			cout << black[j]->get_name();
			cnt++;
			return 1;
		}
	}
	return 0;
}
bool moving(const vector<Figure*> &obj_1,vector<Figure*>& obj_2)
{
	int x1, x2, indx;
	char y1, y2;
	cout<< "\n\tHOD Z KLETKY (FOR EXAMPLE : 7A) : "; // ÄËß ÏÐÈÊËÀÄÓ 7A;
	cin >> x1;
	cin>> y1, cin.get();
	cout << "\tV KLETKU : ";
	cin >> x2;
	cin>> y2, cin.get();
	indx = check_moving(obj_1, x1, (int)y1 - transfer_to_int);
	if (indx < 0 || check_moving(obj_1, x2, (int)y2 - transfer_to_int) >= 0 || !(obj_1[indx]->Step(x2, (int)y2 - transfer_to_int)))
	{
		cout << "\tERORR!!!\n";
		return false;
	}
	board[x1 - 1][(int)y1 - transfer_to_int] = false;
	indx = check_moving(obj_2, x2,(int) y2- transfer_to_int);
	if (indx >= 0)
	{
		delete obj_2[indx];
		obj_2.erase(obj_2.begin() + indx);
	}
	return true;
}
const int check_moving(const vector<Figure*>& obj,const int &x,const int &y )
{
	for (int i = 0; i < obj.size(); i++)
		if (obj[i]->get_x() == x && obj[i]->get_y() == y)
			return i;
	return -1;

}
bool check_step(int x1_start, int y1_start, int x2_final, int y2_final)
{
	
	while (x1_start != x2_final || y1_start != y2_final)
	{
		if (y1_start<y2_final)
			y1_start++;
		if (y1_start > y2_final)
			y1_start--;
	    if (x1_start > x2_final)
			x1_start--;
	    if ( x1_start < x2_final)
			x1_start++;
		if (board[x1_start-1][y1_start] == true && (x1_start != x2_final || y1_start != y2_final))
			return 0;
	}
	return 1;
}
bool Board::menu_board(const bool& case_player)
{
    paint_board();
	if (white[0]->get_name() != "(Kg)" || black[0]->get_name() != "Kg")
		return false;
	if (case_player)
	{
		cout << "\n\n\tWHITE";
		while (!moving(white, black));
		return true;
	}
		cout << "\n\n\tBLACK";
		while (!moving(black, white));
		return true;
}