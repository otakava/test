#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>

float pos_x = 0, pos_y = 0;
bool isRight = true;

// блок объ€влений функций
void renderScene(void);
void processKeys(unsigned char key, int x, int y); // определение фнкции перед фукнцией main
// блок реализации функций

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);

	glutKeyboardFunc(processKeys);

    glutMainLoop();
    return 0;
}

void processKeys(unsigned char key, int x, int y) {
	if (key == 100) {
		pos_x = pos_x + 0.1;
		isRight = false;
	}

	if (key == 97) {
		pos_x = pos_x - 0.1;
		isRight = true;
	}

	if (key == 115) {
		pos_y = pos_y - 0.1;
	}

	if (key == 119) {
		pos_y = pos_y + 0.1;
	}
	if (key ==13)
		exit(0); // close app

	glutPostRedisplay(); // отрисовка
}
void drawcat(float x, float y, bool isRight)  {
	glPushMatrix();
	glScalef(0.20,0.20, 0);
	glTranslatef(x,y,0);
	glRotatef(90,0,0,1);
	if (isRight)
		glRotatef(180, 0, 0, 1);
	glBegin(GL_TRIANGLES);

	//хвост
	glColor3f(0,0,0);
	glVertex2f(0.6, 0.05);
	glVertex2f(-0.25, -0.5);
	glVertex2f(0.6, -0.1);
	//тело
	glColor3f(0.29, 0.29, 0.30);
	glVertex2f(-0.0, 0.2);
	glColor3f(0.23, 0.24, 0.24);
	glVertex2f(0.3, -0.5);
	glColor3f(0.69, 0.71, 0.70);
	glVertex2f(-0.3, -0.5);
	//морда
	glColor3f(0.63, 0.63, 0.63);
	glVertex2f(-0.3, 0.5);
	glColor3f(0.3, 0.3, 0.3);
	glVertex2f(0.3, 0.5);
	glColor3f(1, 1, 1);
	glVertex2f(0.0, 0.1);
	//левый глаз
	glColor3f(.95, .75, .65);
	glVertex2f(-0.2, 0.45);
	glVertex2f(-0.15, 0.4);
	glVertex2f(-0.25, 0.45);
	//правый глаз
	glColor3f(0.95, 0.75, 0.65);
	glVertex2f(0.2, 0.45);
	glVertex2f(0.15, 0.4);
	glVertex2f(0.25, 0.45);
	//левое ухо
	glColor3f(0.8, 0.0, 0.0);
	glVertex2f(-0.3, 0.5);
	glVertex2f(-0.4, 0.6);
	glVertex2f(-0.2, 0.5);
	//правое ухо
	glColor3f(0.8, 0.0, 0.0);
	glVertex2f(0.3, 0.5);
	glVertex2f(0.4, 0.6);
	glVertex2f(0.2, 0.5);
	//нос
	glColor3f(0.8, 0.0, 0.0);
	glVertex2f(-0.03, 0.3);
	glVertex2f(0.0, 0.26);
	glVertex2f(0.03, 0.3);
	glEnd();
	glPopMatrix();
}
void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функци€ должна быть первой в renderScene
	
	/*drawgreen(0, 0);

	drawfon(0,0);

	drawdimohod(0, -0.05);

	drawhome(0.2, -0.3);

	drawhtree(-1.2, 0);

	drawdrow(3.5,0.8);

	drawdoghome(-2.,-1);*/
	drawcat(pos_x, pos_y, isRight); 
	
	/*drafGraf(); */

	glutSwapBuffers();
}


