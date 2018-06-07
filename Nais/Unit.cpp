#include "Unit.h"
//#include "Common.h"
Unit::Unit(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

Unit::Unit() {}

void Unit::setx(double a)
{
	x = a;
}

void Unit::sety(double a)
{
	y = a;
}

void Unit::setz(double a)
{
	z = a;
}

double Unit::getx()
{
	return x;
}

double Unit::gety()
{
	return y;
}

double Unit::getz()
{
	return z;
}