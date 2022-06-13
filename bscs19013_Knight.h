#pragma once
#include "bscs19005_Piece.h"
class Knight :
	public Piece
{
public:
	virtual void WriteOnFile() override;
	Knight(Position pos, Colour Color, Board* board) :Piece(pos, Color, board)
	{
		name = "knight";
		if (Color == Black)
			n = 'H';
		else if (Color == White)
			n = 'h';
	}
	bool IsLegal(Position E) override
	{
	int dr = E.ri - P.ri; int dc = E.ci - P.ci;
	return (abs(dr) == 1 && abs(dc) == 2) || (abs(dr) == 2 && abs(dc) == 1);
    }
	virtual void Draw(Position p) override
	{
		int cr = p.ri, cc = p.ci;
		char s = '*';
		Utility::gotoRowCol(cr - 3, cc); cout << s;
		Utility::gotoRowCol(cr - 2, cc +2); cout << s;
			for (int c = 2; c <= 4; c++)
			{
				Utility::gotoRowCol(cr -1, cc + c - 1);
				cout << s;
				Utility::gotoRowCol(cr, cc + c - 1);
				cout << s;
			}
			for (int r = -2; r < 3; r++)
			{
				for (int c = -1; c <= 1; c++)
				{
					Utility::gotoRowCol(cr + r, cc + c);
					cout << s;
				}
			}
			for (int c = -1; c <= 3; c++)
			{
				Utility::gotoRowCol(cr + 3, cc + c - 1);
				cout << s;
			}
	}
	
};

