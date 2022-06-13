#include "bscs19005_Pawn.h"
#include "bscs19005_Board.h"
class Board;
void Pawn::Move(Position EP)
{
	Position T = P;
	P = EP;
	B->Move(T, EP);
	FM = false;
}
void Print(Piece* p)
{
	for (int r = 0; r < max; r++)
	{
		for (int c = 0; c < max; c++)
		{
			if (p->B->B[r][c] == nullptr)
			{
				cout << "- ";
				continue;
			}
			cout << p->B->B[r][c]->n << " ";
		}
		cout << endl;
	}

}
void Print(Board* b)
{
	for (int r = 0; r < max; r++)
	{
		for (int c = 0; c < max; c++)
		{
			if (b->B[r][c] == nullptr)
			{
				cout << "- ";
				continue;
			}
			cout << b->B[r][c]->n << " ";
		}
		cout << endl;
	}

}
bool Pawn::IsLegal(Position E)
{
	//Print(this);
	int sr = P.ri, sc = P.ci, er = E.ri, ec = E.ci;

	int dr = er - sr, dc = ec - sc;
	bool forward;
	if (GetColour() == Black && sr == 1)
		forward = dr == 1 || dr == 2;
	else if (GetColour() == Black && sr != 1)
		forward = dr == 1;
	else if (GetColour() == White && sr == 6)
		forward = dr == -1 || dr == -2;
	else if (GetColour() == White && sr != 6)
		forward = dr == -1;
	
	if (IsVerticalMove(P, E) && IsVericlePathClear(B, P, E) && forward &&(B->B[E.ri][E.ci]==nullptr) )
	{
		return true;
	}
	if (GetColour() == White)
	{
		if ((((dr == -1 && dc == 1) || (dr == -1 && dc == -1)) && B->B[E.ri][E.ci]!=nullptr))
		{
		B->B[E.ri][E.ci]->IsOppPiece();
		return true;
        }
	}
	else
	{
		if (((((dr == 1 && dc == 1) || (dr == 1 && dc == -1)) && B->B[E.ri][E.ci] != nullptr)))
		{
		B->B[E.ri][E.ci]->IsOppPiece();
		return true;
		}
	}
	return false;
	

}
 void Pawn::WriteOnFile() 
{
	if (GetColour() == White)
		B->wtr << 'p';
	else if (GetColour() == Black)
		B->wtr << 'P';

}