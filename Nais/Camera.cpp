#include "Camera.h"

Camera::Camera(double x, double y, double z, double dx, double dy, double dz)
{
	undeX = x;
	undeY = y;
	undeZ = z;
	deUndeX = dx;
	deUndeY = dy;
	deUndeZ = dz;
}

Camera::Camera(){}

void Camera::setUndeX(double x)
{
	undeX = x;
}

void Camera::setUndeY(double y)
{
	undeY = y;
}

void Camera::setUndeZ(double z)
{
	undeZ = z;
}

void Camera::setDeUndeX(double dx)
{
	deUndeX = dx;
}

void Camera::setDeUndeY(double dy)
{
	deUndeY = dy;
}

void Camera::setDeUndeZ(double dz)
{
	deUndeZ = dz;
}

double Camera::getUndeX()
{
	return undeX;
}

double Camera::getUndeY()
{
	return undeY;
}

double Camera::getUndeZ()
{
	return undeZ;
}

double Camera::getDeUndeX()
{
	return deUndeZ;
}

double Camera::getDeUndeY()
{
	return deUndeZ;
}

double Camera::getDeUndeZ()
{
	return deUndeZ;
}