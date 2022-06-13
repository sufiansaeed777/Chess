#pragma once
#include "bscs19005_Piece.h"
#include "bscs19005_Utility.h"
class Rook :
	public Piece
{private:
	bool FM1;
	bool FM2;
public:
	Rook(Position pos, Colour Color, Board* board) :Piece(pos, Color, board)
	{
		name = "rook";
		if (Color == Black)
			n = 'R';
		else if (Color == White)
			n = 'r';
		FM1 = true;
		FM2 = true;
	}
	
	
	bool IsLegal(Position E) override
	{
		return (IsVerticalMove(P,E) && IsVericlePathClear(B, P,E)) ||
			(IsHorizMove(P,E) && IsHorizPathClear(B, P,E));
	}
	virtual void Draw(Position p) override
	{
		int cr = p.ri, cc = p.ci;
		char s = '*';
	Utility::gotoRowCol(cr-3,cc-3 ); cout << s;
	Utility::gotoRowCol(cr - 3, cc); cout << s;
	Utility::gotoRowCol(cr - 3, cc +3); cout << s;
	for (int r = -2; r < 2; r++)
	{
		for (int c = -2; c <= 2; c++)
		{
			Utility::gotoRowCol(cr + r, cc + c);
			cout << s;
		}
	}
	for (int c = -2; c <= 4; c++)
		{
			Utility::gotoRowCol(cr + 2, cc + c - 1);
			cout << s;
		}
	}
	virtual bool AmIRook()override
	{
		return true;
	}
	
	
};

