#include "Racheta.h"
#include "Ghiulea.h"
#include <Unit.h>
#include <gl/freeglut.h>
#include <cmath>
#define PI 3.14159265

Racheta::Racheta(double a, double b, double c, double rg, double ig) :Ghiulea(a, b, c, rg, ig) {}
Racheta::Racheta() :Ghiulea() {}

void Racheta::setUnghiZbor(double uz)
{
	unghiZbor = uz;
}
double Racheta::getUnghiZbor()
{
	return unghiZbor;
}

void Racheta::Draw()
{
	glPushMatrix();
	glTranslated(getx(), gety(), getz());
	glRotated(getRotireGhiulea(), 0, 1, 0);
	glRotated(getInclinareGhiulea(), 1, 0, 0);
	//glPushMatrix();
	//glRotated(fps*viteza, 0.0, 0.0, 1.0);
	glColor3f(1, 1, 0);
	glutSolidCylinder(0.05, 1, 20, 20);
	//glPopMatrix();
	glPopMatrix();
	setx(getx() - sin((getInclinareGhiulea() + 90) * PI / 180.0)*cos((getRotireGhiulea() + 90) * PI / 180.0)/18);
	setz(getz() + sin((getInclinareGhiulea() + 90) * PI / 180.0)*sin((getRotireGhiulea() + 90) * PI / 180.0)/18);
	sety(gety() + cos((getInclinareGhiulea() + 90) * PI / 180.0)/18);
}
