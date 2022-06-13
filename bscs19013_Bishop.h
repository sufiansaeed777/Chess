#pragma once
#include "bscs19005_Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop(Position pos, Colour Color, Board* board) :Piece(pos, Color, board)
	{
		if (Color == Black)
			n = 'B';
		else if (Color == White)
			n = 'b';
	}
	virtual void WriteOnFile() override;
	virtual bool AmIBishop()override
	{
		return true;
	}
	bool IsLegal(Position E) override
	{
		return (IsDiagMove(P, E) && IsDiagPathClear(B, P, E));
	}
	virtual void Draw(Position p) override
	{
		int cr = p.ri, cc = p.ci;
		char s = '*';
		Utility::gotoRowCol(cr - 4, cc); cout << s;
			for (int c = -1; c <= 1; c++)
				Utility::gotoRowCol(cr - 3, cc + c), cout << s;
			for (int c = -2; c <= 2; c++)
				Utility::gotoRowCol(cr-2, cc + c), cout << s;
			for (int c = -2; c <= 2; c++)
				Utility::gotoRowCol(cr-1, cc + c), cout << s;
			for (int c = -1; c <= 1; c++)
				Utility::gotoRowCol(cr, cc + c), cout << s;
			Utility::gotoRowCol(cr + 1, cc); cout << s;
			Utility::gotoRowCol(cr + 2, cc); cout << s;
				for (int c = -1; c <= 1; c++)
				{
					Utility::gotoRowCol(cr + 3, cc + c);
					cout << s;
				}
	}
	
};

