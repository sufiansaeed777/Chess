#pragma once
struct Position
{
	int ri, ci;
public:
	//Position(){}
	Position(int r=0, int c=0) :ri(r), ci(c)
	{

	}
	/*Position(const Position& P)
	{
		ri = P.ri;
		ci = P.ci;
	 }*/
	bool operator == (Position P)
	{
		return(P.ri == ri && P.ci == ci);
	}
	/*void operator =(const Position &P)
	{
		ri = P.ri;
		ci = P.ci;
	}*/
};

