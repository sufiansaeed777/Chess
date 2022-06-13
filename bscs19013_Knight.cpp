#include "bscs19005_Knight.h"
#include "bscs19005_Board.h"
class Board;
 void Knight:: WriteOnFile()
{
	if (GetColour() == White)
		B->wtr << 'h';
	else if (GetColour() == Black)
		B->wtr << 'H';
}