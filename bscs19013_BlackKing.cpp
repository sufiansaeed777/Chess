#include "bscs19005_BlackKing.h"
#include "bscs19005_Board.h"
void BlackKing::Move(Position EP)
{
	
	fm = false;
	Position T = P;
	P = EP;
	B->Move(T, EP);

}
void BlackKing::WriteOnFile()
{

	B->wtr << 'R';
	B->wtr << fm;
}