#pragma once
#include "bscs19005_King.h"
class WhiteKing :
	public King
{
public:
	bool fm;
	WhiteKing(Position pos, Colour Color, Board* board) :King(pos, Color, board)
	{
		fm = true;
	}
	bool AmIWhiteKing()override
	{
		return true;
	}
	void Move(Position EP)override;
	bool FM()override
	{
		return fm;
	}
	virtual void WriteOnFile() override;
};

