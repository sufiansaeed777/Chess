#include "bscs19005_Piece.h"
#include <iostream>
using namespace std;
#include "bscs19005_Position.h"
#include "bscs19005_Board.h"

class Board;

	Piece::Piece(Position pos, Colour Color, Board* board) :C(Color), P(pos), B(board)
	{
		
		name = "Piece";
		fm = fm1 = fm2 = true;
	}
	 bool Piece::IsLegal( Position EP) 
	 {
		 return true;

	}
	
 void Piece::Draw(Position p)
	{
	 B->C[P.ri][P.ci]->Draw();
	}

	 void Piece::UnDraw() 
	{
		 //c->PrintSpace(Pos P);
	}
	void Piece::Move(Position EP)
	{
		Position T = P;
		P.ri = EP.ri;
		P.ci = EP.ci;
		B->Move(T, EP);
	}
	Colour Piece::GetColour()
	{
		return  C;
	}
	bool Piece:: IsVericlePathClear(Board *B,Position S, Position E)
    {
	int sr=S.ri,sc=S.ci,er=E.ri,ec=E.ci;
	if (sr < er)
	{
		for (int r = sr + 1; r < er; r++)
		{
			if (B->B[r][sc] != nullptr)
				return false;
		}
		return true;
	}
	else
	{
		for (int r = sr - 1; r > er; r--)
		{
			if (B->B[r][sc] != nullptr)
				return false;
		}
		return true;
	}
}
bool  Piece::IsHorizPathClear(Board *B,Position S, Position E)
{
	int sr = S.ri, sc = S.ci, er = E.ri, ec = E.ci;
	if (sc < ec)
	{
		for (int c = sc + 1; c < ec; c++)
		{
			if (B->B[sr][c] != nullptr)
				return false;
		}
		return true;
	}
	else
	{

		for (int c = sc - 1; c > ec; c--)
		{
			if (B->B[sr][c] != nullptr)
				return false;
		}
		return true;
	}
}
bool  Piece::IsVerticalMove(Position S, Position E)
{
	return S.ci == E.ci;
}
bool  Piece::IsHorizMove(Position S, Position E)
{
	return S.ri == E.ri;
}
bool  Piece::IsDiagMove(Position S, Position E)
{
	int sr = S.ri, sc = S.ci, er = E.ri, ec = E.ci;
	int dr = er - sr;
	int dc = ec - sc;
	return (dr == dc) || (dr == -dc);
}
bool Piece::IsDiagPathClear(Board *B,Position S, Position E)
{
	int sr = S.ri, sc = S.ci, er = E.ri, ec = E.ci;
	int dr = er - sr;
	int dc = ec - sc;
	if (dr < 0 && dc>0)
	{
		for (int r = sr - 1, c = sc + 1; r != er && c != ec; r--, c++)
		{
			if (B->B[r][c] != nullptr)
				return false;
		}
	}
	if (dr > 0 && dc < 0)
	{
		for (int r = sr + 1, c = sc - 1; r != er && c != ec; r++, c--)
		{
			if (B->B[r][c] != nullptr)
				return false;
		}
	}
	if (dr < 0 && dc < 0)
	{
		for (int r = sr - 1, c = sc - 1; r != er && c != ec; r--, c--)
		{
			if (B->B[r][c] != nullptr)
				return false;
		}
	}
	if (dr > 0 && dc > 0)
	{
		for (int r = sr + 1, c = sc + 1; r != er && c != ec; r++, c++)
		{
			if (B->B[r][c] != nullptr)
				return false;
		}
		
	}
	return true;
}
bool Piece::IsOppPiece()
{
	if (this == nullptr)
		return false;
	
	if (B->turn == White)
		return (C== Black);
	else
		return (C == White);

}
bool Piece::IsMyPiece()
{
	if (this == nullptr)
		return false;
	
	if (B->turn == White)
		return (C == White);
	else
		return (C == Black);
}




