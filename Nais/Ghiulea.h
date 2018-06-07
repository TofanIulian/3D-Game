#ifndef GHIULEA_H
#define GHIULEA_H
#include "Unit.h"
class Ghiulea : public Unit
{
private:
	double rotireGhiulea;
	double inclinareGhiulea;
public:
	Ghiulea(double a, double b, double c, double rg, double ig);
	Ghiulea();
	void setRotireGhiulea(double a);
	void setInclinareGhiulea(double a);
	double getRotireGhiulea();
	double getInclinareGhiulea();
	void Draw();
	
};

#endif