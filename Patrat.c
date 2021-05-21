#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <glaux.h>


void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK MutaStanga(void);
void CALLBACK MutaDreapta(void);
void CALLBACK MutaSus(void);
void CALLBACK MutaJos(void);
void CALLBACK rot_z_up(void);
void CALLBACK rot_z_down(void);
void CALLBACK rot_u_up(void);
void CALLBACK rot_d_down(void);



static GLfloat x = 0, y = 0, z = 0, alfa = 90, beta = 90, geta=90;
GLuint fontOffset;


void myinit(void) {
	glClearColor(0.439216, 0.858824, 0.576471, 0.0);
}


void CALLBACK MutaStanga(void)
{
	x = x - 10;
}

void CALLBACK MutaDreapta(void)
{
	x = x + 10;
}
void CALLBACK MutaJos(void)
{
	y = y - 10;
}

void CALLBACK MutaSus(void)
{
	y = y + 10;
}
void CALLBACK rot_z_up(void)
{
	alfa = alfa + 10;
}
void CALLBACK rot_z_down(void)
{
	alfa = alfa - 10;
}

void CALLBACK rot_u_up(void)
{
	beta = beta + 10;
}
void CALLBACK rot_d_down(void)
{
	beta = beta - 10;
}


void CALLBACK rot_dd_down(void)
{
	geta = geta - 10;
}

void CALLBACK rot_dd_up(void)
{
	geta = geta - 10;
}

void CALLBACK display(void)
{
	GLUquadricObj *obj;
	obj = gluNewQuadric();


	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glRotatef(alfa, 0, 1, 0);
	glTranslatef(x, y, z);



	//geam
	glPushMatrix();
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	glTranslatef(50, 20, 0);
	glRotatef(0, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluSphere(obj, 25, 25, 50);
	glPopMatrix();

	//I picior
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(70, -25, 0);
	glRotatef(30, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluCylinder(obj, 1, 1, 40, 10, 20);
	glPopMatrix();

	//II picior
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(70, -25, 0);
	glRotatef(150, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluCylinder(obj, 1, 1, 40, 10, 20);
	glPopMatrix();

	//I roata
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(70, -45, 35);
	glRotatef(90, 0, 0, 1);
	auxSolidTorus(1, 2);
	gluQuadricDrawStyle(obj, GLU_FILL);
	glPopMatrix();

	//II roata
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(70, -45, -35);
	glRotatef(90, 0, 0, 1);
	auxSolidTorus(1, 2);
	gluQuadricDrawStyle(obj, GLU_FILL);
	glPopMatrix();

	//corp
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 0, 1, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluCylinder(obj, 35, 0, 250, 50, 50);
	glPopMatrix();

	//fata avionului
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glRotatef(-90, 0, 1, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluCylinder(obj, 35, 0, 100, 50, 50);
	glPopMatrix();


	//I aripa
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(0, 20, 0);
	glRotatef(90, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_LINE);
	gluPartialDisk(obj, 10, 120, 20, 1, 20, 20);
	glPopMatrix();

	//II aripa
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(0, 20, 0);
	glRotatef(270, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_LINE);
	gluPartialDisk(obj, 10, 120, 20, 1, 20, 20);
	glPopMatrix();

	//III aripa
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(0, -20, 0);
	glRotatef(90, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_LINE);
	gluPartialDisk(obj, 10, 90, 20, 1, 20, 20);
	glColor3f(1.0, 0.5, 0.0);
	glPopMatrix();

	//IV aripa
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(0, -20, 0);
	glRotatef(270, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_LINE);
	gluPartialDisk(obj, 10, 90, 20, 1, 20, 20);
	glPopMatrix();

	//I aripa spate
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(247, 0, 0);
	glRotatef(0, 0, 1, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluPartialDisk(obj, 0, 30, 30, 30, 30, 90);
	glPopMatrix();

	//I aripa laterala-spate
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(247, 0, 0);
	glRotatef(90, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_LINE);
	gluPartialDisk(obj, 10, 40, 20, 1, 20, 20);
	glPopMatrix();

	//II aripa laterala-spate
	glPushMatrix();
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(247, 0, 0);
	glRotatef(270, 1, 0, 0);
	gluQuadricDrawStyle(obj, GLU_LINE);
	gluPartialDisk(obj, 10, 40, 20, 1, 20, 20);
	glPopMatrix();


	glRotatef(beta, 1, 0, 0);
	//I elicee 
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(180, 0, 1, 0);

	glTranslatef(100, -7, +4);
	glRotatef(90, 0, 1, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluPartialDisk(obj, 10, 50, 20, 1, 20, 20);
	glPopMatrix();

	//II elicee 
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(-180, 1, 0, 0);
	glTranslatef(-100, -7, -4);
	glRotatef(270, 0, 1, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluPartialDisk(obj, 10, 50, 20, 1, 20, 20);
	glPopMatrix();


	//baza elice
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(-100, 0, 0);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluSphere(obj, 3, 50, 50);
	glPopMatrix();

	glPopMatrix();


	glFlush();
}


void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-160.0, 160.0, 160.0*(GLfloat)h / (GLfloat)w,
			-160.0*(GLfloat)h / (GLfloat)w, -1000.0, 1000.0);
	else
		glOrtho(-160.0*(GLfloat)w / (GLfloat)h,
			160.0*(GLfloat)w / (GLfloat)h, -160.0, 160.0, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
	auxInitPosition(0, 0, 300, 200);
	auxInitWindow("Project made by Butoi Emanuel-Sebastian");
	myinit();
	auxKeyFunc(AUX_LEFT, MutaStanga);
	auxKeyFunc(AUX_RIGHT, MutaDreapta);
	auxKeyFunc(AUX_UP, MutaSus);
	auxKeyFunc(AUX_DOWN, MutaJos);
	auxKeyFunc(AUX_a, MutaStanga);
	auxKeyFunc(AUX_d, MutaDreapta);
	auxKeyFunc(AUX_w, MutaSus);
	auxKeyFunc(AUX_s, MutaJos);
	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
	auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);
	auxMouseFunc(AUX_LEFTBUTTON, AUX_MOUSEDOWN, rot_z_up);
	auxMouseFunc(AUX_RIGHTBUTTON, AUX_MOUSEDOWN, rot_z_down);
	auxKeyFunc(AUX_1, rot_u_up);
	auxKeyFunc(AUX_2, rot_d_down);




	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}
