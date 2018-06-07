#include "Ghiulea.h"
#include <Unit.h>
#include <gl/freeglut.h>
#include <cmath>
#define PI 3.14159265
Ghiulea::Ghiulea(double a, double b, double c, double rg, double ig) :Unit(a, b, c)
{
	rotireGhiulea = rg;
	inclinareGhiulea = ig;
}

Ghiulea::Ghiulea() :Unit() {}

void Ghiulea::setRotireGhiulea(double a)
{
	rotireGhiulea = a;
}

void Ghiulea::setInclinareGhiulea(double a)
{
	inclinareGhiulea = a;
}

double Ghiulea::getRotireGhiulea()
{
	return rotireGhiulea;
}

double Ghiulea::getInclinareGhiulea()
{
	return inclinareGhiulea;
}

void Ghiulea::Draw()
{
	glPushMatrix();
		glTranslated(getx(), gety(), getz());
		//glPushMatrix();
		//glRotated(fps*viteza, 0.0, 0.0, 1.0);
		glColor3f(1, 1, 0);
		glutSolidSphere(0.2, 20, 20);
		//glPopMatrix();
	glPopMatrix();
	setx(getx() - sin((inclinareGhiulea + 90) * PI / 180.0)*cos((rotireGhiulea + 90) * PI / 180.0)/3) ;
	setz(getz() + sin((inclinareGhiulea + 90) * PI / 180.0)*sin((rotireGhiulea + 90) * PI / 180.0)/3) ;
	sety(gety() + cos((inclinareGhiulea + 90) * PI / 180.0)/3);
}
