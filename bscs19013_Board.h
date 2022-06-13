#pragma once
#include <iostream>
#include <fstream>
#include "bscs19005_Piece.h"
#include "bscs19005_Pawn.h"
#include "bscs19005_Queen.h"
#include "bscs19005_King.h"
#include "bscs19005_BlackKing.h"
#include "bscs19005_WhiteKing.h"
#include "bscs19005_Bishop.h"
#include "bscs19005_Knight.h"
#include "bscs19005_Rook.h"
#include "bscs19005_WhiteRook.h"
#include "bscs19005_BlackRook.h"
#include "bscs19005_Utility.h"
#include <string.h>
using namespace std;
#define MaxRows 80
#define MaxCol 100
#define max 8
#define BLACK 0
#define BROWN 6
#define WHITE 15
#define GREEN 2
#define RED 4
#define LBLUE 9
#include "bscs19005_Cell.h"
class Cell;
class Board
{

public:
	friend class Piece;
	Piece *B[max][max];
	Cell* C[max][max];
	int rows,dim;
	int cols;
	friend class Cell;
	friend class Piece;
	friend class King;
	friend class Pawn;
	 Colour turn;
	Position S, E;
	ofstream wtr;


public:
	Board()
	{
	}
	Board(string FN);
	void init(string FN);
	void initS(string FN);
	void Move(Position S, Position E);
	//void MoveSC(Position S, Position E);

	//void PrintBoard();
	bool IsValidSelection();
	bool IsValidDestination();
	bool InRange(Position P);
	void DisplayTurnMsg();
	void Play();
	void TurnChange();
	void SelectPiece();
	void SelectDestination();
	void PrintGrid(int dim);
	void PrintPieces();
	void Write()
	{
		wtr << turn; wtr << endl;
		for (int ri = 0; ri < max; ri++)
		{
			for (int ci = 0; ci < max; ci++)
			{
				if (B[ri][ci] == nullptr)
					wtr << '-';
				else
					B[ri][ci]->WriteOnFile();
				wtr << " ";
			}
			wtr << endl;
		}
		wtr.close();
	}
	void CopyBoard(Board &CB)
		{
		CB.rows = rows;
		CB.cols = cols;
		CB.S = S;
		CB.E = E;
		CB.turn = turn;
		Board* b=new Board;
		b = &CB;
			for (int ri = 0; ri < max; ri++)
			{
				for (int ci = 0; ci < max; ci++)
				{
					if (B[ri][ci] == nullptr)
					{
						CB.B[ri][ci] = nullptr;
						continue;
					}
							
					switch (B[ri][ci]->n)
					{
					case 'p':
						
						CB.B[ri][ci] = new Pawn(Position(ri, ci), White, b);

						break;
					case 'P':
						CB.B[ri][ci] = new Pawn(Position(ri, ci), Black, b);
						break;
					case 'q':
						CB.B[ri][ci] = new Queen(Position(ri, ci), White, b);
						break;
					case 'Q':
						CB.B[ri][ci] = new Queen(Position(ri, ci), Black, b);
						break;
					case 'k':
						CB.B[ri][ci] = new King(Position(ri, ci), White, b);
						break;
					case 'K':
						CB.B[ri][ci] = new King(Position(ri, ci), Black, b);
						break;
					case 'b':
						CB.B[ri][ci] = new Bishop(Position(ri, ci), White, b);
						break;
					case 'B':
						CB.B[ri][ci] = new Bishop(Position(ri, ci), Black, b);
						break;
					case 'r':
						CB.B[ri][ci] = new Rook(Position(ri, ci), White, b);
						break;
					case 'R':
						CB.B[ri][ci] = new Rook(Position(ri, ci), Black, b);
						break;
					case 'h':
						CB.B[ri][ci] = new Knight(Position(ri, ci), White, b);
						break;
					case 'H':
						CB.B[ri][ci] = new Knight(Position(ri, ci), Black, b);
						break;
					

					}
					CB.B[ri][ci]->P = B[ri][ci]->P;
					
				}
			}
		}
	bool IsKill(Position E)//Supposes that move is valid as it is called it main after valid move check
{
		if (B[E.ri][E.ci] == nullptr)
			return false;
	return (B[E.ri][E.ci]->IsOppPiece());
}
	Position FindMyKing()
{
		Position kp;
	for (int ri = 0; ri < max; ri++)
	{
		for (int ci = 0; ci < max; ci++)
		{
			if (B[ri][ci] == nullptr)
				continue;
		
			if ( (B[ri][ci]->IsMyPiece())&& ((B[ri][ci]->GetName()=="king")))
			{
				kp.ri = ri;
				kp.ci = ci;
				return kp;
			}
		}
	}
}
	Position FindOppKing()
	{
		Position kp;
		for (int ri = 0; ri < max; ri++)
		{
			for (int ci = 0; ci < max; ci++)
			{
				if (B[ri][ci] == nullptr)
					continue;

				if (!(B[ri][ci]->IsMyPiece()) && ((B[ri][ci]->GetName() == "king")))
				{
					kp.ri = ri;
					kp.ci = ci;
					return kp;
				}
			}
		}
	}
	bool SelfCheck2(Position s,Position e)
{
	
	 Board CB;
	Position kp;
	CopyBoard(CB);
	CB.Move(s,e);
	if (s == Position(1, 7) && e == Position(2, 6))
		cout << "";
	kp=CB.FindMyKing();
	CB.TurnChange();
	for (int ri = 0; ri < max; ri++)
	{
		for (int ci = 0; ci < max; ci++)
		{
			if (ri == 3 && ci == 7)
				cout << "";
			CB.S.ri = ri;
			CB.S.ci = ci;
			CB.E = kp;
			if (CB.B[ri][ci] == nullptr || CB.B[ri][ci]->GetColour()!=CB.turn)
				continue;
			if (CB.IsValidDestination())
			{
				if (CB.B[ri][ci]->IsLegal(kp) && CB.B[ri][ci]->IsMyPiece())
					return true;
			}
		}
	}
	return false;
}
	bool SelfCheck()
	{

		Board CB;
		Position kp;
		CopyBoard(CB);
		CB.Move(CB.S,CB.E);
		kp = CB.FindMyKing();
		CB.TurnChange();
		for (int ri = 0; ri < max; ri++)
		{
			for (int ci = 0; ci < max; ci++)
			{
				if (ri == 3 && ci == 7)
					cout << "";
				CB.S.ri = ri;
				CB.S.ci = ci;
				CB.E = kp;
				if (CB.B[ri][ci] == nullptr || CB.B[ri][ci]->GetColour() != CB.turn)
					continue;
				if (CB.IsValidDestination())
				{
					if (CB.B[ri][ci]->IsLegal(kp) && CB.B[ri][ci]->IsMyPiece())
						return true;
				}
			}
		}
		return false;
	}
	bool SelfCheck1(Colour T)
	{
		Colour temp = turn;
		turn = T;
		Board CB;
		Position kp;
		CopyBoard(CB);
		//CB.Move(CB.S, CB.E);
		kp = CB.FindOppKing();
		//CB.TurnChange();
		for (int ri = 0; ri < max; ri++)
		{
			for (int ci = 0; ci < max; ci++)
			{
				if (ri == 3 && ci == 7)
					cout << "";
				CB.S.ri = ri;
				CB.S.ci = ci;
				CB.E = kp;
				if (CB.B[ri][ci] == nullptr || CB.B[ri][ci]->GetColour() != CB.turn)
					continue;
				if (CB.IsValidDestination())
				{
					if (CB.B[ri][ci]->IsLegal(kp) && CB.B[ri][ci]->IsMyPiece())
					{
						turn = temp;
						return true;
					}
				}
			}
		}
		turn = temp;
		return false;
	}
	bool SelfCheckCastle( Position EP)
	{

		Board CB;
		Position kp;
		CopyBoard(CB);
		CB.Move(kp, EP);
		kp = CB.FindMyKing();
		CB.TurnChange();
		for (int ri = 0; ri < max; ri++)
		{
			for (int ci = 0; ci < max; ci++)
			{
				CB.S.ri = ri;
				CB.S.ci = ci;
				CB.E = kp;
				if (CB.B[ri][ci] == nullptr || CB.B[ri][ci]->GetColour() != CB.turn)
					continue;
				if (CB.IsValidDestination())
				{
					if (CB.B[ri][ci]->IsLegal(kp) && CB.B[ri][ci]->IsMyPiece())
						return true;
				}
			}
		}
		return false;
	}
	bool IsCastling()
{
		if (B[S.ri][S.ci]->AmIWhiteKing() == false && B[S.ri][S.ci]->AmIBlackKing() == false)
			return false;
int sr=S.ri,sc=S.ci,er=E.ri,ec=E.ci;
	if (B[er][ec] != nullptr)
		return false;
	if (turn == Black)
	{
	Position p1(0, 5);
	Position p2(0, 6),p3(0,2),p4(0,3);
		if ((er == 0 && ec == 6 && B[0][7] !=nullptr &&B[0][7]->AmIBlackRook() && B[0][7]->FM2() && B[0][5] == nullptr && !SelfCheckCastle(p1) && !SelfCheckCastle(p2))||
			(er == 0 && ec == 2 && B[0][0] != nullptr && B[0][0]->AmIBlackRook() && B[0][0]->FM1()   && B[0][3] == nullptr && !SelfCheckCastle(p3) && !SelfCheckCastle(p4)))
		{
			return true;
		}
	}
	else
	{Position p1(7, 5);
	Position p2(7, 6), p3(7, 2), p4(7, 3);
		if ((er == 7 &&  ec == 6 && B[7][7] != nullptr && B[7][7]->AmIWhiteRook() && B[7][7]->FM2() && B[7][5] == nullptr && !SelfCheckCastle(p1) && !SelfCheckCastle(p2))||
			(er == 7 &&   ec == 2 && B[7][0] != nullptr && B[7][0]->AmIWhiteRook() && B[7][0]->FM1() && B[7][3] == nullptr && !SelfCheckCastle(p3) && !SelfCheckCastle(p4)))
		{
			return true;
		}
	}
	return false;
}
bool Castling()
{
	if ((B[S.ri][S.ci]->AmIWhiteKing() == false && B[S.ri][S.ci]->AmIBlackKing() == false )|| (B[S.ri][S.ci]->FM()==false))
		return false;
	int sr=S.ri,sc=S.ci,er=E.ri,ec=E.ci;
	if (B[er][ec] != nullptr)
		return false;
	if (turn == Black)
	{
		Position p1(0, 5);
		Position kp = FindMyKing();
		Position p2(0, 6), p3(0, 2), p4(0, 3);
		if (er == 0 && ec == 6 && B[0][7] != nullptr && B[0][7]->AmIBlackRook() && B[0][7]->FM2() && B[0][5] == nullptr &&  !SelfCheckCastle(p1) && !SelfCheckCastle(p2))
		{
	
			B[kp.ri][kp.ci]->Move(E);
	            
			B[0][7]->Move(p1);
				
	        PrintPieces();
			return true;
		}
		if (er == 0 && ec == 2 && B[0][0] != nullptr && B[0][0]->AmIBlackRook() && B[0][0]->FM1()   && B[0][3] == nullptr && !SelfCheckCastle(p3) && !SelfCheckCastle(p4))
		{
			B[kp.ri][kp.ci]->Move(E);
			B[0][0]->Move(p4);
				PrintPieces();
			return true;
		}
	
	}
	else
	{
			Position kp = FindMyKing();
			Position p1(7, 5);
			Position p2(7, 6), p3(7, 2), p4(7, 3);
			if ((er == 7 && ec == 6 && B[7][7] != nullptr && B[7][7]->AmIWhiteRook() && B[7][7]->FM2() && B[7][5] == nullptr && !SelfCheckCastle(p1) && !SelfCheckCastle(p2)))
			
		{
			B[kp.ri][kp.ci]->Move(E);
			B[7][7]->Move(p1);
			PrintPieces();
			return true;
		}
		if (er == 7 &&   ec == 2 && B[7][0] != nullptr && B[7][0]->AmIWhiteRook() && B[7][0]->FM1() && B[7][3] == nullptr && !SelfCheckCastle(p3) && !SelfCheckCastle(p4))
				
		{
			B[kp.ri][kp.ci]->Move(E);
			B[7][0]->Move(p4);
				PrintPieces();
			return true;
		}
	}
	return false;
}	
bool DoIHaveMoveLeft()
{
	//Position s = S, e = E;
	for (int ri = 0; ri < max; ri++)
	{
		for (int ci = 0; ci < max; ci++)
		{
			for (int r = 0; r < max; r++)
			{
				for (int c = 0; c < max; c++)
				{
					if (turn == White)
						cout << "";
					if (ri == 0 && ci == 4 && r == 1 && c == 5)
						cout << "";
					if (ri == 7 && ci == 7 && r == 7 && c == 7)
						cout << "";
					Position p1(ri, ci);
					Position p(r, c);
					if (B[ri][ci] == nullptr || !B[ri][ci]->IsMyPiece() )
					{
						continue;
						
					}
					if (B[r][c] != nullptr && B[r][c]->IsMyPiece())
						continue;
					//S.ri = ri; S.ci = ci; E.ri = r; E.ci = c;
					Colour t;
					if (turn == Black)
						t = White;
					else
						t = Black;
					if (ri == 1 && ci == 4 && r == 2 && c == 4)
						cout << "";
					if (B[ri][ci]->IsLegal(p) &&  !SelfCheck2(p1,p))
					{
						if (B[r][c] == nullptr || !B[r][c]->IsMyPiece())
						{
							//S = s; E = e;
							return true;
						}
						
					}

				}

			}
		}
	}
	return false;
}
bool CheckMate()
{

	int t = turn;
	//TurnChange();
	
	bool r = (Check());
	TurnChange();
		bool m= !DoIHaveMoveLeft();

   TurnChange();
	return r && m;
}
void LoadSaved()
{
	initS("SavedGame.txt");
}
bool Check()
{
	
	Position kp=FindOppKing();
	for (int ri = 0; ri < max; ri++)
	{
		for (int ci = 0; ci < max; ci++)
		{
			if (B[ri][ci] == nullptr)
				continue;
			//Position temp = B[ri][ci]->P;
			//B[ri][ci]->P.ri = E.ri;
			//B[ri][ci]->P.ci = E.ci;
			if (ri == 3 && ci == 7)
				cout << "";
		if (B[ri][ci]->IsLegal(kp) && B[ri][ci]->IsMyPiece())
				return true;
		//B[ri][ci]->P = temp;
		}
	}
	return false;
}	
bool StaleMate()
{

	return (!Check() && !DoIHaveMoveLeft());
}
void PawnPromotion()
{
	if ((turn == Black && B[S.ri][S.ci]->AmIPawn() == false)  )
	{
		return;
	}
	if ((turn == White && B[S.ri][S.ci]->AmIPawn() == false)  )
	{
		
		return;
	}
	if (E.ri != 7 && E.ri != 0)
		return;
	char promote;
	Utility::gotoRowCol(46, 110);
	cout << "Promote pawn to: ";
	cin >> promote; 	Utility::gotoRowCol(46, 128); cout << promote;
	if (promote >= 'a' && promote <= 'z')
		promote -= 32;
	if ((turn == Black && E.ri == 7)|| (turn == White && E.ri == 0))
	{
		
		do
		{
			
			if (promote == 'Q')
				B[S.ri][S.ci] = new Queen(Position(S), turn, this);
			else if (promote == 'B')
				B[S.ri][S.ci] = new Bishop(Position(S), turn, this);
			else if (promote == 'R')
				B[S.ri][S.ci] = new Rook(Position(S), turn, this);
			else if (promote == 'H')
				B[S.ri][S.ci] = new Knight(Position(S), turn, this);

			
		} while (promote != 'Q' && promote != 'B' && promote != 'R' && promote != 'H');
		Utility::SetClr(0, 0);
		Utility::gotoRowCol(46, 110);
		cout << "                   ";
	}
	
	
}	
	
	
void Replay(Position source[],Position dest[],int count)
{
Board RB("ChessBoard.txt");

	RB.PrintGrid(dim); bool castle = false;
	RB.PrintPieces();
	Colour Turn = White; Position kp;

	for (int i = 0; i < count; i++)
	{
		RB.S = source[i];
		RB.E = dest[i];
		DisplayTurnMsg();
		RB.C[source[i].ri][source[i].ci]->HighlightValidCells(source[i]);
		kp=RB.FindMyKing();
		castle=RB.Castling();
		
		Sleep(1000);
		RB.C[source[i].ri][source[i].ci]->UnHighlightValidCells(source[i]);
		if (!castle)
		{
			RB.PawnPromotion();
			RB.B[source[i].ri][source[i].ci]->Move(dest[i]);
			//UpdatedDisplay(BC, S[i].s.r, S[i].s.c, D[i].d.r, D[i].d.c, rdim, cdim);
		}
		castle = false;
		RB.PrintPieces();
		Sleep(1000);
		TurnChange();
	}
}
	
	

	
	
	
	
	
	
	
	/*bool SelfCheck()
{
	
		Position kp; Board CB;
	
	CopyBoard( CB);
	
	CB.Move(S,E);
	kp=CB.FindMyKing();
	CB.TurnChange();
	for (int ri = 0; ri < max; ri++)
	{
		
		for (int ci = 0; ci < max; ci++)
		{
			
			if (CB.B[ri][ci] == nullptr)
				continue;
			if (CB.B[ri][ci]->IsLegal(kp)  && CB.B[ri][ci]-> IsMyPiece())
				return true;
		}
	}
	return false;
}*/
	/*Board( int r, int c, int Dim) :rows(r), cols(c),dim(Dim)
	{
		B = new char* [rows];
		for (int ri = 0; ri < rows; ri++)
		{
			B[ri] = new char[cols];
		}
		for (int ri = 0; ri < rows; ri++)
		{
			for (int ci = 0; ci < cols; ci++)
			{
				 B[ri][ci]='0';
			}
		}
		SetDimensions();
	}*/
	/*Board(ifstream Rdr, int r, int c, int Dim) :rows(r), cols(c),dim(Dim)
	{
		B = new char* [rows];
		for (int ri = 0; ri < rows; ri++)
		{
			B[ri] = new char[cols];
		}
		for (int ri = 0; ri < rows; ri++)
		{
			for (int ci = 0; ci < cols; ci++)
			{
				Rdr >> B[ri][ci];
			}
		}
		SetDimensions();

	}
	void PrintGrid()
	{
		int k = 15;
		char ch = -37;
		
		for (int ri = 0; ri < dim; ri++)
		{
			for (int ci = 0; ci < dim; ci++)
			{
				if ((ri % 2 == 0 && ci % 2 == 0) || (ri % 2 == 1 && ci % 2 == 1))
					SetClr(LBLUE, WHITE);
				else if ((ri % 2 == 0 && ci % 2 == 1) || (ri % 2 == 1 && ci % 2 == 0))
					SetClr(WHITE, LBLUE);
				PrintBox(ri * rdim, ci * cdim, rdim, cdim, ch);
			}
		}
	}*/

};

