#include "bscs19005_Bishop.h"
#include "bscs19005_Board.h"
class Board;
 void Bishop::WriteOnFile() 
{
	if (GetColour() == White)
		B->wtr << 'b';
	else if (GetColour() == Black)
		B->wtr << 'B';
}