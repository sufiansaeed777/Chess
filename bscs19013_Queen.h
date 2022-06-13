#pragma once
#include "bscs19005_Piece.h"
class Queen :
	public Piece
{
public:
	Queen(Position pos, Colour Color, Board* board) :Piece(pos, Color, board)
	{
		name = "queen";
		if (Color == Black)
			n = 'Q';
		else if (Color == White)
			n = 'q';
	}
	virtual bool IsLegal(Position E)override
	{		bool r= (IsVerticalMove(P, E) && IsVericlePathClear(B, P, E)) ||
			(IsHorizMove(P, E) && IsHorizPathClear(B, P, E));
		bool b= (IsDiagMove(P, E) && IsDiagPathClear(B, P, E));
		return (r || b);
	}
	virtual void Draw(Position p) override
	{
		int cr = p.ri, cc = p.ci;
		char s = '*';
		
				Utility::gotoRowCol(cr - 4, cc); cout << s;
				for (int c = -1; c <= 1; c++)
					Utility::gotoRowCol(cr - 3, cc + c), cout << s;
				for (int c = -2; c <= 2; c++)
				{
					if (c != 0)
					{
						Utility::gotoRowCol(cr - 2, cc + c), cout << s;
					}
				}
				for (int c = -1; c <= 1; c++)
					Utility::gotoRowCol(cr-1, cc + c), cout << s;
				Utility::gotoRowCol(cr, cc); cout << s;
				Utility::gotoRowCol(cr + 1, cc); cout << s;
				Utility::gotoRowCol(cr-2, cc); cout << " ";
				for (int c = -1; c <= 1; c++)
				{
					Utility::gotoRowCol(cr + 2, cc + c);
					cout << s;
				}
			
	}
	virtual void WriteOnFile() override;
	virtual bool AmIQueen()override
	{
		return true;
	}

};

