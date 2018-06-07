#pragma once
#include "Ghiulea.h"
class Racheta: public Ghiulea
{
private:
	double unghiZbor;
public:
	void setUnghiZbor(double);
	double getUnghiZbor();
	Racheta(double a, double b, double c, double rg, double ig);
	Racheta();
	void Draw();
};

