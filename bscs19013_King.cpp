#include "bscs19005_King.h"
#include "bscs19005_Board.h"
class Board;
void King::Move(Position EP)
{
	Position T = P;
	P = EP;
	B->Move(T, EP);
	FM = false;
}
