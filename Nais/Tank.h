#ifndef TANK_H
#define TANK_H
#include "Unit.h"
#include "Camera.h"
class Tank : public Unit
{
private:
	double rotireTun;
	double inclinareTun;
	double rotireTank;
public:
	Tank(double a, double b, double c, double rt, double it,double rotireTank);
	Tank();
	void setRotireTun(double);
	void setInclinareTun(double);
	void setRotireTank(double);
	double getRotireTun();
	double getInclinareTun();
	double getRotireTank();
	void Draw();
};

#endif

