#ifndef UNIT_H
#define UNIT_H
class Unit
{
private:
	double x;
	double y;
	double z;
public:
	Unit(double, double, double);
	Unit();
	void setx(double a);
	void sety(double a);
	void setz(double a);
	double getx();
	double gety();
	double getz();
	virtual void Draw() = 0;
};

#endif // UNIT_H