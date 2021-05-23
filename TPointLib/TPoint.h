#pragma once
#include "TBase.h"

class TBase;

class TPoint : public TBase {
protected:
	double x0, x1;

	virtual TBase* GetChild(int i);
	virtual void SetChild(TBase* c, int i);

public:
	TPoint(double _x0 = 0, double _x1 = 0);
	TPoint(const TPoint& p);

	virtual void Print();
	virtual double GetVal(int i);
	virtual void SetVal(double val, int i);
	virtual double& operator[](char* name);
	virtual double& operator[](int i);

	double GetX0();
	double GetX1();

	void SetX0(double x);
	void SetX1(double x);
	virtual TBase* Clone();

	friend std::ostream& operator<<(std::ostream& out, const TPoint& point)
	{
		out << point.x0 << " " << point.x1;
		return out;
	}

};

TPoint::TPoint(double _x0, double _x1) {
	x0 = _x0;
	x1 = _x1;
}

TPoint::TPoint(const TPoint& p) {
	x0 = p.x0;
	x1 = p.x1;
}

void TPoint::Print() {
	std::cout << "Point X: " << x0 << " " << "Point Y: " << x1 << "\n";
}

double TPoint::GetVal(int i) {
	if (i < 0 || i > 1)
		throw - 1;
	if (i == 0)
		return x0;
	if (i == 1)
		return x1;
}

void TPoint::SetVal(double val, int i) {
	if (i < 0 || i > 1)
		throw - 1;
	if (i == 0)
		x0 = val;
	if (i == 1)
		x1 = val;
}

double& TPoint::operator[](char* name) {
	if (name == "X0")
		return x0;
	else {
		if (name == "X1")
			return x1;
		else
			throw - 1;
	}
}

double& TPoint::operator[](int i) {
	if (i < 0 || i > 1)
		throw - 1;
	if (i == 0)
		return x0;
	if (i == 1)
		return x1;
}

TBase* TPoint::GetChild(int i) {
	return 0;
}
void TPoint::SetChild(TBase* c, int i) {
}

double TPoint::GetX0() {
	return x0;
}

double TPoint::GetX1() {
	return x1;
}

void TPoint::SetX0(double x) {
	x0 = x;
}

void TPoint::SetX1(double x) {
	x1 = x;
}

TBase* TPoint::Clone()
{
	return new TPoint(*this);
}
