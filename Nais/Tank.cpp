#include "Tank.h"
#include "Unit.h"
#include <gl/freeglut.h>
#include <cmath>
Tank::Tank(double a, double b, double c, double rtun, double itun,double rtank) : Unit(a, b, c)
{
	rotireTun = rtun;
	inclinareTun = itun;
	rotireTank = rtank;
	//Camera ca(getx(), gety(), getz(), getx(), gety() + 2, getz() + 10);
	//cam = ca;
}

Tank::Tank() :Unit() {}

void Tank::setRotireTun(double rtun)
{
	rotireTun = rtun;
}

void Tank::setInclinareTun(double itun)
{
	inclinareTun = itun;
}

void Tank::setRotireTank(double rtank)
{
	rotireTank = rtank;
}

double Tank::getRotireTun()
{
	return rotireTun;
}

double Tank::getInclinareTun()
{
	return inclinareTun;
}

double Tank::getRotireTank()
{
	return rotireTank;
}

void Tank::Draw()
{
	//cam.setUndeX(getx());
	//cam.setUndeY(gety());
	//cam.setUndeZ(getz());
	glPushMatrix();
		glTranslated(getx(), gety(), getz());
		glColor3f(1, 1, 0);
		glutSolidSphere(0.3, 20, 20);
		glColor3f(0, 0.5, 1);
		glPushMatrix();
			glTranslated(0, -0.9, 0);
			glRotated(rotireTank, 0, 1, 0);
			glutSolidCube(1.5);
		glPopMatrix();
		glPushMatrix();
			glRotated(rotireTun, 0, 1, 0);
			glRotated(inclinareTun, 1, 0, 0);
			glColor3f(0.57, 0.38, 0);
			glutSolidCylinder(0.05, 1, 20, 20);
		glPopMatrix();
	glPopMatrix();
	
}

