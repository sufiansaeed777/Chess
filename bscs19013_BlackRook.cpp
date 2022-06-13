#include "bscs19005_BlackRook.h"
#include "bscs19005_Board.h"
class Board;
void BlackRook::Move(Position EP)
{
	if(P.ri==0 && P.ci==0)
		fm1 = false;
	if (P.ri == 0 && P.ci == 7)
		fm2 = false;
	Position T = P;
	P = EP;
	B->Move(T, EP);
	
}
 void BlackRook:: WriteOnFile() 
{


	B->wtr << 'R';
	B->wtr << fm1;
}