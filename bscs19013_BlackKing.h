#pragma once
#include "bscs19005_King.h"
class BlackKing :
	public King
{
public:
	
	BlackKing(Position pos, Colour Color, Board* board) :King(pos, Color, board)
	{
		fm = true;
	}
	bool AmIBlackKing()override
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

