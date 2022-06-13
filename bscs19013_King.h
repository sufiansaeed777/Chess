#pragma once
#include "bscs19005_Piece.h"
class King :
	public Piece
{
private:
	bool FM;
public:
	
	King(Position pos, Colour Color, Board* board) :Piece(pos, Color, board)
	{
		name = "king";
		if (Color == Black)
			n = 'K';
		else if (Color == White)
			n = 'k';
		FM = true;
	}
	virtual bool IsLegal(Position E)override
	{
		bool r = (IsVerticalMove(P, E) && IsVericlePathClear(B, P, E)) ||
			(IsHorizMove(P, E) && IsHorizPathClear(B, P, E));
		bool b = (IsDiagMove(P, E) && IsDiagPathClear(B, P, E));
		bool q= (r || b);
		
		int dr = E.ri - P.ri;
		int dc = E.ci - P.ci;
		return (((abs(dr) == 1 && abs(dc) == 1) || (abs(dr) == 1 && abs(dc) == 0) || ((abs(dr) == 0 && abs(dc) == 1)) && q));
     }
	virtual void Draw(Position p) override
	{
		int cr = p.ri, cc = p.ci;
		char s = '*';
		for (int r = -2; r <= 2; r++)
			Utility::gotoRowCol(cr + r, cc), cout << s;
		for (int c = -2; c <= 2; c++)
			Utility::gotoRowCol(cr, cc+c), cout << s;
		for (int r = 3; r <= 3; r++)
		{
			for (int c = -1; c <= 1; c++)
			{
				Utility::gotoRowCol(cr + r, cc + c);
				cout << s;
			}
		}
	}
	void Move(Position EP)override;
	virtual string GetName()
	{
		return name;
	}
	bool IsFirstMove()
	{
		return FM;
	}
	
	
};

