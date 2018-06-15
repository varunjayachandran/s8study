#include <GL\glut.h>
#include <iostream>

using namespace std;

void display1()
{
	glBegin(GL_LINE)
	{
		glvertex2f(75, 75);
		glvertex2f(200, 200);
	}
	glFlush();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(PROJECTION_MATRIX);
	glLoadIdentity();
	glOrtho2d(50, 320, 50, 320);
	glMatrixMode(MODEL_VIEW_MATRIX);
	glLoadIdentity();
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Test");
	glutDisplayFunc("display1");
	glutMainLoop();

	return(0);
}