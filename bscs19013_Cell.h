#pragma once
#include "bscs19005_Position.h"
#include "bscs19005_Utility.h"
#include <iostream>
#include "bscs19005_Piece.h"
#define BLACK 0
#define BROWN 6
#define WHITE 15
#define GREEN 2
#define RED 4
#define LBLUE 9
class Board;
#define max 8
using namespace std;
class Cell
{
	private:
		friend class Board;
		int row, col, color, rdim, cdim;
		Board* board;
		Position SD;
		Utility U;
		
	public:
		Cell(int r, int c, int Rdim, int Cdim, Board* b);
		void PrintCell(char ch);
		void PrintCell(Position S, char ch);
		void PrintBoxHollow(Position S, char ch)
			{
				int sr=S.ri,sc=S.ci;
				for (int r = 0; r < rdim; r++)
				{
					for (int c = 0; c < cdim; c++)
					{
			
						if (c == 0 || c == cdim - 1)
						{
							Utility::gotoRowCol(sr + r, sc + c);
							cout << ch;
						}
						if (r == 0 || r == rdim - 1)
						{
							Utility::gotoRowCol(sr + r, sc + c);
							cout << ch;
						}
					}
				}
			}
		void Draw();
		void HighlightValidCells(Position S);
		void HighlightValidCellsCastle(Position S);
		void UnHighlightValidCells(Position S);
		/*static void PrintSpace(Position P)
{
			char sym = -37;
	if ((P.ri% 2 == 0 && P.ci % 2 == 0) || (P.ri % 2 == 1 && P.ci % 2 == 1))
		Utility::SetClr(LBLUE, WHITE);
	else if ((P.ri % 2 == 0 && P.ci % 2 == 1) || (P.ri % 2 == 1 && P.ci % 2 == 0))
		Utility::SetClr(WHITE, LBLUE);
	C->PrintCell(sym);
	
}*/

};

