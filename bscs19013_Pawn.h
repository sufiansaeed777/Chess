#pragma once
#include "bscs19005_Piece.h"
#include "bscs19005_Position.h"
#include "bscs19005_Utility.h"
class Pawn :
	public Piece
{
private:
	bool FM;
public:
	//Pawn(){}
	Pawn(Position pos, Colour Color, Board* board) :Piece(pos,Color,board)
	{
		name = "pawn";
		if (Color == Black)
			n = 'P';
		else if (Color == White)
			n = 'p';
		FM = true;
	}
	void Move(Position EP)override;
	virtual void Draw(Position p) override
	{
		char s='*';
	for (int r = -2; r < 2; r++)
	{
		for (int c = -3; c <= 1; c++)
		{
			Utility::gotoRowCol(p.ri + r, p.ci + c);
			cout << s;
		}
	}
	Utility::gotoRowCol(p.ri + 1, p.ci-1); cout << s;
	Utility::gotoRowCol(p.ri + 2, p.ci-1); cout << s;
	for (int c = -1; c <= 1; c++)
	{
		Utility::gotoRowCol(p.ri + 3, p.ci + c-1);
		cout << s;
	
}
	}

	virtual void UnDraw()
	{
		cout << " ";
	}
	virtual bool IsLegal(Position E)override;
	virtual void WriteOnFile() override;
	bool IsFirstMove()
	{
		return FM;
	}
	virtual bool AmIPawn()override
	{
		return true;
	}
};

