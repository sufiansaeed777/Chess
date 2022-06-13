#pragma once
#include "bscs19005_Board.h"
#include <conio.h>
using namespace std;

Board::Board(string FN)
{
	wtr.open("SavedGame.txt");
	init(FN);
	
}
void Board::initS(string FN)
{

	rows = max; cols = max; dim = max;
	//turn = White;
	ifstream Rdr;Rdr.open (FN); char p;
	for (int ri = 0; ri < rows; ri++)
	{
		for (int ci = 0; ci < cols; ci++)
		{
			int t;
			Rdr >> t;
			if (!Rdr)
				cout << "";
			if (t == 0)
				turn = Black;
			else
				turn = White;
			Rdr >> p;
			switch (p) 
			{
			case 'p':
					B[ri][ci] = new Pawn(Position(ri, ci), White, this);
					break;
			case 'P':
				B[ri][ci] = new Pawn(Position(ri, ci), Black, this);
				break;
			case 'q':
				B[ri][ci] = new Queen(Position(ri, ci), White, this);
				break;
			case 'Q':
				B[ri][ci] = new Queen(Position(ri, ci), Black, this);
				break;
			case 'k':
				B[ri][ci] = new WhiteKing(Position(ri, ci), White, this);
				Rdr >> B[ri][ci]->fm;
				break;
			case 'K':
				B[ri][ci] = new BlackKing(Position(ri, ci), Black, this);
				Rdr >> B[ri][ci]->fm;
				break;
			case 'b':
				B[ri][ci] = new Bishop(Position(ri, ci), White, this);
				
			case 'B':
				B[ri][ci] = new Bishop(Position(ri, ci), Black, this);
				break;
			case 'r':
				B[ri][ci] = new WhiteRook(Position(ri, ci), White, this);
				Rdr >> B[ri][ci]->fm1;
				break;
			case 'R':
				B[ri][ci] = new BlackRook(Position(ri, ci), Black, this);
				Rdr >> B[ri][ci]->fm2;
				break;
			case 'h':
				B[ri][ci] = new Knight(Position(ri, ci), White, this);
				break;
			case 'H':
				B[ri][ci] = new Knight(Position(ri, ci), Black, this);
				break;
			default:
				B[ri][ci]=nullptr;

			}
			
				
		}
	}
}
void Board::init(string FN)
{

	rows = max; cols = max; dim = max;
	turn = White;
	ifstream Rdr(FN); char p;
	for (int ri = 0; ri < rows; ri++)
	{
		for (int ci = 0; ci < cols; ci++)
		{
			
			Rdr >> p;
			switch (p)
			{
			case 'p':
				B[ri][ci] = new Pawn(Position(ri, ci), White, this);
				break;
			case 'P':
				B[ri][ci] = new Pawn(Position(ri, ci), Black, this);
				break;
			case 'q':
				B[ri][ci] = new Queen(Position(ri, ci), White, this);
				break;
			case 'Q':
				B[ri][ci] = new Queen(Position(ri, ci), Black, this);
				break;
			case 'k':
				B[ri][ci] = new WhiteKing(Position(ri, ci), White, this);
			
				break;
			case 'K':
				B[ri][ci] = new BlackKing(Position(ri, ci), Black, this);
				break;
			case 'b':
				B[ri][ci] = new Bishop(Position(ri, ci), White, this);
				break;
			case 'B':
				B[ri][ci] = new Bishop(Position(ri, ci), Black, this);
				break;
			case 'r':
				B[ri][ci] = new WhiteRook(Position(ri, ci), White, this);
				break;
			case 'R':
				B[ri][ci] = new BlackRook(Position(ri, ci), Black, this);
				break;
			case 'h':
				B[ri][ci] = new Knight(Position(ri, ci), White, this);
				break;
			case 'H':
				B[ri][ci] = new Knight(Position(ri, ci), Black, this);
				break;
			default:
				B[ri][ci] = nullptr;

			}


		}
	}
}

void Board::Move(Position S, Position E)
{
	/*B[E.ri][E.ci]->UnDraw();*/
	//B[S.ri][S.ci]->UnDraw();
	char sym = -37;
	


	B[E.ri][E.ci] = B[S.ri][S.ci];
	B[S.ri][S.ci] = nullptr;
	
}

bool Board::InRange(Position P)
{
	if (P.ri < 0 || P.ri >= max || P.ci< 0 || P.ci >= max)
			return false;
}
bool Board::IsValidSelection()
{
	return (B[S.ri][S.ci] != nullptr && B[S.ri][S.ci]->GetColour() == turn && InRange(S));

}
bool Board::IsValidDestination()
{
	return ((B[E.ri][E.ci] == nullptr || B[E.ri][E.ci]->GetColour() != turn) && InRange(S));

}
void Board::DisplayTurnMsg()
{
	

	Utility::SetClr(WHITE, BLACK);
	Utility::gotoRowCol(40,110);
	if (turn == White)
		cout << "Red's ";
	else
		cout << "Grey's";
		cout<< " turn";

	/*if (turn == White)
		cout << "White's turn";
	else
		cout << "Black's turn";*/
}
void Board::Play()
{
	cout << "New game(n) or saved game(s): ";
	char o; cin >> o;
	if (o == 'n')
		init("ChessBoard.txt");
	else
		initS("SavedGame.txt");
	Position source[500];
	Position dest[500];
	int count = 0;
	
	PrintGrid(max);
	int sr = 10, sc = 110;
	bool castle;
Utility::	SetClr(0, 4);
	Utility::gotoRowCol(sr + (5 * 3) + 2, sc + 3); cout << "Replay";
	Utility::gotoRowCol(sr + (5 * 2) + 2, sc + 3); cout << "Undo";
	Utility::gotoRowCol(sr + 2, sc + 3); cout << "Save and exit";

	while (1)
	{
		PrintPieces();
		
		do
		{
			DisplayTurnMsg();
			do
			{
				//cout << "\nSelect Piece";
				Position US = S;
				Position UE = E;
				SelectPiece();
				int rdim = MaxRows / dim;
				int cdim = MaxCol / dim;
				if (S.ri < 15 && S.ri>10 && S.ci > 105 && S.ci < 125)
				{
					Write();
					return;
				}
				if (S.ri < 25 && S.ri>20 && S.ci > 105 && S.ci < 125)
				{
					S.ri = S.ri / C[0][0]->rdim; S.ci = S.ci / C[0][0]->cdim;
					B[UE.ri][UE.ci]->Move(US);

					TurnChange();
					DisplayTurnMsg();
					PrintPieces();
					SelectPiece();
				}
				if (S.ri < 35 && S.ri>25 && S.ci > 105 && S.ci < 125)
				{
					Replay(source, dest, count);
					DisplayTurnMsg();
					SelectPiece();
				}
				S.ri = S.ri / C[0][0]->rdim; S.ci = S.ci / C[0][0]->cdim;
				if (IsValidSelection() == false)
				{
					Utility::gotoRowCol(42, 110);
					Utility::	SetClr(4, BLACK);
					cout << "Invalid selection ";
				}
			} while (IsValidSelection() == false);
			C[S.ri][S.ci]->HighlightValidCells(S);
			{Utility::gotoRowCol(42, 110);
			Utility::SetClr(2, BLACK);
			cout << "Select destination      "; }
			SelectDestination();
			C[S.ri][S.ci]->UnHighlightValidCells(S);
			 castle = Castling();
			if (castle)
				break;
			if (IsValidDestination()==false || SelfCheck())
			{
				Utility::gotoRowCol(42, 110);
				Utility::				SetClr(2, BLACK);
				cout << "Select destination      ";
			}

		} while (IsValidDestination() == false || SelfCheck() );
		if ((!castle && B[S.ri][S.ci]->IsLegal(E)))
		{

			if ((S.ri % 2 == 0 && S.ci % 2 == 0) || (S.ri % 2 == 1 && S.ci % 2 == 1))
				Utility::SetClr(LBLUE, WHITE);
			else if ((S.ri % 2 == 0 && S.ci % 2 == 1) || (S.ri % 2 == 1 && S.ci % 2 == 0))
				Utility::SetClr(WHITE, LBLUE);
			PawnPromotion();
			B[S.ri][S.ci]->Move(E);
			{
				Utility::gotoRowCol(42, 110);
				Utility::SetClr(2, BLACK);
				//cout << "                        ";
			}
			if (CheckMate())
			{
				Utility::SetClr(0, 0);
				
				TurnChange();
				PrintPieces();
				Utility::SetClr(2, BLACK);
				Utility::gotoRowCol(46, 110);
				string n;
				if (turn == Black)
					n = "Grey";
				else
					n = "Red";
				cout << "Check Mate to player " << n << "!!!";
				return;
		    }
			if (Check())
			{
				int ri, ci, rp, cp;
				DoIHaveMoveLeft();
				Utility::gotoRowCol(46, 110);
				TurnChange();
				string n;
				if (turn == Black)
					n = "Grey";
				else
					n = "Red";
				cout << "Check to player " << n << "!!!";
				TurnChange();
			}
			if (_kbhit())
			{
				char ch = _getch();
				if (ch == 'r' || ch == 'R')
					Replay(source, dest, count);
			}
			TurnChange();
			if (StaleMate())
			{
				int ri, ci, rp, cp;
				//DoIHaveMoveLeft();
				Utility::gotoRowCol(46, 110);
				//TurnChange(turn);
				PrintPieces();
				cout << "Stale mate!!!";
				return;
			}
		}
		
		else
		{
			Utility::gotoRowCol(42, 110);
			Utility::SetClr(2, BLACK);
			cout << "Invalid Move";
		}
		if (castle)
			TurnChange();
		//for (int r = 30; r <= 80; r++)
		{
			for (int c = 110; c < 130; c++)
			{
				Utility::gotoRowCol(42, c);
				cout << " ";
			}
		}
		source[count] = S;
		dest[count] = E;
		count++;
	}
}
void Board::TurnChange()
{
	if (turn == White)
		turn = Black;
	else
		turn = White;

}
void Board::SelectPiece()
{
	Utility::getRowColbyLeftClick(S.ri, S.ci);
	
	
}
void Board::SelectDestination()
{
	Utility::getRowColbyLeftClick(E.ri, E.ci);
	E.ri = E.ri / C[0][0]->rdim; E.ci = E.ci / C[0][0]->cdim;
}
void Board::PrintGrid(int dim)
{
	int k = 15;
	char ch = -37;
	int rdim = MaxRows / dim;
	int cdim = MaxCol / dim;
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			if ((ri % 2 == 0 && ci % 2 == 0) || (ri % 2 == 1 && ci % 2 == 1))
				Utility::SetClr(LBLUE, WHITE);
			else if ((ri % 2 == 0 && ci % 2 == 1) || (ri % 2 == 1 && ci % 2 == 0))
				Utility::SetClr(WHITE, LBLUE);
			C[ri][ci] = new Cell(ri, ci, rdim, cdim, this);
			Position pos(ri*rdim, ci*cdim);
			C[ri][ci]->PrintCell(pos,ch);
		}
	}
}
void Board::PrintPieces()
{
	int k; char ch = -37;
	for (int ri = 0; ri < max; ri++)
	{
		for (int ci = 0; ci < max; ci++)
		{
			if ((ri % 2 == 0 && ci % 2 == 0) || (ri % 2 == 1 && ci % 2 == 1))
				Utility::SetClr(WHITE, LBLUE);
			else if ((ri % 2 == 0 && ci % 2 == 1) || (ri % 2 == 1 && ci % 2 == 0))
				Utility::SetClr(LBLUE, WHITE);
			if(B[ri][ci]!=nullptr)
			   C[ri][ci]->Draw();
			else
			{
				if ((ri % 2 == 0 && ci % 2 == 0) || (ri % 2 == 1 && ci % 2 == 1))
					Utility::SetClr(LBLUE, WHITE);
				else if ((ri % 2 == 0 && ci % 2 == 1) || (ri % 2 == 1 && ci % 2 == 0))
					Utility::SetClr(WHITE, LBLUE);
				int rdim = MaxRows / 8;
				int cdim = MaxCol / 8;
				Cell C(ri, ci, rdim, cdim, this);
				Position p(ri * rdim, ci * cdim);
				C.PrintCell(p, -37);
			}
		}
		cout << endl;
	}
}
