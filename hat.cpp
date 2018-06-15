#include <GL/glut.h>
#include <iostream>
#include <algorithm>

using namespace std;


int vertices[8];
int xmax, xmin, ymax, ymin;

void keys(unsigned char ch, int x, int y)
{
	hatch(ch);
}

void hatch(unsigned char ch)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	int i,j;
	if(ch=='h')
	{
		glBegin(GL_LINES)
		{
			for(i=ymin; i<ymax; y++)
			{
				glVertex2f(xmin, i);
				glVertex2f(xmax, i);
			}			
		}
		glEnd();
	}
	else if(ch=='v')
	{
		glBegin(GL_LINES)
		{
			for(i=xmin; i<xmax; i++)
			{
				glVertex2f(i, ymin);
				glVertex2f(i, ymax);
			}
		}
		glEnd();
	}
	else if(ch=='d')
	{
		int slope= (ymax-ymin)/(xmax-xmin);
		int xinc, yinc;
		if(slope>1)
		{
			xinc=slope*5;
			yinc=1;
		}
		else
		{
			xinc=1;
			yinc=(1/slope)*5;
		}
		glBegin(GL_LINES)
		{
			for (i = xmin, j= ymin; i < xmax && j<ymax; i+=xinc, j+=yinc)
			{
				glVertex2f(i, ymax);
				glVertex2f(xmin, j);
				glVertex2f(i, ymin);
				glVertex2f(xmax, j);

			}
		}
		glEnd();
	}
	glFlush();
}

void display()
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3f, 0.2f, 0.5f);
	glBegin(GL_POLYGON);
	{
		for(i=0; i<8; i++)
			glVertex2f(vertices[i], vertices[i+1]);
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	int i;

	cout<<"Enter the coordinates for the vertices of the polygon"<<endl;
	for(i=0; i<4; i++)
		cin>>vertices[i];

	xmax= max(vertices[0], vertices[2], vertices[4], vertices[6]);
	xmin= min(vertices[0], vertices[2], vertices[4], vertices[6]);
	ymax= max(vertices[1], vertices[3], vertices[5], vertices[7]);
	ymin= min(vertices[1], vertices[3], vertices[5], vertices[7]);

	glutInit(&argc,  argv);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100,100);
	glutCreateWindow(Hatching);
	glutDisplayFunc(display);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f)

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODEL_VIEW);
	glLoadIdentity();
	glOrtho2D(0, 300, 0, 300);
	glutKeyboardFunc(keys);
	glMainLoop();

	return (0);
}