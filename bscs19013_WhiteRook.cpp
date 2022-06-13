#include "bscs19005_WhiteRook.h"
#include "bscs19005_Board.h"
void WhiteRook::Move(Position EP)
{
	if (P.ri == 7 && P.ci == 0)
		fm1 = false;
	if (P.ri == 7 && P.ci == 7)
		fm2 = false;
	Position T = P;
	P = EP;
	B->Move(T, EP);

}
 void WhiteRook:: WriteOnFile()
{

	B->wtr << 'r';

	B->wtr << fm1;
}