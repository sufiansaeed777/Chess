#include "bscs19005_Queen.h"
#include "bscs19005_Board.h"
class Board;
 void Queen::WriteOnFile() 
{
	if (GetColour() == White)
		B->wtr << 'q';
	else if (GetColour() == Black)
		B->wtr << 'Q';
}