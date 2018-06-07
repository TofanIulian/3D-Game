#ifndef CAMERA_H
#define CAMERA_H
class Camera
{
private:
	double undeX;
	double undeY;
	double undeZ;
	double deUndeX;
	double deUndeY;
	double deUndeZ;
public:
	Camera(double, double, double, double, double, double);
	Camera();
	void setUndeX(double);
	void setUndeY(double);
	void setUndeZ(double);
	void setDeUndeX(double);
	void setDeUndeY(double);
	void setDeUndeZ(double);
	double getUndeX();
	double getUndeY();
	double getUndeZ();
	double getDeUndeX();
	double getDeUndeY();
	double getDeUndeZ();
};
#endif
