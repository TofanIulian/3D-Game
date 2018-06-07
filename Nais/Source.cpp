#include <gl/freeglut.h>
#include <cmath>
#include "Tank.h"
#include "Ghiulea.h"
#include "Racheta.h"
#include "Common.h"
#include "Camera.h"
Tank tank(0, 1, 0, 180, 0, 0);
Ghiulea *ghiulea = new Ghiulea[100];
Racheta racheta;
Camera cam();
int camera = 1;
int g = 0;
double xcOffset = 0, zcOffset = 0;
#define PI 3.14159265
// angle of rotation for the camera direction
float angle = 0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f, ly = 0.0f;
// XZ position of the camera
float xc = 0.0f, zc = 10.0f, yc = 3.0f;
int refreshMills = 8;
void timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

enum {
	IARNA, PRIMAVARA
};

int rendermode = IARNA;

void menu(int selection)
{
	rendermode = selection;
	glutPostRedisplay();
}

void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}


void drawTree() {

	// Draw Body
	glColor3f(0.57, 0.38, 0);
	glPushMatrix();
	glRotated(90, -1, 0, 0);
	glutSolidCylinder(0.1, 3, 20, 20);
	glPopMatrix();

	// Draw Head
	glColor3f(0, 0.6, 0);
	glTranslatef(0.0f, 3.0f, 0.0f);
	glutSolidSphere(1, 20, 20);


}

void primavara()
{
	// Draw ground
	glColor3f(0, 0.71, 0);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	// Draw 36 SnowMen
	for (int i = -3; i < 3; i++)
		for (int j = -3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0, 0, j * 10.0);
			drawTree();
			glPopMatrix();
		}
}

void drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);

	// Draw Body
	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);

	// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);

	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();

	// Draw Nose
	glColor3f(1.0f, 0.5f, 0.5f);
	glutSolidCone(0.08f, 0.5f, 10, 2);
}

void iarna()
{

	// Draw ground
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	//glNormal3i(0, -1, 0);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
	/*
	// Draw 36 SnowMen
	for (int i = -3; i < 3; i++)
	for (int j = -3; j < 3; j++) {
	glPushMatrix();
	glTranslatef(i*10.0, 0, j * 10.0);
	drawSnowMan();
	glPopMatrix();
	}
	*/
}

void drawUnits()
{
	tank.Draw();
	for (int i = 0; i < g; i++)
	{
		ghiulea[i].Draw();
	}
	racheta.Draw();
}

void axeDeCoordonate()
{
	//Sferele
	glColor3f(1, 1, 0);
	glutSolidSphere(0.3, 20, 20);
	glPushMatrix();
	glTranslated(2, 0, 0);
	glColor3f(1, 0, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 2, 0);
	glColor3f(0, 1, 0);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, 2);
	glColor3f(0, 0, 1);
	glutSolidSphere(0.3, 20, 20);
	glPopMatrix();

	//Cilindrele
	glColor3f(1, 0, 0);               //Rosu OZ
	glutSolidCylinder(0.1, 3, 20, 20);
	glColor3f(0, 1, 0);				  //Verde OX
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glutSolidCylinder(0.1, 3, 20, 20);
	glPopMatrix();
	glColor3f(0, 0, 1);				 //Albastru OY
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glutSolidCylinder(0.1, 3, 20, 20);
	glPopMatrix();
}
void lumina()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat pozitial0[] = { 10.0, 5.0, 10.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pozitial0);
	glPushMatrix();
	glTranslated(10, 7, 10);
	glColor3f(1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
}
void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	lumina();

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glLoadIdentity();

	glClearColor(1.0, 1.0, 1.0, 0.0);
	// Set the camera
	if(camera == 1)
		gluLookAt(xc + xcOffset, yc + ly, zc + zcOffset,    tank.getx(), tank.gety(), tank.getz(),       0, 1, 0);
	else
		gluLookAt(racheta.getx()+ xc, racheta.gety() +3, racheta.getz() + zc, racheta.getx(), racheta.gety(), racheta.getz(), 0, 1, 0);

	//gluLookAt(tank.cam.getDeUndeX() + xcOffset, tank.cam.getDeUndeY() + ly, tank.cam.getDeUndeZ() + zcOffset,
	//	tank.cam.getUndeX(), tank.cam.getUndeY(), tank.cam.getUndeZ(),
	//	0, 1, 0);
	axeDeCoordonate();
	drawUnits();
	switch (rendermode) {

	case IARNA:
		iarna();
		break;

	case PRIMAVARA:
		primavara();
		break;
	};

	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		if (camera == 1)
		{
			tank.setz(tank.getz() - sin((tank.getRotireTank() + 90) * PI / 180));
			tank.setx(tank.getx() + cos((tank.getRotireTank() + 90) * PI / 180));
			zcOffset -= sin((tank.getRotireTank() + 90) * PI / 180);
			xcOffset += cos((tank.getRotireTank() + 90) * PI / 180);
		}
		else
		{
			racheta.setInclinareGhiulea(racheta.getInclinareGhiulea() + 2);
		}
		break;
	case 's':
		if (camera == 1)
		{
			tank.setz(tank.getz() + sin((tank.getRotireTank() + 90) * PI / 180));
			tank.setx(tank.getx() - cos((tank.getRotireTank() + 90) * PI / 180));
			zcOffset += sin((tank.getRotireTank() + 90) * PI / 180);
			xcOffset -= cos((tank.getRotireTank() + 90) * PI / 180);
		}
		else
		{
			racheta.setInclinareGhiulea(racheta.getInclinareGhiulea() - 2);
		}
		break;
	case 'a':
		if (camera == 1)
		{
			angle += 0.0175f;
			tank.setRotireTank(tank.getRotireTank() + 1);
		}
		else
		{
			racheta.setRotireGhiulea(racheta.getRotireGhiulea() + 2);

		}
		xc = 10 * sin(angle);
		zc = 10 * cos(angle);
		break;
	case 'd':
		if (camera == 1)
		{
			angle += 0.0175f;
			tank.setRotireTank(tank.getRotireTank() - 1);
		}
		else
		{
			racheta.setRotireGhiulea(racheta.getRotireGhiulea() - 2);

		}
		angle -= 0.0175f;
		xc = 10 * sin(angle);
		zc = 10 * cos(angle);
	break;
	case 'l':
		tank.setRotireTun(tank.getRotireTun() - 1);
		if (tank.getRotireTun() == 360 || tank.getRotireTun() == -360)
			tank.setRotireTun(0);
		break;
	case 'j':
		tank.setRotireTun(tank.getRotireTun() + 1);
		if (tank.getRotireTun() == 360 || tank.getRotireTun() == -360)
			tank.setRotireTun(0);
		break;
	case 'i':
		tank.setInclinareTun(tank.getInclinareTun() - 1);
		break;
	case 'k':
		tank.setInclinareTun(tank.getInclinareTun() + 1);
		break;
	case 'f':
	{
		Ghiulea giu(tank.getx(), tank.gety(), tank.getz(), tank.getRotireTun(), tank.getInclinareTun());
		ghiulea[g] = giu;
		g++;
	}
		break;
	case 'r':
	{
		Racheta r(tank.getx(), tank.gety(), tank.getz(), tank.getRotireTun(), tank.getInclinareTun());
		racheta = r;
		break;
	}
	
		break;
	case '1':
		camera = 1;
		break;
	case '2':
		camera = 2;
		break;
	}
	if (key == 27)
		exit(0);

}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {

	case GLUT_KEY_UP:
		yc -= 0.1;
		break;
	case GLUT_KEY_DOWN:
		yc += 0.1;
		break;
	case GLUT_KEY_LEFT:
		angle -= 0.02f;
		xc = 10 * sin(angle);
		zc = 10 * cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.02f;
		xc = 10 * sin(angle);
		zc = 10 * cos(angle);
		break;

	}
}

int main(int argc, char **argv) {

	// init GLUT and create window
	int ok = 0;
	if(ok==0)
	{
		
		ok = 1;
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	glutCreateMenu(menu);
	glutAddMenuEntry("Iarna", IARNA);
	glutAddMenuEntry("Primavara", PRIMAVARA);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// enter GLUT event processing cycle
	glutTimerFunc(0, timer, 0);

	glutMainLoop();

	return 1;
}
