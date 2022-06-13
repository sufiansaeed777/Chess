#include "bscs19005_WhiteKing.h"
#include "bscs19005_Board.h"
void WhiteKing::Move(Position EP)
{

	fm = false;
	Position T = P;
	P = EP;
	B->Move(T, EP);

}
 void WhiteKing::WriteOnFile() 
{
	B->wtr << 'r';

	B->wtr << fm;
}