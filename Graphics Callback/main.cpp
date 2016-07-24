/*
Autor:ROY SHUBHOBRATA
Project : Solar System
*/

#include <GL\glut.h>
#include <cstdio>

float m = 0.0, v=0.0, e=0.0, ma=0.0, j=0.0, mo=0.0;
float x, y;
float _angle = 0.0;

#include "imageloader.h"

using namespace std;


GLuint _textureId;




void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	glutSwapBuffers();
}

GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
		0,                            //0 for now
		GL_RGB,                       //Format OpenGL uses for image
		image->width, image->height,  //Width and height
		0,                            //The border of the image
		GL_RGB, //GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
		//as unsigned numbers
		image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}


void DrawBackGround()
{
	/*
	glPushMatrix();
	glNormal3f(0, 0, 1);
	glTranslatef(0.0, 0.0, 10.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(-4.0*1.78, -4.0, 0.0);

	glTexCoord2f(0.0, 4.0);
	glVertex3f(-4.0*1.78, 4.0, 0.0);

	glTexCoord2f(3.0, 4.0);
	glVertex3f(4.0*1.78, 4.0, 0.0);

	glTexCoord2f(3.0, 0.0);
	glVertex3f(4.0*1.78, -4.0, 0.0);

	glEnd();

	glPopMatrix();
	*/

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.5, -1.0, 18.0);
	glTexCoord2f(0.0, 6.0);
	glVertex3f(-1.5, 1.0, 18.0);
	glTexCoord2f(5.0, 6.0);
	glVertex3f(1.5, 1.0, 18.0);
	glTexCoord2f(5.0, 0.0);
	glVertex3f(1.5, -1.0, 18.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();



}


void Draw()
{


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	glTranslatef(0, 0, -20);
	

	DrawBackGround();
	glDisable(GL_DEPTH_TEST);

	GLfloat ambientColor[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	glPushMatrix();
	GLfloat lightColor0[] = { 1.5f, 1.5f, 1.5f, 1.0f };
	GLfloat lightPos0[] = { 0, 0, 0, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	glPopMatrix();
	
	GLfloat lightColor1[] = { 2.0f, 2.0f, 2.0f, 1.0f };
	GLfloat lightPos1[] = { 0, 0, 6, 1.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	
	GLfloat lightColor2[] = { 2.0f, 2.0f, 2.0f, 1.0f };
	GLfloat lightPos2[] = { 0, 0, -6, 1.0f };
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor2);
	glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);



	glPushMatrix();
	glEnable(GL_DEPTH_TEST);
	
	
	//sun
	glPushMatrix();
	glColor3f(1, 1, 0);
	glutSolidSphere(1.5, 100, 100);
	glPopMatrix();
	

	//Mercury
	glPushMatrix();
	glRotatef(m, 0, 1, 0);
	glTranslatef(-6, 0, 0);
	glColor3f(1, .7, .3);
	glutSolidSphere(.20, 100, 100);
	glPopMatrix();

	//Venus
	glPushMatrix();
	glRotatef(v , 0, 1, 0);
	glTranslatef(-7, 0, 0);
	glColor3f(.5, .5, .5);
	glutSolidSphere(.20, 100, 100);
	glPopMatrix();


	glPushMatrix();
	glRotatef(e, 0, 1, 0);
	glTranslatef(-8, 0, 0);
	//Earth
	glPushMatrix();
	//glTranslatef(-4-4, 0, 0);
	glColor3f(0, 0, .7);
	glutSolidSphere(.3, 100, 100);
	glPopMatrix();

	//Moon
	glPushMatrix();
	glRotatef(mo, 0, 1, 0);
	glTranslatef(0, 0, -.5);
	//glTranslatef(-4 - 3.5, 0, 0);
	glColor3f(1, 1, 1);
	glutSolidSphere(.10, 100, 100);
	glPopMatrix();

	glPopMatrix();
	
	//Mars
	glPushMatrix();
	glRotatef(ma, 0, 1, 0);
	glTranslatef(-9, 0, 0);
	glColor3f(1, 0, 0);
	glutSolidSphere(.25, 100, 100);
	glPopMatrix();


	//Jupiter
	glPushMatrix();
	glRotatef(j, 0, 1, 0);
	glTranslatef(-10, 0, 0);
	glColor3f(1, .8, .3);
	glutSolidSphere(.6, 100, 100);
	glPopMatrix();

	glDisable(GL_DEPTH_TEST);
	glPopMatrix();
	glutSwapBuffers();
}


void Initialize() {
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHT2);
	glEnable(GL_NORMALIZE);
	glClearColor(0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, 1.78, 1.0, 40.0);

	Image* image = loadBMP("images.bmp");

	_textureId = loadTexture(image);

	delete image;

}


void update(int value)
{
	mo = mo + 2;
	if (mo >360) mo = 0;

	ma = ma + .05;
	if (ma >360) ma = 0;


   	m = m + .2;
	if (m >360) m = 0;

	v = v + .1;
	if (v>360) v = 0;

	e = e + .09;
	if (e>360) e = 0;

	j = j + .025;
	if (j>360) j = 0;

	printf("%lf %lf\n", m,v);
	glutPostRedisplay();

	glutTimerFunc(5, update, value);
}


int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(00, 00);
	glutCreateWindow("Project Opengl ROY SHUBHOBRATA");
	Initialize();
	glutDisplayFunc(Draw);
	glutTimerFunc(250, update, 0);
	glutMainLoop();
	return 0;
}