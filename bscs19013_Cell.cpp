#include "bscs19005_Cell.h"
#include "bscs19005_Board.h"
class Board;
Cell::Cell(int r, int c, int Rdim, int Cdim, Board* b) :row(r), col(c), rdim(Rdim), cdim(Cdim),board(b)
{
	SD.ri = row * rdim;
	SD.ci = col * cdim;
}
void Cell::PrintCell(char ch)
{
	if (ch == '-') ch = -37;
	for (int r = 0; r < rdim; r++)
	{

		for (int c = 0; c < cdim; c++)
		{
			Utility::gotoRowCol(board->S.ri + r, board->S.ci + c);
			cout << ch;
		}

	}
}
void Cell::PrintCell(Position S,char ch)
{
	if (ch == '-') ch = -37;
	for (int r = 0; r < rdim; r++)
	{

		for (int c = 0; c < cdim; c++)
		{
			Utility::gotoRowCol(S.ri + r, S.ci + c);
			cout << ch;
		}

	}
}
void Cell::Draw()
{
	if (board->B[row][col] == nullptr)
	{
		if ((row % 2 == 0 && col % 2 == 0) || (row % 2 == 1 && col % 2 == 1))
			Utility::SetClr(LBLUE, WHITE);
		else if ((row % 2 == 0 && col % 2 == 1) || (row % 2 == 1 && col % 2 == 0))
			Utility::SetClr(WHITE, LBLUE);
		char ch = -37;
		PrintCell(SD,ch);

	}
	else if(board->B[row][col]->GetColour()==White)
		Utility::SetClr(20, 20);
	else if (board->B[row][col]->GetColour() == Black)
		Utility::SetClr(23, 23);
		
	int cr = row * (rdim)+rdim / 2, cc = col * cdim + (cdim / 2);
	Position p(cr, cc);
	board->B[row][col]->Draw(p);
}
void Cell::HighlightValidCellsCastle(Position S)
{
	int sr = S.ri, sc = S.ci;
	if ((sr % 2 == 0 && sc % 2 == 0) || (sr % 2 == 1 && sc % 2 == 1))
		Utility::SetClr(BLACK, LBLUE);
	else if ((sr % 2 == 0 && sc % 2 == 1) || (sr % 2 == 1 && sc % 2 == 0))
		Utility::SetClr(BLACK, WHITE);
	Position p(sr * rdim, sc * cdim);
	PrintBoxHollow(p, '*');

	Position EP = board->E;
	for (int ri = 0; ri < max; ri++)
	{
		for (int ci = 0; ci < max; ci++)
		{
			if(ri==5 && ci==4 )
				cout << "";
			if(ri==5)
					cout << "";
			if(ri==6)
				cout << "";
			
			board->S = S;
			Position pos(ri, ci);
			board->E = pos;

			if ((ri % 2 == 0 && ci % 2 == 0) || (ri % 2 == 1 && ci % 2 == 1))
				Utility::SetClr(2, LBLUE);
			else if ((ri % 2 == 0 && ci % 2 == 1) || (ri % 2 == 1 && ci % 2 == 0))
				Utility::SetClr(2, WHITE);
			if (ri == 2 && ci==5)
				cout << "";
			if ((board->B[S.ri][S.ci]->IsLegal(board->E) && board->IsValidDestination()) && !(board->SelfCheck()))
			{
				Position p;
				p.ri = (ri * rdim);
				p.ci=( ci* cdim);
				PrintBoxHollow(p, '*');
				int bgclr;
				if ((ri % 2 == 0 && ci % 2 == 0) || (ri % 2 == 1 && ci % 2 == 1)) bgclr = LBLUE;
				else if ((ri % 2 == 0 && ci % 2 == 1) || (ri % 2 == 1 && ci % 2 == 0)) bgclr = WHITE;
				if (board->IsKill(board->E))
				{
				Utility:: SetClr(4, bgclr);
					PrintBoxHollow(p, '*');
				}

			}
		}
	}
	board->E = EP;

}
void Cell::HighlightValidCells(Position S)
{
	int sr = S.ri, sc = S.ci; bool IsKing=false,castle=false; int bgclr;
	if ((sr % 2 == 0 && sc % 2 == 0) || (sr % 2 == 1 && sc % 2 == 1))
		Utility::SetClr(BLACK, LBLUE);
	else if ((sr % 2 == 0 && sc % 2 == 1) || (sr % 2 == 1 && sc % 2 == 0))
		Utility::SetClr(BLACK, WHITE);
	Position p(sr * rdim, sc * cdim);
	PrintBoxHollow(p, '*');
	if (S == board->FindMyKing())
		IsKing = true;
	Position EP = board->E;
	for (int ri = 0; ri < max; ri++)
	{
		for (int ci = 0; ci < max; ci++)
		{
			board->S = S;
			Position pos(ri, ci);
			board->E.ri = pos.ri;
			board->E.ci = pos.ci;

			if (ri == 1)
				cout << "";
			if (ri == 2)
				cout << "";
			if (ri == 3)
				cout << "";
			if (ri == 4)
				cout << "";
			if (ri == 5)
				cout << "";
			if (ri == 6)
				cout << "";
			if (ri == 7)
				cout << "";
			if ((ri % 2 == 0 && ci % 2 == 0) || (ri % 2 == 1 && ci % 2 == 1))
				Utility::SetClr(2, LBLUE);
			else if ((ri % 2 == 0 && ci % 2 == 1) || (ri % 2 == 1 && ci % 2 == 0))
				Utility::SetClr(2, WHITE);
			if (ri == 2 && ci == 5)
				cout << "";
			
			if (((board->B[S.ri][S.ci]->IsLegal(board->E) && board->IsValidDestination()) && !(board->SelfCheck()))||(IsKing && (castle=board->IsCastling())))
		    {
				Position p;
				p.ri = (ri * rdim);
				p.ci = (ci * cdim);
				PrintBoxHollow(p, '*');
				
				if ((ri % 2 == 0 && ci % 2 == 0) || (ri % 2 == 1 && ci % 2 == 1)) bgclr = LBLUE;
				else if ((ri % 2 == 0 && ci % 2 == 1) || (ri % 2 == 1 && ci % 2 == 0)) bgclr = WHITE;
				if (board->IsKill(board->E))
				{
					Utility::SetClr(4, bgclr);
					PrintBoxHollow(p, '*');
				}
				if (castle)
				{
					Utility::SetClr(5, bgclr);
					Position p(ri * rdim, ci * cdim);
					PrintBoxHollow(p, '*');
				}
			}
			
		}
	}
	
	board->E = EP;

}
void Cell::UnHighlightValidCells(Position S)
{
	int ri, ci, color; bool IsKing=false;
	int sr = S.ri, sc = S.ci;
	if (S == board->FindMyKing())
		IsKing = true;
	if ((sr % 2 == 0 && sc % 2 == 0) || (sr % 2 == 1 && sc % 2 == 1))
		Utility::SetClr(LBLUE, WHITE);
	else if ((sr % 2 == 0 && sc % 2 == 1) || (sr % 2 == 1 && sc % 2 == 0))
		Utility::SetClr(WHITE, LBLUE);
	Position p(sr * rdim, sc * cdim);
	PrintBoxHollow(p, -37);
	
	Position EP = board->E;
	for (ri = 0; ri < max; ri++)
	{
		for (ci = 0; ci < max; ci++)
		{
			board->S = S;
			
			Position pos(ri, ci);
			board->E = pos;
			
			if ((ri % 2 == 0 && ci % 2 == 0) || (ri % 2 == 1 && ci % 2 == 1))
				Utility::SetClr(LBLUE, WHITE);
			else if ((ri % 2 == 0 && ci % 2 == 1) || (ri % 2 == 1 && ci % 2 == 0))
				Utility::SetClr(WHITE, LBLUE);
			
			if ((((board->B[sr][sc]->IsLegal(pos) && board->IsValidDestination() && !(board->SelfCheck())))) ||
							(IsKing && board->IsCastling()))
			{
				Position p(ri * rdim, ci * cdim);
				PrintCell(p, -37);
			}
		}
	}
	board->E = EP;
}

