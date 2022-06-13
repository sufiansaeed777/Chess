//keep console width to 150 and height to 150
//use raster font 8x8
//set console background to black
#include<conio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<time.h>
#include<iomanip>
#include<math.h>
#include<mmsystem.h>
#include<MMSystem.h>
#include "bscs19005_Board.h"

#include <stdlib.h>                     // Provides exit
#include <ctype.h>                      // Provides toupper
using namespace std;
#define BLACK 0
#define BROWN 6
#define WHITE 15
#define GREEN 2
#define RED 4
#define LBLUE 9
using namespace std;
#define max 8
#define WHITEP 0
#define BLACKP 1
#define MaxRows 80
#define MaxCol 100
enum option {SaveGame, undo, replay, NewGame, LoadSavedGame,NoOpt};
struct Pos
{
	int r, c;
};
struct source
{
	Pos s;
};
struct dest
{
	Pos d;
};
void SetClr(int tcl, int bcl)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (tcl + (bcl * 16)));
}
int main()
{
	Board B("ChessBoard.txt");
	B.Play();
	return _getch();

}










