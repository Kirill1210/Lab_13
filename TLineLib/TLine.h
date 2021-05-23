#pragma once
#include "TBase.h"
#include "TPoint.h"
#include <cstring>

class TLine : public TBase {
protected:
	TPoint p1, p2;
	virtual void SetChild(TBase* c, int i);

public:
	TLine() {
	}
	TLine(const TPoint& _p1, const TPoint& _p2);
	TLine(const TLine& line);

	virtual void Print();
	TPoint& getFirst();
	TPoint& getSecond();
	virtual double GetVal(int i);
	virtual void SetVal(double val, int i);
	virtual double& operator[](char* name);
	virtual double& operator[](int i);

	virtual TBase* GetChild(int i);

	virtual TBase* Clone();


	friend std::ostream& operator<<(std::ostream& out, const TLine& line)
	{
		out << "(" << line.p1 << "; " << line.p2 << ")";
		return out;
	}
};

TLine::TLine(const TPoint& _p1, const TPoint& _p2) {
	p1 = _p1;
	p2 = _p2;
}
TLine::TLine(const TLine& line) {
	p1 = line.p1;
	p2 = line.p2;
}
void TLine::Print() {
	std::cout << "X0: " << p1.GetX0() << " Y0: " << p1.GetX1() << "\nX1: " << p2.GetX0() << " Y1: " << p2.GetX1() << "\n";
}
TPoint& TLine::getFirst() {
	return p1;
}
TPoint& TLine::getSecond() {
	return p2;
}
double TLine::GetVal(int i) {
	if (i < 0 || i > 3)
		throw - 1;
	if (i == 0)
		return p1.GetX0();
	if (i == 1)
		return p1.GetX1();
	if (i == 2)
		return p2.GetX0();
	if (i == 3)
		return p2.GetX1();
}
void TLine::SetVal(double val, int i) {
	if (i < 0 || i > 3)
		throw - 1;
	if (i == 0)
		p1.SetX0(val);
	if (i == 1)
		p1.SetX1(val);
	if (i == 2)
		p2.SetX0(val);
	if (i == 3)
		p2.SetX1(val);
}

double& TLine::operator[](char* name) {
	if (strlen(name) != 2)
		throw - 1;
	if (name[1] < '1' || name[1] > '4')
		throw - 1;
	if (name[1] - '0' == 1 || name[1] - '0' == 2) {
		return p1[name[1] - '0'];
	}
	if (name[1] - '0' == 2 || name[1] - '0' == 3) {
		return p2[name[1] - '0'];
	}
}

double& TLine::operator[](int i) {
	if (i < 0 || i > 3)
		throw - 1;
	if (i == 0)
		return p1[0];
	if (i == 1)
		return p1[1];
	if (i == 2)
		return p2[0];
	if (i == 3)
		return p2[1];
}

TBase* TLine::GetChild(int i) {
	if (i < 0 || i > 2)
		throw - 1;
	if (i == 0)
		return &p1;
	if (i == 1)
		return &p2;
}
TBase* TLine::Clone()
{
	return new TLine(*this);
}
void TLine::SetChild(TBase* c, int i) {
}