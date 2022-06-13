#pragma once
#include "bscs19005_Rook.h"
#include "bscs19005_Piece.h"
class BlackRook :
	public Rook
{
public:
	//bool fm1, fm2;
	BlackRook(Position pos, Colour Color, Board* board) :Rook( pos,  Color,  board) 
	{
		fm1 = true;
		fm2 = true;
	}
	bool AmIBlackRook()override
	{
		return true;
	}
	void Move(Position EP)override;
	bool FM1()override
	{
		return fm1;
	}
	bool FM2()override
	{
		return fm2;
	}
	virtual void WriteOnFile() override;
};

