#pragma once
#include <iostream>
using namespace std;
#include "bscs19005_Position.h"
#include "bscs19005_Cell.h"
#include<fstream>
using namespace std;
class Cell;
enum Colour {Black=0,White=1};
class Board;
class Piece
{
	friend class Board;
	
public:
	
	Colour C;
	Position P;
	Board* B;
	Cell* c;
	string name;
	char n;
	bool fm, fm1, fm2;
	static bool IsVericlePathClear(Board* B, Position S, Position E);
	static bool  IsHorizPathClear(Board* B, Position S, Position E);
	static bool  IsVerticalMove(Position S, Position E);
	static bool  IsHorizMove(Position S, Position E);
	static bool IsDiagMove(Position S, Position E);
	static bool IsDiagPathClear(Board* B, Position S, Position E);
	

public:
	
	Piece(Position pos, Colour Color, Board* board);
	virtual bool IsLegal( Position EP) = 0;
	virtual void Draw(Position p);
	virtual bool IsOppPiece();
	virtual bool IsMyPiece();
	virtual void UnDraw();
	virtual void Move(Position EP); 
	virtual Colour GetColour();
	virtual string GetName()
	{
		return name;
	}
	virtual bool FM1()
	{
		return false;
	}
	virtual bool FM()
	{
		return false;
	}
	virtual bool FM2()
	{
		return false;
	}
	virtual bool AmIBlackKing()
	{
		return false;
	}
	virtual bool AmIWhiteKing()
	{
		return false;
	}
	virtual bool AmIBlackRook()
	{
		return false;
	}
	virtual bool AmIWhiteRook()
	{
		return false;
	}

	virtual bool AmIPawn()
	{
		return false;
	}
	virtual void WriteOnFile()
	{

	}
	virtual bool AmIRook()
	{
		return false;
	}
	virtual bool AmIQueen()
	{
		return false;
	}
	virtual bool AmIPawnKnight()
	{
		return false;
	}
	virtual bool AmIBishop()
	{
		return false;
	}






};

