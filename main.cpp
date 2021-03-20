#include<iostream>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.14159265358979323846

using namespace std;

GLfloat arcPos = 0.0f;
GLfloat smallarcpos1 = -380.0f;
GLfloat smallarcpos2 = 200.0f;
GLfloat arcSmallSpeed = 0.2f;
GLfloat arcSpeed = 0.2f;

GLfloat positionSun = 0.0f;
GLfloat speedSun = 0.02f;


GLfloat positionCloud = 0.0f;
GLfloat positionCloud2 = 700.0f;
GLfloat speedCloud = 0.1f;


GLfloat smokepos1 = 175.0f;
GLfloat smokepos2 = 175.0f;
GLfloat smokepos3 = 175.0f;
GLfloat smokepos4 = 175.0f;
GLfloat smokespeed = 0.2f;

GLfloat trainpos1 = -370.0f;
GLfloat trainpos2 = 320.0f;
GLfloat trainspeed = 0.8f;

GLfloat carpos1 = 0.0f;
GLfloat carpos2 = 600.0f;
GLfloat carspeed = 1.0f;

const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;

void update(int value) {


    if(arcPos < -660)
        arcPos = 600;

     arcPos -= arcSpeed;

    if(arcSpeed < 0)
    {
        arcSpeed = 0;

    }
	glutPostRedisplay();

	///SMALL ARC 1 SPEED
    if(smallarcpos1 > 660)
        smallarcpos1 = -600;

     smallarcpos1 += arcSmallSpeed;

    if(arcSpeed < 0)
    {
        arcSpeed = 0;

    }
	glutPostRedisplay();

	///SMALL ARC 2 SPEED
    if(smallarcpos2 > 660)
        smallarcpos2 = -600;

     smallarcpos2 += arcSmallSpeed;

    if(arcSpeed < 0)
    {
        arcSpeed = 0;

    }
	glutPostRedisplay();

	glutTimerFunc(10, update, 0);
}

void updateSun(int value) {
    if(positionSun > 100)
        positionSun = -50.0f;
    positionSun += speedSun;
	glutPostRedisplay();
	glutTimerFunc(10, updateSun, 0);
}



void updateCloud(int value) {
    if(positionCloud > 640.0)
        positionCloud = -500.0f;
    positionCloud += speedCloud;
	glutPostRedisplay();

	 if(positionCloud2 > 640.0)
        positionCloud2 = -500.0f;
    positionCloud2 += speedCloud;
	glutPostRedisplay();
	glutTimerFunc(10, updateCloud, 0);
}


void updatesmoke(int value) {
    if(smokepos1 > 200)
        smokepos1 = 0.0f;
    smokepos1 += smokespeed;
	glutPostRedisplay();

	if(smokepos2 > 250)
        smokepos2 = 0.0f;
    smokepos2 += smokespeed;
	glutPostRedisplay();

	if(smokepos3 > 300)
        smokepos3 = 0.0f;
    smokepos3 += smokespeed;
	glutPostRedisplay();

	if(smokepos4 > 350)
        smokepos4 = 0.0f;
    smokepos4 += smokespeed;
	glutPostRedisplay();
	glutTimerFunc(10, updatesmoke, 0);
}

void updateTrain(int value) {
    if(trainpos2 < -600)
        trainpos2 = 320.0f;
    trainpos2 -= trainspeed;
	glutPostRedisplay();

    if(trainpos1 > 800)
        trainpos1 = -400.0f;
    trainpos1 += trainspeed;
	glutPostRedisplay();
	glutTimerFunc(10, updateTrain, 0);
}


void updateCar(int value) {
    if(carpos1 > 600)
        carpos1 = -300.0f;
    carpos1 += carspeed;
	glutPostRedisplay();

	if(carpos2 < -700)
        carpos2 = 900.0f;
    carpos2 -= carspeed;
	glutPostRedisplay();

	glutTimerFunc(10, updateCar, 0);
}

void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

/*void handleMouse(int button, int state, int x, int y) {
	if ()
	{

	}


	glutPostRedisplay();
}*/

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'A':
    arcSpeed += 0.1f;
    break;
    glutPostRedisplay();

case 'D':
    arcSpeed -= 0.1f;
    break;
    glutPostRedisplay();

case ' ':
    arcSpeed = 0.0f;
    speedSun = 0.0f;
    speedCloud = 0.0f;
    trainspeed = 0.0f;
    carspeed = 0.0f;
    break;
    glutPostRedisplay();

case 'M':
    arcSpeed = 0.2f;
    speedSun = 0.02f;
    speedCloud = 0.1f;
    trainspeed = 0.8f;
    carspeed = 1.0F;
    break;
    glutPostRedisplay();

case 'L':
    arcSpeed = 0.1f;
    speedSun = 0.01f;
    speedCloud = 0.05f;
    carspeed = 0.5;
    trainspeed = 0.4f;
    break;
    glutPostRedisplay();

    break;
    glutPostRedisplay();

	}
}



void myDisplay(void)
{


glClear (GL_COLOR_BUFFER_BIT);

///sky
	glBegin(GL_QUADS);
	glColor3ub(153, 204, 255);
	glVertex2f(0,480);
	glVertex2f(0,340);
	glVertex2f(640,340);
	glVertex2f(640,480);
	glEnd();
int i1;

///sun
glPushMatrix();
glTranslatef(0.0f,positionSun, 0.0f);


	GLfloat x1=555;  GLfloat y1=400;  GLfloat radius1 =20.0f;
	 int triangleAmount = 100; //# of triangles used to draw circle


	 GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();



///clouds 1
glPushMatrix();
glTranslatef(positionCloud,0.0f, 0.0f);
	GLfloat x2=40; GLfloat y2=450; GLfloat radius2 =20.0f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,253);
		glVertex2f(x2, y2); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x2 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y2 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x3=80; GLfloat y3=450;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,250);
		glVertex2f(x3, y3); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x3 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y3 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x4=65; GLfloat y4=460;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,245);
		glVertex2f(x4, y4); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x4 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y4 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat x5=65; GLfloat y5=450;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,253);
		glVertex2f(x5, y5); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x5 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y5 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x6=50; GLfloat y6=440;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,250);
		glVertex2f(x6, y6); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x6 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y6 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x7=300; GLfloat y7=465;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,245);
		glVertex2f(x7, y7); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x7 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y7 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat x8=280; GLfloat y8=450;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,253);
		glVertex2f(x8, y8); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x8 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y8 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat x9=310; GLfloat y9=450;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250,255,253);
		glVertex2f(x9, y9); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x9 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y9 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();


///CLOUDS 2
glPushMatrix();
glTranslatef(positionCloud2,0.0f, 0.0f);
	 x2=40;  y2=450;  radius2 =20.0f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,253);
		glVertex2f(x2, y2); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x2 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y2 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	 x3=80;  y3=450;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,250);
		glVertex2f(x3, y3); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x3 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y3 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	 x4=65;  y4=460;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,250,245);
		glVertex2f(x4, y4); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x4 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y4 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

 x5=65;  y5=450;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,253);
		glVertex2f(x5, y5); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x5 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y5 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	 x6=50;  y6=440;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,250);
		glVertex2f(x6, y6); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x6 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y6 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	 x7=300;  y7=465;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,245);
		glVertex2f(x7, y7); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x7 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y7 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	 x8=280;  y8=450;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,253);
		glVertex2f(x8, y8); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x8 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y8 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

    x9=310;  y9=450;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(250,255,253);
		glVertex2f(x9, y9); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x9 + (radius2 * cos(i1 *  twicePi / triangleAmount)),
			    y9 + (radius2 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();




///VALLEY 1
	 x1=600;  y1=340;  radius1 =70.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(140,179,114);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
///VALLEY 3
	 x1=450;  y1=360;  radius1 =70.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(140,179,114);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

///VALLEY 4
	 x1=350;  y1=360;  radius1 =70.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(191,235,162);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

///VALLEY 7
	 x1=440;  y1=360;  radius1 =50.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(95,209,20);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

///VALLEY 5
	 x1=410;  y1=320;  radius1 =70.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(87,174,29);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();


///VALLEY 2
	 x1=540;  y1=360;  radius1 =70.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(160,218,121);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();


///VALLEY 6
	 x1=530;  y1=340;  radius1 =70.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(83,185,14);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();




///SMALL TREES
    //1
    x1=420;  y1=430;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//1
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(420,430);
glVertex2f(420,420);
glEnd();

//2
	x1=430;  y1=432;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//2
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(430,430);
glVertex2f(430,425);
glEnd();

	//3
	x1=440;  y1=434;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//3
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(440,432);
glVertex2f(440,425);
glEnd();

	//4
	x1=450;  y1=434;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//4
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(450,432);
glVertex2f(450,425);
glEnd();

	//5
	x1=460;  y1=432;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//5
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(460,432);
glVertex2f(460,425);
glEnd();

	//6
	x1=470;  y1=432;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//6
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(470,432);
glVertex2f(470,425);
glEnd();

	//7
	x1=480;  y1=430;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//7
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(480,430);
glVertex2f(480,420);
glEnd();

//8
	x1=490;  y1=429;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//8
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(490,428);
glVertex2f(490,416);
glEnd();

//9
	x1=500;  y1=430;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//9
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(500,428);
glVertex2f(500,416);
glEnd();

//10
	x1=510;  y1=432;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//10
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(510,430);
glVertex2f(510,420);
glEnd();

//11
	x1=520;  y1=434;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//11
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(520,430);
glVertex2f(520,425);
glEnd();

//12
	x1=540;  y1=434;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//12
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(540,432);
glVertex2f(540,428);
glEnd();

//13
	x1=555;  y1=432;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//13
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(555,430);
glVertex2f(555,420);
glEnd();

//14
	x1=565;  y1=432;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//14
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(565,430);
glVertex2f(565,425);
glEnd();
//15
	x1=575;  y1=428;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//15
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(575,426);
glVertex2f(575,420);
glEnd();
//16
	x1=590;  y1=424;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//16
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(590,422);
glVertex2f(590,410);
glEnd();
//17
	x1=600;  y1=420;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//17
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(600,418);
glVertex2f(600,410);
glEnd();
//18
	x1=610;  y1=418;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//18
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(610,415);
glVertex2f(610,408);
glEnd();
//19
	x1=630;  y1=410;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//19
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(630,408);
glVertex2f(630,402);
glEnd();

//20
	x1=410;  y1=410;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//20
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(410,408);
glVertex2f(410,400);
glEnd();
//21
	x1=425;  y1=412;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//21
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(425,408);
glVertex2f(425,402);
glEnd();
//22
	x1=440;  y1=420;  radius1 =3.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//22
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(440,417);
glVertex2f(440,410);
glEnd();

//23
	x1=455;  y1=412;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//23
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(455,408);
glVertex2f(455,402);
glEnd();

//24
	x1=490;  y1=408;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//24
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(490,404);
glVertex2f(490,397);
glEnd();
//25
	x1=505;  y1=408;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//25
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(505,406);
glVertex2f(505,399);
glEnd();
//26
	x1=515;  y1=414;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//26
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(515,412);
glVertex2f(515,408);
glEnd();
//27
	x1=530;  y1=416;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//27
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(530,412);
glVertex2f(530,408);
glEnd();
//28
	x1=540;  y1=418;  radius1 =3.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//28
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(540,415);
glVertex2f(540,408);
glEnd();
//29
	x1=555;  y1=410;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//29
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(555,408);
glVertex2f(555,402);
glEnd();
//30
	x1=565;  y1=408;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//30
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(565,404);
glVertex2f(565,400);
glEnd();
//31
	x1=575;  y1=404;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//31
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(575,401);
glVertex2f(575,394);
glEnd();

//32
	x1=590;  y1=404;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//32
glLineWidth(1);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(590,401);
glVertex2f(590,394);
glEnd();

//33
	x1=575;  y1=404;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//33
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(575,401);
glVertex2f(575,394);
glEnd();

//34
	x1=620;  y1=404;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//34
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(620,401);
glVertex2f(620,394);
glEnd();

 //35
    x1=395;  y1=400;  radius1 =5.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//35
glLineWidth(3);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(395,395);
glVertex2f(395,388);
glEnd();
 //36
    x1=415;  y1=394;  radius1 =5.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//36
glLineWidth(3);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(415,390);
glVertex2f(415,380);
glEnd();
 //37
    x1=435;  y1=400;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//37
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(435,396);
glVertex2f(435,385);
glEnd();
 //-38
    x1=382;  y1=390;  radius1 =4.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//38
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(382,386);
glVertex2f(382,380);
glEnd();

 //0
    x1=405;  y1=420;  radius1 =3.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//0
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(405,417);
glVertex2f(405,412);
glEnd();

 //-1
    x1=395;  y1=420;  radius1 =3.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//-1
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(395,417);
glVertex2f(395,412);
glEnd();

 //-2
    x1=382;  y1=425;  radius1 =3.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(35,88,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//-2
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(102,51,0);
glVertex2f(382,422);
glVertex2f(382,417);
glEnd();

///

///road
	glBegin(GL_QUADS);
	glColor3ub(64, 64, 64);
	glVertex2f(0,200);
	glVertex2f(0,0);
	glVertex2f(640,0);
	glVertex2f(640,200);
	glEnd();

///ground footpath
	glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2f(0,200);
	glVertex2f(0,150);
	glVertex2f(640,150);
	glVertex2f(640,200);
	glEnd();
//footpath boundary
    glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2f(0,150);
	glVertex2f(0,140);
	glVertex2f(640,140);
	glVertex2f(640,150);
	glEnd();
	//footpath boundary underline
    glBegin(GL_LINES);
	glColor3ub(255, 255, 0);
	glVertex2f(0,140);
	glVertex2f(640,140);

	glEnd();

///road divider 1
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(0,82);
	glVertex2f(0,70);
	glVertex2f(40,70);
	glVertex2f(40,82);
	glEnd();
///road divider 2
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(80,82);
	glVertex2f(80,70);
	glVertex2f(160,70);
	glVertex2f(160,82);
	glEnd();
///road divider 3
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(200,82);
	glVertex2f(200,70);
	glVertex2f(280,70);
	glVertex2f(280,82);
	glEnd();
/*//road divider 4
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(320,82);
	glVertex2f(320,70);
	glVertex2f(400,70);
	glVertex2f(400,82);
	glEnd();*/
///road divider 5
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(440,82);
	glVertex2f(440,70);
	glVertex2f(520,70);
	glVertex2f(520,82);
	glEnd();
///road divider 6
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(560,82);
	glVertex2f(560,70);
	glVertex2f(640,70);
	glVertex2f(640,82);
	glEnd();

///ZEBRA CROSSING UP 1
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(320,100);
glVertex2f(320,88);
glVertex2f(400,88);
glVertex2f(400,100);
glEnd();
///ZEBRA CROSSING UP 2
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(321,118);
glVertex2f(321,106);
glVertex2f(399,106);
glVertex2f(399,118);
glEnd();
///ZEBRA CROSSING UP 3
glBegin(GL_QUADS);
glColor3ub(255,255,255);
glVertex2f(322,136);
glVertex2f(322,124);
glVertex2f(398,124);
glVertex2f(398,136);
glEnd();
///ZEBRA CROSSING MIDDLE
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(319,82);
	glVertex2f(319,70);
	glVertex2f(401,70);
	glVertex2f(401,82);
	glEnd();
///ZEBRA CROSSING DOWN 1
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(318,64);
	glVertex2f(318,52);
	glVertex2f(402,52);
	glVertex2f(402,64);
	glEnd();
///ZEBRA CROSSING DOWN 2
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(317,46);
	glVertex2f(317,34);
	glVertex2f(403,34);
	glVertex2f(403,46);
	glEnd();
///ZEBRA CROSSING DOWN 3
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(316,28);
	glVertex2f(316,16);
	glVertex2f(404,16);
	glVertex2f(404,28);
	glEnd();
///ZEBRA CROSSING DOWN 4
    glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(315,10);
	glVertex2f(315,0);
	glVertex2f(405,0);
	glVertex2f(405,10);
	glEnd();
///river

	glBegin(GL_QUADS);
	glColor3ub(76, 158, 240);
	glVertex2f(0,350);
	glVertex2f(0,200);
	glVertex2f(640,200);
	glVertex2f(640,350);
	glEnd();


///ground top of river
    glBegin(GL_QUADS);
	glColor3ub(96, 96, 96);
	glVertex2f(0,350);
	glVertex2f(0,340);
	glVertex2f(640,340);
	glVertex2f(640,350);
	glEnd();


///ground bottom of river
    glBegin(GL_QUADS);
	glColor3ub(96, 96, 96);
	glVertex2f(0,210);
	glVertex2f(0,200);
	glVertex2f(640,200);
	glVertex2f(640,210);
	glEnd();


///ground valley road back
	glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2f(0,365);
	glVertex2f(0,360);
	glVertex2f(640,360);
	glVertex2f(640,365);
	glEnd();

///ground valley road front
	glBegin(GL_QUADS);
	glColor3ub(255, 229, 204);
	glVertex2f(0,360);
	glVertex2f(0,350);
	glVertex2f(640,350);
	glVertex2f(640,360);
	glEnd();
	//valley1
	glBegin(GL_TRIANGLES);
	glColor3ub(95, 121, 82);
	glVertex2f(420,365);
	glVertex2f(520,365);
	glVertex2f(470,410);
	glEnd();

///TRAIN LINE 1
    //SIDEPATH UNDER
    glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glVertex2f(0,361);
	glVertex2f(640,361);
	glEnd();
    //SIDEPATH TOP
    glBegin(GL_LINES);
	glVertex2f(0,363);
	glVertex2f(550,363);
	glEnd();
	//INSIDE STEP 1
    glBegin(GL_LINES);
	glVertex2f(380,360);
	glVertex2f(382,363);
	glEnd();
	//INSIDE STEP 2
    glBegin(GL_LINES);
	glVertex2f(382,360);
	glVertex2f(384,363);
	glEnd();
	//INSIDE STEP 3
    glBegin(GL_LINES);
	glVertex2f(388,360);
	glVertex2f(390,363);
	glEnd();
	//INSIDE STEP 4
    glBegin(GL_LINES);
	glVertex2f(390,360);
	glVertex2f(392,363);
	glEnd();
	//INSIDE STEP 5
    glBegin(GL_LINES);
	glVertex2f(398,360);
	glVertex2f(400,363);
	glEnd();
	//INSIDE STEP 6
    glBegin(GL_LINES);
	glVertex2f(400,360);
	glVertex2f(402,363);
	glEnd();
	//INSIDE STEP 7
    glBegin(GL_LINES);
	glVertex2f(408,360);
	glVertex2f(410,363);
	glEnd();
	//INSIDE STEP 8
    glBegin(GL_LINES);
	glVertex2f(410,360);
	glVertex2f(412,363);
	glEnd();
	//INSIDE STEP 9
    glBegin(GL_LINES);
	glVertex2f(418,360);
	glVertex2f(420,363);
	glEnd();
	//INSIDE STEP 10
    glBegin(GL_LINES);
	glVertex2f(420,360);
	glVertex2f(422,363);
	glEnd();
	//INSIDE STEP 11
    glBegin(GL_LINES);
	glVertex2f(428,360);
	glVertex2f(430,363);
	glEnd();
	//INSIDE STEP 12
    glBegin(GL_LINES);
	glVertex2f(430,360);
	glVertex2f(432,363);
	glEnd();
	//INSIDE STEP 13
    glBegin(GL_LINES);
	glVertex2f(438,360);
	glVertex2f(440,363);
	glEnd();
	//INSIDE STEP 14
    glBegin(GL_LINES);
	glVertex2f(440,360);
	glVertex2f(442,363);
	glEnd();
	//INSIDE STEP 15
    glBegin(GL_LINES);
	glVertex2f(448,360);
	glVertex2f(450,363);
	glEnd();
	//INSIDE STEP 16
    glBegin(GL_LINES);
	glVertex2f(450,360);
	glVertex2f(452,363);
	glEnd();
	//INSIDE STEP 17
    glBegin(GL_LINES);
	glVertex2f(458,360);
	glVertex2f(460,363);
	glEnd();
	//INSIDE STEP 18
    glBegin(GL_LINES);
	glVertex2f(460,360);
	glVertex2f(462,363);
	glEnd();
	//INSIDE STEP 19
    glBegin(GL_LINES);
	glVertex2f(468,360);
	glVertex2f(470,363);
	glEnd();
	//INSIDE STEP 20
    glBegin(GL_LINES);
	glVertex2f(470,360);
	glVertex2f(472,363);
	glEnd();
	//INSIDE STEP 21
    glBegin(GL_LINES);
	glVertex2f(478,360);
	glVertex2f(480,363);
	glEnd();
	//INSIDE STEP 22
    glBegin(GL_LINES);
	glVertex2f(480,360);
	glVertex2f(482,363);
	glEnd();
	//INSIDE STEP 23
    glBegin(GL_LINES);
	glVertex2f(488,360);
	glVertex2f(490,363);
	glEnd();
	//INSIDE STEP 24
    glBegin(GL_LINES);
	glVertex2f(490,360);
	glVertex2f(492,363);
	glEnd();
	//INSIDE STEP 25
    glBegin(GL_LINES);
	glVertex2f(498,360);
	glVertex2f(500,363);
	glEnd();
	//INSIDE STEP 26
    glBegin(GL_LINES);
	glVertex2f(500,360);
	glVertex2f(502,363);
	glEnd();
	//INSIDE STEP 27
    glBegin(GL_LINES);
	glVertex2f(508,360);
	glVertex2f(510,363);
	glEnd();
	//INSIDE STEP 28
    glBegin(GL_LINES);
	glVertex2f(510,360);
	glVertex2f(512,363);
	glEnd();
	//INSIDE STEP 29
    glBegin(GL_LINES);
	glVertex2f(518,360);
	glVertex2f(520,363);
	glEnd();
	//INSIDE STEP 30
    glBegin(GL_LINES);
	glVertex2f(520,360);
	glVertex2f(522,363);
	glEnd();
	//INSIDE STEP 31
    glBegin(GL_LINES);
	glVertex2f(528,360);
	glVertex2f(530,363);
	glEnd();
	//INSIDE STEP 32
    glBegin(GL_LINES);
	glVertex2f(530,360);
	glVertex2f(532,363);
	glEnd();
	//INSIDE STEP 33
    glBegin(GL_LINES);
	glVertex2f(538,360);
	glVertex2f(540,363);
	glEnd();
	//INSIDE STEP 34
    glBegin(GL_LINES);
	glVertex2f(540,360);
	glVertex2f(542,363);
	glEnd();
	//INSIDE STEP 35
    glBegin(GL_LINES);
	glVertex2f(548,360);
	glVertex2f(550,363);
	glEnd();
	//INSIDE STEP 36
    glBegin(GL_LINES);
	glVertex2f(550,360);
	glVertex2f(552,363);
	glEnd();


///TRAIN 1
glPushMatrix();
glTranslatef(trainpos1,3.0f,0.0f);
///Engine head
    glBegin(GL_TRIANGLES);
	glColor3ub(255, 51, 51);
	glVertex2f(734,375);
	glVertex2f(734,360);
	glVertex2f(752,360);
	glEnd();
///Engine body
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 51);
	glVertex2f(722,375);
	glVertex2f(722,360);
	glVertex2f(734,360);
	glVertex2f(734,375);
	glEnd();
	//window1
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(733,372);
	glVertex2f(733,367);
	glVertex2f(742,367);
	glVertex2f(736,372);
	glEnd();
	//window2
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(724,372);
	glVertex2f(724,367);
	glVertex2f(730,367);
	glVertex2f(730,372);
	glEnd();

///boggy1
	glBegin(GL_QUADS);
	glColor3ub(204, 153, 255);
	glVertex2f(320,375);
	glVertex2f(320,360);
	glVertex2f(398,360);
	glVertex2f(398,375);
	glEnd();
	//window1
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(322,372);
	glVertex2f(322,367);
	glVertex2f(330,367);
	glVertex2f(330,372);
	glEnd();
	//window2
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(332,372);
	glVertex2f(332,367);
	glVertex2f(340,367);
	glVertex2f(340,372);
	glEnd();
	//window3
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(342,372);
	glVertex2f(342,367);
	glVertex2f(350,367);
	glVertex2f(350,372);
	glEnd();
	//window4
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(352,372);
	glVertex2f(352,367);
	glVertex2f(360,367);
	glVertex2f(360,372);
	glEnd();
	//window5
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(362,372);
	glVertex2f(362,367);
	glVertex2f(370,367);
	glVertex2f(370,372);
	glEnd();
	//window6
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(372,372);
	glVertex2f(372,367);
	glVertex2f(380,367);
	glVertex2f(380,372);
	glEnd();
	//window7
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(382,372);
	glVertex2f(382,367);
	glVertex2f(390,367);
	glVertex2f(390,372);
	glEnd();
	//window8
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(392,372);
	glVertex2f(392,367);
	glVertex2f(396,367);
	glVertex2f(396,372);
	glEnd();
///boggy2
	glBegin(GL_QUADS);
	glColor3ub(153, 255, 255);
	glVertex2f(400,375);
	glVertex2f(400,360);
	glVertex2f(478,360);
	glVertex2f(478,375);
	glEnd();
	//window1
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(402,372);
	glVertex2f(402,367);
	glVertex2f(410,367);
	glVertex2f(410,372);
	glEnd();
	//window2
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(412,372);
	glVertex2f(412,367);
	glVertex2f(420,367);
	glVertex2f(420,372);
	glEnd();
	//window3
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(422,372);
	glVertex2f(422,367);
	glVertex2f(430,367);
	glVertex2f(430,372);
	glEnd();
	//window4
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(432,372);
	glVertex2f(432,367);
	glVertex2f(440,367);
	glVertex2f(440,372);
	glEnd();
	//window5
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(442,372);
	glVertex2f(442,367);
	glVertex2f(450,367);
	glVertex2f(450,372);
	glEnd();
    //window6
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(452,372);
	glVertex2f(452,367);
	glVertex2f(460,367);
	glVertex2f(460,372);
	glEnd();
	//window7
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(462,372);
	glVertex2f(462,367);
	glVertex2f(470,367);
	glVertex2f(470,372);
	glEnd();
	//window8
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(472,372);
	glVertex2f(472,367);
	glVertex2f(476,367);
	glVertex2f(476,372);
	glEnd();
///boggy3
	glBegin(GL_QUADS);
	glColor3ub(204, 153, 255);
	glVertex2f(480,375);
	glVertex2f(480,360);
	glVertex2f(558,360);
	glVertex2f(558,375);
	glEnd();
	//window1
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(482,372);
	glVertex2f(482,367);
	glVertex2f(486,367);
	glVertex2f(486,372);
	glEnd();
	//window2
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(488,372);
	glVertex2f(488,367);
	glVertex2f(496,367);
	glVertex2f(496,372);
	glEnd();
	//window3
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(498,372);
	glVertex2f(498,367);
	glVertex2f(506,367);
	glVertex2f(506,372);
	glEnd();
	//window4
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(508,372);
	glVertex2f(508,367);
	glVertex2f(516,367);
	glVertex2f(516,372);
	glEnd();
	//window5
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(518,372);
	glVertex2f(518,367);
	glVertex2f(526,367);
	glVertex2f(526,372);
	glEnd();
	//window6
	glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
	glVertex2f(528,372);
	glVertex2f(528,367);
	glVertex2f(536,367);
	glVertex2f(536,372);
	glEnd();
	//window7
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(538,372);
	glVertex2f(538,367);
	glVertex2f(546,367);
	glVertex2f(546,372);
	glEnd();
	//window8
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(548,372);
	glVertex2f(548,367);
	glVertex2f(556,367);
	glVertex2f(556,372);
	glEnd();
///boggy4
	glBegin(GL_QUADS);
	glColor3ub(153, 255, 255);
	glVertex2f(560,375);
	glVertex2f(560,360);
	glVertex2f(638,360);
	glVertex2f(638,375);
	glEnd();
	//window1
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(562,372);
	glVertex2f(562,367);
	glVertex2f(570,367);
	glVertex2f(570,372);
	glEnd();
	//window2
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(572,372);
	glVertex2f(572,367);
	glVertex2f(580,367);
	glVertex2f(580,372);
	glEnd();
	//window3
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(582,372);
	glVertex2f(582,367);
	glVertex2f(590,367);
	glVertex2f(590,372);
	glEnd();
	//window4
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(592,372);
	glVertex2f(592,367);
	glVertex2f(600,367);
	glVertex2f(600,372);
	glEnd();
	//window5
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(602,372);
	glVertex2f(602,367);
	glVertex2f(610,367);
	glVertex2f(610,372);
	glEnd();
	//window6
	glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
	glVertex2f(612,372);
	glVertex2f(612,367);
	glVertex2f(620,367);
	glVertex2f(620,372);
	glEnd();
	//window7
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(622,372);
	glVertex2f(622,367);
	glVertex2f(630,367);
	glVertex2f(630,372);
	glEnd();
	//window8
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(632,372);
	glVertex2f(632,367);
	glVertex2f(636,367);
	glVertex2f(636,372);
	glEnd();
	///boggy5
	glBegin(GL_QUADS);
	glColor3ub(204, 153, 255);
	glVertex2f(640,375);
	glVertex2f(640,360);
	glVertex2f(720,360);
	glVertex2f(720,375);
	glEnd();
	//window1
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(642,372);
	glVertex2f(642,367);
	glVertex2f(648,367);
	glVertex2f(648,372);
	glEnd();
	//window2
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(650,372);
	glVertex2f(650,367);
	glVertex2f(658,367);
	glVertex2f(658,372);
	glEnd();
	//window3
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(660,372);
	glVertex2f(660,367);
	glVertex2f(668,367);
	glVertex2f(668,372);
	glEnd();
	//window4
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(670,372);
	glVertex2f(670,367);
	glVertex2f(678,367);
	glVertex2f(678,372);
	glEnd();
	//window5
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(680,372);
	glVertex2f(680,367);
	glVertex2f(688,367);
	glVertex2f(688,372);
	glEnd();
	//window6
	glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
	glVertex2f(690,372);
	glVertex2f(690,367);
	glVertex2f(698,367);
	glVertex2f(698,372);
	glEnd();
	//window7
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(700,372);
	glVertex2f(700,367);
	glVertex2f(708,367);
	glVertex2f(708,372);
	glEnd();
	//window8
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(710,372);
	glVertex2f(710,367);
	glVertex2f(718,367);
	glVertex2f(718,372);
	glEnd();
glPopMatrix();
	///

	//valley2
	glBegin(GL_TRIANGLES);
	glColor3ub(60, 98, 40);
	glVertex2f(490,360);
	glVertex2f(560,360);
	glVertex2f(525,390);
	glEnd();

///TRAIN LINE 2
    //SIDEPATH UNDER
    glBegin(GL_LINES);
	glColor3ub(0, 0, 0);
	glVertex2f(0,357);
	glVertex2f(640,357);
	glEnd();
    //SIDEPATH TOP
    glBegin(GL_LINES);
	glVertex2f(0,360);
	glVertex2f(550,360);
	glEnd();
	//INSIDE STEP 1
    glBegin(GL_LINES);
	glVertex2f(380,357);
	glVertex2f(382,360);
	glEnd();
	//INSIDE STEP 2
    glBegin(GL_LINES);
	glVertex2f(382,357);
	glVertex2f(384,360);
	glEnd();
	//INSIDE STEP 3
    glBegin(GL_LINES);
	glVertex2f(388,357);
	glVertex2f(390,360);
	glEnd();
	//INSIDE STEP 4
    glBegin(GL_LINES);
	glVertex2f(390,357);
	glVertex2f(392,360);
	glEnd();
	//INSIDE STEP 5
    glBegin(GL_LINES);
	glVertex2f(398,357);
	glVertex2f(400,360);
	glEnd();
	//INSIDE STEP 6
    glBegin(GL_LINES);
	glVertex2f(400,357);
	glVertex2f(402,360);
	glEnd();
	//INSIDE STEP 7
    glBegin(GL_LINES);
	glVertex2f(408,357);
	glVertex2f(410,360);
	glEnd();
	//INSIDE STEP 8
    glBegin(GL_LINES);
	glVertex2f(410,357);
	glVertex2f(412,360);
	glEnd();
	//INSIDE STEP 9
    glBegin(GL_LINES);
	glVertex2f(418,357);
	glVertex2f(420,360);
	glEnd();
	//INSIDE STEP 10
    glBegin(GL_LINES);
	glVertex2f(420,357);
	glVertex2f(422,360);
	glEnd();
	//INSIDE STEP 11
    glBegin(GL_LINES);
	glVertex2f(428,357);
	glVertex2f(430,360);
	glEnd();
	//INSIDE STEP 12
    glBegin(GL_LINES);
	glVertex2f(430,357);
	glVertex2f(432,360);
	glEnd();
	//INSIDE STEP 13
    glBegin(GL_LINES);
	glVertex2f(438,357);
	glVertex2f(440,360);
	glEnd();
	//INSIDE STEP 14
    glBegin(GL_LINES);
	glVertex2f(440,357);
	glVertex2f(442,360);
	glEnd();
	//INSIDE STEP 15
    glBegin(GL_LINES);
	glVertex2f(448,357);
	glVertex2f(450,360);
	glEnd();
	//INSIDE STEP 16
    glBegin(GL_LINES);
	glVertex2f(450,357);
	glVertex2f(452,360);
	glEnd();
	//INSIDE STEP 17
    glBegin(GL_LINES);
	glVertex2f(458,357);
	glVertex2f(460,360);
	glEnd();
	//INSIDE STEP 18
    glBegin(GL_LINES);
	glVertex2f(460,357);
	glVertex2f(462,360);
	glEnd();
	//INSIDE STEP 19
    glBegin(GL_LINES);
	glVertex2f(468,357);
	glVertex2f(470,360);
	glEnd();
	//INSIDE STEP 20
    glBegin(GL_LINES);
	glVertex2f(470,357);
	glVertex2f(472,360);
	glEnd();
	//INSIDE STEP 21
    glBegin(GL_LINES);
	glVertex2f(478,357);
	glVertex2f(480,360);
	glEnd();
	//INSIDE STEP 22
    glBegin(GL_LINES);
	glVertex2f(480,357);
	glVertex2f(482,360);
	glEnd();
	//INSIDE STEP 23
    glBegin(GL_LINES);
	glVertex2f(488,357);
	glVertex2f(490,360);
	glEnd();
	//INSIDE STEP 24
    glBegin(GL_LINES);
	glVertex2f(490,357);
	glVertex2f(492,360);
	glEnd();
	//INSIDE STEP 25
    glBegin(GL_LINES);
	glVertex2f(498,357);
	glVertex2f(500,360);
	glEnd();
	//INSIDE STEP 26
    glBegin(GL_LINES);
	glVertex2f(500,357);
	glVertex2f(502,360);
	glEnd();
	//INSIDE STEP 27
    glBegin(GL_LINES);
	glVertex2f(508,357);
	glVertex2f(510,360);
	glEnd();
	//INSIDE STEP 28
    glBegin(GL_LINES);
	glVertex2f(510,357);
	glVertex2f(512,360);
	glEnd();
	//INSIDE STEP 29
    glBegin(GL_LINES);
	glVertex2f(518,357);
	glVertex2f(520,360);
	glEnd();
	//INSIDE STEP 30
    glBegin(GL_LINES);
	glVertex2f(520,357);
	glVertex2f(522,360);
	glEnd();
	//INSIDE STEP 31
    glBegin(GL_LINES);
	glVertex2f(528,357);
	glVertex2f(530,360);
	glEnd();
	//INSIDE STEP 32
    glBegin(GL_LINES);
	glVertex2f(530,357);
	glVertex2f(532,360);
	glEnd();
	//INSIDE STEP 33
    glBegin(GL_LINES);
	glVertex2f(538,357);
	glVertex2f(540,360);
	glEnd();
	//INSIDE STEP 34
    glBegin(GL_LINES);
	glVertex2f(540,357);
	glVertex2f(542,360);
	glEnd();
	//INSIDE STEP 35
    glBegin(GL_LINES);
	glVertex2f(548,357);
	glVertex2f(550,360);
	glEnd();
	//INSIDE STEP 36
    glBegin(GL_LINES);
	glVertex2f(550,357);
	glVertex2f(552,360);
	glEnd();

///TRAIN 2
glPushMatrix();
glTranslatef(trainpos2,0.0f,0.0f);
///Engine head
    glBegin(GL_TRIANGLES);
	glColor3ub(255, 51, 51);
	glVertex2f(306,375);
	glVertex2f(306,360);
	glVertex2f(288,360);
	glEnd();
///Engine body
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 51);
	glVertex2f(306,375);
	glVertex2f(306,360);
	glVertex2f(318,360);
	glVertex2f(318,375);
	glEnd();
	//window1
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(307,372);
	glVertex2f(307,367);
	glVertex2f(298,367);
	glVertex2f(304,372);
	glEnd();
	//window2
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(309,372);
	glVertex2f(309,367);
	glVertex2f(315,367);
	glVertex2f(315,372);
	glEnd();

///boggy1
	glBegin(GL_QUADS);
	glColor3ub(164, 232, 135);
	glVertex2f(320,375);
	glVertex2f(320,360);
	glVertex2f(398,360);
	glVertex2f(398,375);
	glEnd();
	//window1
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(322,372);
	glVertex2f(322,367);
	glVertex2f(330,367);
	glVertex2f(330,372);
	glEnd();
	//window2
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(332,372);
	glVertex2f(332,367);
	glVertex2f(340,367);
	glVertex2f(340,372);
	glEnd();
	//window3
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(342,372);
	glVertex2f(342,367);
	glVertex2f(350,367);
	glVertex2f(350,372);
	glEnd();
	//window4
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(352,372);
	glVertex2f(352,367);
	glVertex2f(360,367);
	glVertex2f(360,372);
	glEnd();
	//window5
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(362,372);
	glVertex2f(362,367);
	glVertex2f(370,367);
	glVertex2f(370,372);
	glEnd();
	//window6
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(372,372);
	glVertex2f(372,367);
	glVertex2f(380,367);
	glVertex2f(380,372);
	glEnd();
	//window7
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(382,372);
	glVertex2f(382,367);
	glVertex2f(390,367);
	glVertex2f(390,372);
	glEnd();
	//window8
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(392,372);
	glVertex2f(392,367);
	glVertex2f(396,367);
	glVertex2f(396,372);
	glEnd();
///boggy2
	glBegin(GL_QUADS);
	glColor3ub(236, 115, 136);
	glVertex2f(400,375);
	glVertex2f(400,360);
	glVertex2f(478,360);
	glVertex2f(478,375);
	glEnd();
	//window1
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(402,372);
	glVertex2f(402,367);
	glVertex2f(410,367);
	glVertex2f(410,372);
	glEnd();
	//window2
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(412,372);
	glVertex2f(412,367);
	glVertex2f(420,367);
	glVertex2f(420,372);
	glEnd();
	//window3
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(422,372);
	glVertex2f(422,367);
	glVertex2f(430,367);
	glVertex2f(430,372);
	glEnd();
	//window4
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(432,372);
	glVertex2f(432,367);
	glVertex2f(440,367);
	glVertex2f(440,372);
	glEnd();
	//window5
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(442,372);
	glVertex2f(442,367);
	glVertex2f(450,367);
	glVertex2f(450,372);
	glEnd();
    //window6
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(452,372);
	glVertex2f(452,367);
	glVertex2f(460,367);
	glVertex2f(460,372);
	glEnd();
	//window7
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(462,372);
	glVertex2f(462,367);
	glVertex2f(470,367);
	glVertex2f(470,372);
	glEnd();
	//window8
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(472,372);
	glVertex2f(472,367);
	glVertex2f(476,367);
	glVertex2f(476,372);
	glEnd();
///boggy3
	glBegin(GL_QUADS);
	glColor3ub(164, 232, 135);
	glVertex2f(480,375);
	glVertex2f(480,360);
	glVertex2f(558,360);
	glVertex2f(558,375);
	glEnd();
	//window1
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(482,372);
	glVertex2f(482,367);
	glVertex2f(486,367);
	glVertex2f(486,372);
	glEnd();
	//window2
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(488,372);
	glVertex2f(488,367);
	glVertex2f(496,367);
	glVertex2f(496,372);
	glEnd();
	//window3
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(498,372);
	glVertex2f(498,367);
	glVertex2f(506,367);
	glVertex2f(506,372);
	glEnd();
	//window4
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(508,372);
	glVertex2f(508,367);
	glVertex2f(516,367);
	glVertex2f(516,372);
	glEnd();
	//window5
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(518,372);
	glVertex2f(518,367);
	glVertex2f(526,367);
	glVertex2f(526,372);
	glEnd();
	//window6
	glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
	glVertex2f(528,372);
	glVertex2f(528,367);
	glVertex2f(536,367);
	glVertex2f(536,372);
	glEnd();
	//window7
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(538,372);
	glVertex2f(538,367);
	glVertex2f(546,367);
	glVertex2f(546,372);
	glEnd();
	//window8
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(548,372);
	glVertex2f(548,367);
	glVertex2f(556,367);
	glVertex2f(556,372);
	glEnd();
///boggy4
	glBegin(GL_QUADS);
	glColor3ub(236, 115, 136);
	glVertex2f(560,375);
	glVertex2f(560,360);
	glVertex2f(638,360);
	glVertex2f(638,375);
	glEnd();
	//window1
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(562,372);
	glVertex2f(562,367);
	glVertex2f(570,367);
	glVertex2f(570,372);
	glEnd();
	//window2
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(572,372);
	glVertex2f(572,367);
	glVertex2f(580,367);
	glVertex2f(580,372);
	glEnd();
	//window3
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(582,372);
	glVertex2f(582,367);
	glVertex2f(590,367);
	glVertex2f(590,372);
	glEnd();
	//window4
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(592,372);
	glVertex2f(592,367);
	glVertex2f(600,367);
	glVertex2f(600,372);
	glEnd();
	//window5
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(602,372);
	glVertex2f(602,367);
	glVertex2f(610,367);
	glVertex2f(610,372);
	glEnd();
	//window6
	glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
	glVertex2f(612,372);
	glVertex2f(612,367);
	glVertex2f(620,367);
	glVertex2f(620,372);
	glEnd();
	//window7
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(622,372);
	glVertex2f(622,367);
	glVertex2f(630,367);
	glVertex2f(630,372);
	glEnd();
	//window8
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(632,372);
	glVertex2f(632,367);
	glVertex2f(636,367);
	glVertex2f(636,372);
	glEnd();
	///boggy5
	glBegin(GL_QUADS);
	glColor3ub(164, 232, 135);
	glVertex2f(640,375);
	glVertex2f(640,360);
	glVertex2f(720,360);
	glVertex2f(720,375);
	glEnd();
	//window1
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(642,372);
	glVertex2f(642,367);
	glVertex2f(648,367);
	glVertex2f(648,372);
	glEnd();
	//window2
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(650,372);
	glVertex2f(650,367);
	glVertex2f(658,367);
	glVertex2f(658,372);
	glEnd();
	//window3
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(660,372);
	glVertex2f(660,367);
	glVertex2f(668,367);
	glVertex2f(668,372);
	glEnd();
	//window4
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(670,372);
	glVertex2f(670,367);
	glVertex2f(678,367);
	glVertex2f(678,372);
	glEnd();
	//window5
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(680,372);
	glVertex2f(680,367);
	glVertex2f(688,367);
	glVertex2f(688,372);
	glEnd();
	//window6
	glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
	glVertex2f(690,372);
	glVertex2f(690,367);
	glVertex2f(698,367);
	glVertex2f(698,372);
	glEnd();
	//window7
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(700,372);
	glVertex2f(700,367);
	glVertex2f(708,367);
	glVertex2f(708,372);
	glEnd();
	//window8
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(710,372);
	glVertex2f(710,367);
	glVertex2f(718,367);
	glVertex2f(718,372);
	glEnd();
glPopMatrix();
	///

	//valley3
	glBegin(GL_TRIANGLES);
	glColor3ub(59, 78, 61);
	glVertex2f(550,357);
	glVertex2f(650,357);
	glVertex2f(600,400);
	glEnd();


///home2
    glBegin(GL_QUADS);
    glColor3ub(255, 102, 102);
	glVertex2f(40,350);
	glVertex2f(40,475);
	glVertex2f(120,475);
	glVertex2f(120,350);
	glEnd();
	//sideview
    glBegin(GL_QUADS);
	glColor3ub(255, 153, 153);
	glVertex2f(120,475);
	glVertex2f(120,350);
	glVertex2f(130,350);
	glVertex2f(130,460);
	glEnd();
	//window1
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(50,470);
	glVertex2f(50,450);
	glVertex2f(70,450);
	glVertex2f(70,470);
	glEnd();
    //window2
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(90,470);
	glVertex2f(90,450);
	glVertex2f(110,450);
	glVertex2f(110,470);
	glEnd();
	//window3
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(50,440);
	glVertex2f(50,420);
	glVertex2f(70,420);
	glVertex2f(70,440);
	glEnd();
    //window4
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(90,440);
	glVertex2f(90,420);
	glVertex2f(110,420);
	glVertex2f(110,440);
	glEnd();
    //window5
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(50,410);
	glVertex2f(50,390);
	glVertex2f(70,390);
	glVertex2f(70,410);
	glEnd();
    //window6
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(90,410);
	glVertex2f(90,390);
	glVertex2f(110,390);
	glVertex2f(110,410);
	glEnd();
     //window7
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(50,380);
	glVertex2f(50,360);
	glVertex2f(70,360);
	glVertex2f(70,380);
	glEnd();
    //window8
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(90,380);
	glVertex2f(90,360);
	glVertex2f(110,360);
	glVertex2f(110,380);
	glEnd();

///home1
    glBegin(GL_QUADS);
	glColor3ub(233, 169, 132);
	glVertex2f(0,350);
	glVertex2f(0,460);
	glVertex2f(50,460);
	glVertex2f(50,350);
	glEnd();
	//window1
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(0,450);
	glVertex2f(0,425);
	glVertex2f(10,425);
	glVertex2f(10,450);
	glEnd();
	//window2
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(20,450);
	glVertex2f(20,425);
	glVertex2f(40,425);
	glVertex2f(40,450);
	glEnd();
	//window3
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(0,415);
	glVertex2f(0,390);
	glVertex2f(10,390);
	glVertex2f(10,415);
	glEnd();
	//window4
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(20,415);
	glVertex2f(20,390);
	glVertex2f(40,390);
	glVertex2f(40,415);
	glEnd();
    //window5
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(0,380);
	glVertex2f(0,355);
	glVertex2f(10,355);
	glVertex2f(10,380);
	glEnd();
	//window6
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(20,380);
	glVertex2f(20,355);
	glVertex2f(40,355);
	glVertex2f(40,380);
	glEnd();

///home4
    glBegin(GL_QUADS);
	glColor3ub(228, 174, 27);
	glVertex2f(210,350);
	glVertex2f(210,450);
	glVertex2f(290,450);
	glVertex2f(290,350);
	glEnd();
	//sideview
    glBegin(GL_QUADS);
	glColor3ub(195, 145, 4);
	glVertex2f(290,350);
	glVertex2f(290,450);
	glVertex2f(300,430);
	glVertex2f(300,350);
	glEnd();
	//window1
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(220,440);
	glVertex2f(220,425);
	glVertex2f(240,425);
	glVertex2f(240,440);
	glEnd();
	//window2
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(260,440);
	glVertex2f(260,425);
	glVertex2f(280,425);
	glVertex2f(280,440);
	glEnd();
	//window3
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(220,410);
	glVertex2f(220,395);
	glVertex2f(240,395);
	glVertex2f(240,410);
	glEnd();
	//window4
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(260,410);
	glVertex2f(260,395);
	glVertex2f(280,395);
	glVertex2f(280,410);
	glEnd();
    //window5
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(220,380);
	glVertex2f(220,365);
	glVertex2f(240,365);
	glVertex2f(240,380);
	glEnd();
	//window6
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(260,380);
	glVertex2f(260,365);
	glVertex2f(280,365);
	glVertex2f(280,380);
	glEnd();


///home3
    glBegin(GL_QUADS);
	glColor3ub(204, 153, 255);
	glVertex2f(130,350);
	glVertex2f(130,470);
	glVertex2f(210,470);
	glVertex2f(210,350);
	glEnd();
	//window1
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(140,465);
	glVertex2f(140,445);
	glVertex2f(160,445);
	glVertex2f(160,465);
	glEnd();
    //window2
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(180,465);
	glVertex2f(180,445);
	glVertex2f(200,445);
	glVertex2f(200,465);
	glEnd();
	//window3
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(140,435);
	glVertex2f(140,415);
	glVertex2f(160,415);
	glVertex2f(160,435);
	glEnd();
    //window4
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(180,435);
	glVertex2f(180,415);
	glVertex2f(200,415);
	glVertex2f(200,435);
	glEnd();
    //window5
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(140,405);
	glVertex2f(140,385);
	glVertex2f(160,385);
	glVertex2f(160,405);
	glEnd();
    //window6
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(180,405);
	glVertex2f(180,385);
	glVertex2f(200,385);
	glVertex2f(200,405);
	glEnd();
     //window7
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(140,375);
	glVertex2f(140,355);
	glVertex2f(160,355);
	glVertex2f(160,375);
	glEnd();
    //window8
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(180,375);
	glVertex2f(180,355);
	glVertex2f(200,355);
	glVertex2f(200,375);
	glEnd();

///home5
    glBegin(GL_QUADS);
	glColor3ub(156, 103, 112);
	glVertex2f(300,350);
	glVertex2f(300,450);
	glVertex2f(380.,450);
	glVertex2f(380,350);
	glEnd();
    //window1
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(310,440);
	glVertex2f(310,425);
	glVertex2f(330,425);
	glVertex2f(330,440);
	glEnd();
	//window2
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(370,440);
	glVertex2f(370,425);
	glVertex2f(350,425);
	glVertex2f(350,440);
	glEnd();
	//window3
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(310,410);
	glVertex2f(310,395);
	glVertex2f(330,395);
	glVertex2f(330,410);
	glEnd();
	//window4
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(350,410);
	glVertex2f(350,395);
	glVertex2f(370,395);
	glVertex2f(370,410);
	glEnd();
    //window5
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(310,380);
	glVertex2f(310,365);
	glVertex2f(330,365);
	glVertex2f(330,380);
	glEnd();
	//window6
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex2f(350,380);
	glVertex2f(350,365);
	glVertex2f(370,365);
	glVertex2f(370,380);
	glEnd();


///SIGNBOARD HOSPITAL
glBegin(GL_QUADS);
glColor3ub(255,0,0);
glVertex2i(215,452);
glVertex2i(215,475);
glVertex2i(285,475);
glVertex2i(285,452);
glEnd();
///TEXT HOSPITAL
glColor3ub(255, 255, 255);
renderBitmapString(215,460,(void *)font1,"HOSPITAL");

///CIRCLE OF HOSPITAL
 x1=276;  y1=464;  radius1 =8.0f;
 triangleAmount = 100; //# of triangles used to draw circle
 twicePi = 2.0f * PI;
glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255);
    glVertex2f(x1, y1); // center of circle
    for(i1 = 0; i1 <= triangleAmount;i1++) {
        glVertex2f(
                x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
            y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
        );
    }
glEnd();

///PLUS SIGN
glLineWidth(10);
glBegin(GL_LINES);
glColor3ub(255,0,0);
glVertex2i(276,458);
glVertex2i(276,470);
glEnd();
glLineWidth(10);
glBegin(GL_LINES);
glColor3ub(255,0,0);
glVertex2i(270,464);
glVertex2i(282,464);
glEnd();


// end of text


///ground top of river topline
    glLineWidth(2);
    glBegin(GL_LINES);
	glColor3ub(255, 255, 0);
	glVertex2f(0,350);
	glVertex2f(640,350);
	glEnd();

///ARC SMALL 1
glPushMatrix();
glTranslatef(smallarcpos1, 50.0f, 0.0f);
//MAIN
    glBegin(GL_QUADS);
    glColor3f(0, 0,0);
    glVertex2i(340,280);
    glVertex2i(360,260);
    glVertex2i(420,260);
    glVertex2i(440,280);
    glEnd();
    //SHADE
    glBegin(GL_QUADS);
    glColor3f(0, 255,0);
    glVertex2i(350,280);
    glVertex2i(350,295);
    glVertex2i(400,295);
    glVertex2i(420,280);
    glEnd();

    //window front
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(398,292);
	glVertex2f(398,287);
	glVertex2f(407,287);
	glVertex2f(401,292);
	glEnd();

    //window1
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(396,292);
	glVertex2f(396,287);
	glVertex2f(385,287);
	glVertex2f(385,292);
	glEnd();

    //window2
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(383,292);
	glVertex2f(383,287);
	glVertex2f(372,287);
	glVertex2f(372,292);
	glEnd();

    //window3
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2f(370,292);
	glVertex2f(370,287);
	glVertex2f(359,287);
	glVertex2f(359,292);
	glEnd();
glPopMatrix();

///ARC SMALL 2
glPushMatrix();
glTranslatef(smallarcpos2, 30.0f, 0.0f);
//MAIN
    glBegin(GL_QUADS);
    glColor3f(0, 0,0);
    glVertex2i(340,280);
    glVertex2i(360,260);
    glVertex2i(420,260);
    glVertex2i(440,280);
    glEnd();
    //SHADE
    glBegin(GL_QUADS);
    glColor3f(255, 128,0);
    glVertex2i(400,280);
    glVertex2i(400,300);
    glVertex2i(400,300);
    glVertex2i(420,280);
    glEnd();
glPopMatrix();


///ARC BIG
glPushMatrix();
glTranslatef(arcPos, 0.0f, 0.0f);

//MAIN
glBegin(GL_QUADS);
glColor3f(0, 0,0);
glVertex2i(260,290);
glVertex2i(300,270);
glVertex2i(420,270);
glVertex2i(460,290);
glEnd();
//1st FLOOR
    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(400,310);
    glVertex2i(400,290);
    glVertex2i(440,290);
    glVertex2i(440,310);
    glEnd();
    //window1
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
    glVertex2i(405,295);
    glVertex2i(405,305);
    glVertex2i(415,305);
    glVertex2i(415,295);
	glEnd();
    //window2
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
    glVertex2i(425,295);
    glVertex2i(425,305);
    glVertex2i(435,305);
    glVertex2i(435,295);
	glEnd();
//2nd FLOOR
    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(405,310);
    glVertex2i(405,320);
    glVertex2i(435,320);
    glVertex2i(435,310);
    glEnd();
    //window1
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
    glVertex2i(407,312);
    glVertex2i(407,318);
    glVertex2i(418,318);
    glVertex2i(418,312);
	glEnd();
    //window2
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
    glVertex2i(422,312);
    glVertex2i(422,318);
    glVertex2i(433,318);
    glVertex2i(433,312);
	glEnd();
//3rd FLOOR
    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(420,320);
    glVertex2i(420,335);
    glVertex2i(430,335);
    glVertex2i(430,320);
    glEnd();
//FLAG STAND
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(280,290);
    glVertex2f(280,320);
    glEnd();
//FLAG OUTER
    glBegin(GL_QUADS);
    glColor3f(0,255,0);
    glVertex2i(280,310);
    glVertex2i(280,320);
    glVertex2i(290,320);
    glVertex2i(290,310);
    glEnd();
//FLAG INNER CIRCLE
    x1=285;  y1=315;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
    //FLOOR1
	//CONTAINER 1
    glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
    glVertex2i(310,290);
    glVertex2i(310,300);
    glVertex2i(325,300);
    glVertex2i(325,290);
	glEnd();
	//CONTAINER 2
    glBegin(GL_QUADS);
	glColor3ub(0, 255, 0);
    glVertex2i(325,290);
    glVertex2i(325,300);
    glVertex2i(340,300);
    glVertex2i(340,290);
	glEnd();
	//CONTAINER 3
    glBegin(GL_QUADS);
	glColor3ub(225, 0, 0);
    glVertex2i(340,290);
    glVertex2i(340,300);
    glVertex2i(355,300);
    glVertex2i(355,290);
	glEnd();
	//CONTAINER 4
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 255);
    glVertex2i(355,290);
    glVertex2i(355,300);
    glVertex2i(370,300);
    glVertex2i(370,290);
	glEnd();
	//CONTAINER 5
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 0);
    glVertex2i(370,290);
    glVertex2i(370,300);
    glVertex2i(385,300);
    glVertex2i(385,290);
	glEnd();

	//FLOOR2
	//CONTAINER 1
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 0);
    glVertex2i(317,300);
    glVertex2i(317,310);
    glVertex2i(332,310);
    glVertex2i(332,300);
	glEnd();
	//CONTAINER 2
    glBegin(GL_QUADS);
	glColor3ub(0, 0, 255);
    glVertex2i(332,300);
    glVertex2i(332,310);
    glVertex2i(347,310);
    glVertex2i(347,300);
	glEnd();
	//CONTAINER 3
    glBegin(GL_QUADS);
	glColor3ub(0, 255, 0);
    glVertex2i(347,300);
    glVertex2i(347,310);
    glVertex2i(362,310);
    glVertex2i(362,300);
	glEnd();
	//CONTAINER 4
    glBegin(GL_QUADS);
	glColor3ub(255,0, 0);
    glVertex2i(362,300);
    glVertex2i(362,310);
    glVertex2i(377,310);
    glVertex2i(377,300);
	glEnd();
glPopMatrix();


///BRIDGE
//fence1
glBegin(GL_QUADS);
glColor3f(255,0,0);
glVertex2i(0,220);
glVertex2i(0,215);
glVertex2i(640,215);
glVertex2i(640,220);
glEnd();
//fence2
glBegin(GL_QUADS);
glColor3f(255,0,0);
glVertex2i(0,230);
glVertex2i(0,225);
glVertex2i(640,225);
glVertex2i(640,230);
glEnd();
//fence3
glBegin(GL_QUADS);
glColor3f(255,0,0);
glVertex2i(0,235);
glVertex2i(0,240);
glVertex2i(640,240);
glVertex2i(640,235);
glEnd();
///RALLING
//RALLING STICK 1
glBegin(GL_QUADS);
glColor3f(255,255,255);
glVertex2i(5,250);
glVertex2i(5,210);
glVertex2i(15,210);
glVertex2i(15,250);
glEnd();
//RALLING STICK 2
glBegin(GL_QUADS);
glVertex2i(25,250);
glVertex2i(25,210);
glVertex2i(35,210);
glVertex2i(35,250);
glEnd();
//RALLING STICK 3
glBegin(GL_QUADS);
glVertex2i(45,250);
glVertex2i(45,210);
glVertex2i(55,210);
glVertex2i(55,250);
glEnd();
//RALLING STICK 4
glBegin(GL_QUADS);
glVertex2i(65,250);
glVertex2i(65,210);
glVertex2i(75,210);
glVertex2i(75,250);
glEnd();
//RALLING STICK 5
glBegin(GL_QUADS);
glVertex2i(85,250);
glVertex2i(85,210);
glVertex2i(95,210);
glVertex2i(95,250);
glEnd();
//RALLING STICK 6
glBegin(GL_QUADS);
glVertex2i(105,250);
glVertex2i(105,210);
glVertex2i(115,210);
glVertex2i(115,250);
glEnd();
//RALLING STICK 7
glBegin(GL_QUADS);
glVertex2i(125,250);
glVertex2i(125,210);
glVertex2i(135,210);
glVertex2i(135,250);
glEnd();
//RALLING STICK 8
glBegin(GL_QUADS);
glVertex2i(145,250);
glVertex2i(145,210);
glVertex2i(155,210);
glVertex2i(155,250);
glEnd();
//RALLING STICK 9
glBegin(GL_QUADS);
glVertex2i(165,250);
glVertex2i(165,210);
glVertex2i(175,210);
glVertex2i(175,250);
glEnd();
//RALLING STICK 10
glBegin(GL_QUADS);
glVertex2i(185,250);
glVertex2i(185,210);
glVertex2i(195,210);
glVertex2i(195,250);
glEnd();
//RALLING STICK 11
glBegin(GL_QUADS);
glVertex2i(205,250);
glVertex2i(205,210);
glVertex2i(215,210);
glVertex2i(215,250);
glEnd();
//RALLING STICK 12
glBegin(GL_QUADS);
glVertex2i(225,250);
glVertex2i(225,210);
glVertex2i(235,210);
glVertex2i(235,250);
glEnd();
//RALLING STICK 13
glBegin(GL_QUADS);
glVertex2i(245,250);
glVertex2i(245,210);
glVertex2i(255,210);
glVertex2i(255,250);
glEnd();
//RALLING STICK 14
glBegin(GL_QUADS);
glVertex2i(265,250);
glVertex2i(265,210);
glVertex2i(275,210);
glVertex2i(275,250);
glEnd();
//RALLING STICK 15
glBegin(GL_QUADS);
glVertex2i(285,250);
glVertex2i(285,210);
glVertex2i(295,210);
glVertex2i(295,250);
glEnd();
//RALLING STICK 16
glBegin(GL_QUADS);
glVertex2i(305,250);
glVertex2i(305,210);
glVertex2i(315,210);
glVertex2i(315,250);
glEnd();
//RALLING STICK 17
glBegin(GL_QUADS);
glVertex2i(325,250);
glVertex2i(325,210);
glVertex2i(335,210);
glVertex2i(335,250);
glEnd();
//RALLING STICK 18
glBegin(GL_QUADS);
glVertex2i(345,250);
glVertex2i(345,210);
glVertex2i(355,210);
glVertex2i(355,250);
glEnd();
//RALLING STICK 19
glBegin(GL_QUADS);
glVertex2i(365,250);
glVertex2i(365,210);
glVertex2i(375,210);
glVertex2i(375,250);
glEnd();
//RALLING STICK 20
glBegin(GL_QUADS);
glVertex2i(385,250);
glVertex2i(385,210);
glVertex2i(395,210);
glVertex2i(395,250);
glEnd();
//RALLING STICK 21
glBegin(GL_QUADS);
glVertex2i(405,250);
glVertex2i(405,210);
glVertex2i(415,210);
glVertex2i(415,250);
glEnd();
//RALLING STICK 22
glBegin(GL_QUADS);
glVertex2i(425,250);
glVertex2i(425,210);
glVertex2i(435,210);
glVertex2i(435,250);
glEnd();
//RALLING STICK 23
glBegin(GL_QUADS);
glVertex2i(445,250);
glVertex2i(445,210);
glVertex2i(455,210);
glVertex2i(455,250);
glEnd();
//RALLING STICK 24
glBegin(GL_QUADS);
glVertex2i(465,250);
glVertex2i(465,210);
glVertex2i(475,210);
glVertex2i(475,250);
glEnd();
//RALLING STICK 25
glBegin(GL_QUADS);
glVertex2i(485,250);
glVertex2i(485,210);
glVertex2i(495,210);
glVertex2i(495,250);
glEnd();
//RALLING STICK 26
glBegin(GL_QUADS);
glVertex2i(505,250);
glVertex2i(505,210);
glVertex2i(515,210);
glVertex2i(515,250);
glEnd();
//RALLING STICK 27
glBegin(GL_QUADS);
glVertex2i(525,250);
glVertex2i(525,210);
glVertex2i(535,210);
glVertex2i(535,250);
glEnd();
//RALLING STICK 28
glBegin(GL_QUADS);
glVertex2i(545,250);
glVertex2i(545,210);
glVertex2i(555,210);
glVertex2i(555,250);
glEnd();
//RALLING STICK 29
glBegin(GL_QUADS);
glVertex2i(565,250);
glVertex2i(565,210);
glVertex2i(575,210);
glVertex2i(575,250);
glEnd();
//RALLING STICK 30
glBegin(GL_QUADS);
glVertex2i(585,250);
glVertex2i(585,210);
glVertex2i(595,210);
glVertex2i(595,250);
glEnd();
//RALLING STICK 31
glBegin(GL_QUADS);
glVertex2i(605,250);
glVertex2i(605,210);
glVertex2i(615,210);
glVertex2i(615,250);
glEnd();
//RALLING STICK 32
glBegin(GL_QUADS);
glVertex2i(625,250);
glVertex2i(625,210);
glVertex2i(635,210);
glVertex2i(635,250);
glEnd();
///

///SMOKE 1
glPushMatrix();
glTranslatef(arcPos+60 ,smokepos1 ,0.0f);
//smoke ball 1
    x1=370;  y1=345; radius1 =5.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

//smoke ball 2
    x1=375;  y1=348; radius1 =5.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

//smoke ball 3
    x1=380;  y1=358; radius1 =10.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

glPopMatrix();

///SMOKE 2
glPushMatrix();
glTranslatef(arcPos+60 ,smokepos2 ,0.0f);
//smoke ball 1
    x1=370;  y1=345; radius1 =5.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

//smoke ball 2
    x1=375;  y1=348; radius1 =5.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

//smoke ball 3
    x1=380;  y1=358; radius1 =10.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

glPopMatrix();

///SMOKE 3
glPushMatrix();
glTranslatef(arcPos+60 ,smokepos3 ,0.0f);
//smoke ball 1
    x1=370;  y1=345; radius1 =5.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

//smoke ball 2
    x1=375;  y1=348; radius1 =5.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

//smoke ball 3
    x1=380;  y1=358; radius1 =10.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

glPopMatrix();

///SMOKE 4
glPushMatrix();
glTranslatef(arcPos+60 ,smokepos4 ,0.0f);
//smoke ball 1
    x1=370;  y1=345; radius1 =5.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

//smoke ball 2
    x1=375;  y1=348; radius1 =5.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

//smoke ball 3
    x1=380;  y1=358; radius1 =10.0f;
    triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(224, 224, 224);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

glPopMatrix();


///LAMPPOST 1
    //STEP 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(85,160);
    glVertex2i(85,165);
    glVertex2i(115,165);
    glVertex2i(115,160);
    glEnd();
    //STEP 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(90,165);
    glVertex2i(90,170);
    glVertex2i(110,170);
    glVertex2i(110,165);
    glEnd();
    //STAND
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(98,165);
    glVertex2i(98,280);
    glVertex2i(102,280);
    glVertex2i(102,165);
    glEnd();
    //STEP 3
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(90,280);
    glVertex2i(90,285);
    glVertex2i(110,285);
    glVertex2i(110,280);
    glEnd();
    //LIGHT QUADS OUTER
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(92,285);
    glVertex2i(85,315);
    glVertex2i(115,315);
    glVertex2i(108,285);
    glEnd();
    //LIGHT QUADS INNER1
    glBegin(GL_QUADS);
    glColor3f(255,255,0);
    glVertex2i(94,285);
    glVertex2i(88,315);
    glVertex2i(112,315);
    glVertex2i(106,285);
    glEnd();
    //LIGHT QUADS INNER2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(96,285);
    glVertex2i(91,315);
    glVertex2i(109,315);
    glVertex2i(104,285);
    glEnd();
     //LIGHT QUADS INNER3
    glBegin(GL_QUADS);
    glColor3f(255,255,5);
    glVertex2i(98,285);
    glVertex2i(94,315);
    glVertex2i(106,315);
    glVertex2i(102,285);
    glEnd();
     //LIGHT TRIANGLE OUTER
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    glVertex2i(85,315);
    glVertex2i(115,315);
    glVertex2i(100,340);
    glEnd();
     //LIGHT TRIANGLE INNER 1
    glBegin(GL_TRIANGLES);
    glColor3f(255,255,0);
    glVertex2i(89,317);
    glVertex2i(111,317);
    glVertex2i(100,336);
    glEnd();
     //LIGHT TRIANGLE INNER 2
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    glVertex2i(92,317);
    glVertex2i(108,317);
    glVertex2i(100,336);
    glEnd();
    //LIGHT TRIANGLE INNER 3
    glBegin(GL_TRIANGLES);
    glColor3f(255,255,255);
    glVertex2i(95,317);
    glVertex2i(105,317);
    glVertex2i(100,333);
    glEnd();
    //LIGHT OUTER CIRCLE
     x1=100;  y1=342;  radius1 =5.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	//LIGHT INNER CIRCLE
     x1=100;  y1=342;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
///

///LAMPPOST 2
glPushMatrix();
glTranslatef(500.0f,0.0f,0.0f);
    //STEP 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(85,160);
    glVertex2i(85,165);
    glVertex2i(115,165);
    glVertex2i(115,160);
    glEnd();
    //STEP 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(90,165);
    glVertex2i(90,170);
    glVertex2i(110,170);
    glVertex2i(110,165);
    glEnd();
    //STAND
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(98,165);
    glVertex2i(98,280);
    glVertex2i(102,280);
    glVertex2i(102,165);
    glEnd();
    //STEP 3
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(90,280);
    glVertex2i(90,285);
    glVertex2i(110,285);
    glVertex2i(110,280);
    glEnd();
    //LIGHT QUADS OUTER
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(92,285);
    glVertex2i(85,315);
    glVertex2i(115,315);
    glVertex2i(108,285);
    glEnd();
    //LIGHT QUADS INNER1
    glBegin(GL_QUADS);
    glColor3f(255,255,0);
    glVertex2i(94,285);
    glVertex2i(88,315);
    glVertex2i(112,315);
    glVertex2i(106,285);
    glEnd();
    //LIGHT QUADS INNER2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(96,285);
    glVertex2i(91,315);
    glVertex2i(109,315);
    glVertex2i(104,285);
    glEnd();
     //LIGHT QUADS INNER3
    glBegin(GL_QUADS);
    glColor3f(255,255,2);
    glVertex2i(98,285);
    glVertex2i(94,315);
    glVertex2i(106,315);
    glVertex2i(102,285);
    glEnd();
     //LIGHT TRIANGLE OUTER
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    glVertex2i(85,315);
    glVertex2i(115,315);
    glVertex2i(100,340);
    glEnd();
     //LIGHT TRIANGLE INNER 1
    glBegin(GL_TRIANGLES);
    glColor3f(255,255,0);
    glVertex2i(89,317);
    glVertex2i(111,317);
    glVertex2i(100,336);
    glEnd();
     //LIGHT TRIANGLE INNER 2
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    glVertex2i(92,317);
    glVertex2i(108,317);
    glVertex2i(100,336);
    glEnd();
    //LIGHT TRIANGLE INNER 3
    glBegin(GL_TRIANGLES);
    glColor3f(255,255,255);
    glVertex2i(95,317);
    glVertex2i(105,317);
    glVertex2i(100,333);
    glEnd();
    //LIGHT OUTER CIRCLE
     x1=100;  y1=342;  radius1 =5.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	//LIGHT INNER CIRCLE
     x1=100;  y1=342;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();
///

///BENCH 1
glPushMatrix();
glTranslatef(-45.0f,0.0f,0.0f);
//SEAT BACK PART
    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(200,180);
    glVertex2i(200,170);
    glVertex2i(280,170);
    glVertex2i(280,180);
    glEnd();
//SEAT FRONT PART
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,182);
    glVertex2i(282,182);
    glVertex2i(280,180);
    glVertex2i(200,180);
    glEnd();
    //SEAT SIDE PART
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(282,182);
    glVertex2i(282,175);
    glVertex2i(280,170);
    glVertex2i(280,180);
    glEnd();
    //UPPER PART 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,188);
    glVertex2i(280,188);
    glVertex2i(280,183);
    glVertex2i(202,183);
    glEnd();
     //UPPER PART 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,194);
    glVertex2i(280,194);
    glVertex2i(280,189);
    glVertex2i(202,189);
    glEnd();
    //UPPER PART 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,200);
    glVertex2i(280,200);
    glVertex2i(280,195);
    glVertex2i(202,195);
    glEnd();
    //SIDE HANDLE UP
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(280,183);
    glVertex2i(280,186);
    glVertex2i(282,188);
    glVertex2i(282,186);
    glEnd();
     //SIDE HANDLE DOWN
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(282,188);
    glVertex2i(283,188);
    glVertex2i(283,180);
    glVertex2i(282,180);
    glEnd();
     //LEG BACK LEFT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(205,160);
    glVertex2i(207,160);
    glVertex2i(207,205);
    glVertex2i(205,205);
    glEnd();
     //LEG BACK RIGHT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(273,160);
    glVertex2i(275,160);
    glVertex2i(275,205);
    glVertex2i(273,205);
    glEnd();
     //LEG FRONT LEFT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(210,162);
    glVertex2i(212,162);
    glVertex2i(212,170);
    glVertex2i(210,170);
    glEnd();
     //LEG FRONT RIGHT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(278,162);
    glVertex2i(280,162);
    glVertex2i(280,170);
    glVertex2i(278,170);
    glEnd();
glPopMatrix();


///BENCH 2
glPushMatrix();
glTranslatef(260.0f,0.0f,0.0f);
//SEAT BACK PART
    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(200,180);
    glVertex2i(200,170);
    glVertex2i(280,170);
    glVertex2i(280,180);
    glEnd();
//SEAT FRONT PART
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,182);
    glVertex2i(282,182);
    glVertex2i(280,180);
    glVertex2i(200,180);
    glEnd();
    //SEAT SIDE PART
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(282,182);
    glVertex2i(282,175);
    glVertex2i(280,170);
    glVertex2i(280,180);
    glEnd();
    //UPPER PART 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,188);
    glVertex2i(280,188);
    glVertex2i(280,183);
    glVertex2i(202,183);
    glEnd();
     //UPPER PART 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,194);
    glVertex2i(280,194);
    glVertex2i(280,189);
    glVertex2i(202,189);
    glEnd();
    //UPPER PART 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,200);
    glVertex2i(280,200);
    glVertex2i(280,195);
    glVertex2i(202,195);
    glEnd();
    //SIDE HANDLE UP
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(280,183);
    glVertex2i(280,186);
    glVertex2i(282,188);
    glVertex2i(282,186);
    glEnd();
     //SIDE HANDLE DOWN
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(282,188);
    glVertex2i(283,188);
    glVertex2i(283,180);
    glVertex2i(282,180);
    glEnd();
     //LEG BACK LEFT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(205,160);
    glVertex2i(207,160);
    glVertex2i(207,205);
    glVertex2i(205,205);
    glEnd();
     //LEG BACK RIGHT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(273,160);
    glVertex2i(275,160);
    glVertex2i(275,205);
    glVertex2i(273,205);
    glEnd();
     //LEG FRONT LEFT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(210,162);
    glVertex2i(212,162);
    glVertex2i(212,170);
    glVertex2i(210,170);
    glEnd();
     //LEG FRONT RIGHT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(278,162);
    glVertex2i(280,162);
    glVertex2i(280,170);
    glVertex2i(278,170);
    glEnd();

glPopMatrix();
///

///BENCH 3
glPushMatrix();
glTranslatef(-250.0f,0.0f,0.0f);
//SEAT BACK PART
    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(200,180);
    glVertex2i(200,170);
    glVertex2i(280,170);
    glVertex2i(280,180);
    glEnd();
//SEAT FRONT PART
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,182);
    glVertex2i(282,182);
    glVertex2i(280,180);
    glVertex2i(200,180);
    glEnd();
    //SEAT SIDE PART
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(282,182);
    glVertex2i(282,175);
    glVertex2i(280,170);
    glVertex2i(280,180);
    glEnd();
    //UPPER PART 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,188);
    glVertex2i(280,188);
    glVertex2i(280,183);
    glVertex2i(202,183);
    glEnd();
     //UPPER PART 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,194);
    glVertex2i(280,194);
    glVertex2i(280,189);
    glVertex2i(202,189);
    glEnd();
    //UPPER PART 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(202,200);
    glVertex2i(280,200);
    glVertex2i(280,195);
    glVertex2i(202,195);
    glEnd();
    //SIDE HANDLE UP
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(280,183);
    glVertex2i(280,186);
    glVertex2i(282,188);
    glVertex2i(282,186);
    glEnd();
     //SIDE HANDLE DOWN
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(282,188);
    glVertex2i(283,188);
    glVertex2i(283,180);
    glVertex2i(282,180);
    glEnd();
     //LEG BACK LEFT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(205,160);
    glVertex2i(207,160);
    glVertex2i(207,205);
    glVertex2i(205,205);
    glEnd();
     //LEG BACK RIGHT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(273,160);
    glVertex2i(275,160);
    glVertex2i(275,205);
    glVertex2i(273,205);
    glEnd();
     //LEG FRONT LEFT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(210,162);
    glVertex2i(212,162);
    glVertex2i(212,170);
    glVertex2i(210,170);
    glEnd();
     //LEG FRONT RIGHT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(278,162);
    glVertex2i(280,162);
    glVertex2i(280,170);
    glVertex2i(278,170);
    glEnd();

glPopMatrix();
///

///CAR1

glPushMatrix();
glTranslatef(carpos1 ,10.0f, 0.0f);
//shade
    glBegin(GL_QUADS);
    glColor3f(0,255,255);
    glVertex2i(40,60);
    glVertex2i(60,90);
    glVertex2i(130,90);
    glVertex2i(170,60);
    glEnd();
//BACKSCHIELD
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    glVertex2i(45,65);
    glVertex2i(57,65);
    glVertex2i(57,80);
    glEnd();
//DIVIDE LINE 1
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(60,86);
    glVertex2i(128,86);
    glEnd();

//DIVIDE LINE 2
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(40,60);
    glVertex2i(170,60);
    glEnd();

//WINDOW1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(63,82);
    glVertex2i(63,58);
    glVertex2i(93,58);
    glVertex2i(93,82);
    glEnd();
//WINDOW2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(98,82);
    glVertex2i(98,58);
    glVertex2i(125,58);
    glVertex2i(125,82);
    glEnd();
//body
    glBegin(GL_QUADS);
    glColor3f(0, 255,255);
    glVertex2i(40,60);
    glVertex2i(40,20);
    glVertex2i(190,20);
    glVertex2i(190,60);
    glEnd();
    //DIVIDE LINE BACK
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(60,90);
    glVertex2i(60,50);
    glEnd();
    //DIVIDE LINE BOTTOM
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(40,25);
    glVertex2i(190,25);
    glEnd();
    //DIVIDE LINE BACKDOOR
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(60,50);
    glVertex2i(70,40);
    glEnd();
    //DIVIDE LINE FRONTDOOR
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(96,86);
    glVertex2i(96,25);
    glEnd();

    //DIVIDE LINE ONLY FRONT
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(128,86);
    glVertex2i(128,25);
    glEnd();
//LOOKING GLASS
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(135,65);
    glVertex2i(135,55);
    glVertex2i(145,55);
    glVertex2i(145,65);
    glEnd();
    //HANDLE FRONT
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(100,56);
    glVertex2i(100,54);
    glVertex2i(105,54);
    glVertex2i(105,56);
    glEnd();
    //HANDLE BACK
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(65,56);
    glVertex2i(65,54);
    glVertex2i(70,54);
    glVertex2i(70,56);
    glEnd();
//BACK BUMPER
    glBegin(GL_QUADS);
    glColor3f(0, 0,0);
    glVertex2i(35,35);
    glVertex2i(35,20);
    glVertex2i(45,20);
    glVertex2i(45,35);
    glEnd();
//FRONT BUMPER
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(180,35);
    glVertex2i(180,20);
    glVertex2i(192,20);
    glVertex2i(192,35);
    glEnd();
//FRONT WIND-SHIELD
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(128,88);
    glVertex2i(132,88);
    glVertex2i(170,60);
    glVertex2i(158,60);
    glEnd();
//BACK lIGHT
    glBegin(GL_QUADS);
    glColor3f(255, 0,0);
    glVertex2i(38,55);
    glVertex2i(38,40);
    glVertex2i(42,40);
    glVertex2i(42,55);
    glEnd();
//TIRE1
     x1=70;  y1=20;  radius1 =20.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	//TIRE1 INSIDE
     x1=70;  y1=20;  radius1 =10.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//TIRE2
     x1=150;  y1=20;  radius1 =20.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	//TIRE2 INSIDE
     x1=150;  y1=20;  radius1 =10.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	//HEADLIGHT
     x1=187;  y1=45;  radius1 =5.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	//FOGLIGHT
     x1=187;  y1=45;  radius1 =2.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

glPopMatrix();


///CAR2

glPushMatrix();
glTranslatef(carpos2 , 0.0f, 0.0f);
//shade
    glBegin(GL_QUADS);
    glColor3f(0,0,255);
    glVertex2i(350,160);
    glVertex2i(390,180);
    glVertex2i(480,180);
    glVertex2i(500,160);
    glEnd();
//shade UPPER
    glBegin(GL_TRIANGLES);
    glColor3f(0,0,255);
    glVertex2i(390,180);
    glVertex2i(480,180);
    glVertex2i(435,185);
    glEnd();
//WIND SHIELD
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(350,160);
    glVertex2i(380,175);
    glVertex2i(382,172);
    glVertex2i(365,160);
    glEnd();
//body
    glBegin(GL_POLYGON);
    glColor3f(0,0,255);
    glVertex2i(320,155);
    glVertex2i(320,120);
    glVertex2i(520,120);
    glVertex2i(520,160);
    glVertex2i(350,160);
    glEnd();
//DIVIDER LINE
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(350,160);
    glVertex2i(520,160);
    glEnd();
//DIVIDER LINE BOTTOM
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(320,125);
    glVertex2i(520,125);
    glEnd();
//DIVIDER LINE TOP
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(390,180);
    glVertex2i(475,180);
    glEnd();
//DIVIDER LINE ONLY FRONT
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(375,160);
    glVertex2i(375,120);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(375,160);
    glVertex2i(390,180);
    glEnd();
//DIVIDER LINE FRONT DOOR
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(433,180);
    glVertex2i(433,125);
    glEnd();
    //DIVIDER LINE BACK DOOR
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(475,180);
    glVertex2i(475,150);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2i(475,150);
    glVertex2i(460,120);
    glEnd();
//WINDOW1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(395,175);
    glVertex2i(395,160);
    glVertex2i(430,160);
    glVertex2i(430,175);
    glEnd();
//WINDOW2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(435,175);
    glVertex2i(435,160);
    glVertex2i(465,160);
    glVertex2i(465,175);
    glEnd();
    //FRONT BUMPER
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(318,133);
    glVertex2i(318,120);
    glVertex2i(330,120);
    glVertex2i(330,133);
    glEnd();
    //BACK BUMPER
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(510,133);
    glVertex2i(510,120);
    glVertex2i(522,120);
    glVertex2i(522,133);
    glEnd();
    //HEADLIGHT
    glBegin(GL_QUADS);
    glColor3f(255,255,255);
    glVertex2i(318,153);
    glVertex2i(318,140);
    glVertex2i(322,140);
    glVertex2i(322,153);
    glEnd();
    //BACK-LIGHT
    glBegin(GL_QUADS);
    glColor3f(255,0,0);
    glVertex2i(510,153);
    glVertex2i(510,145);
    glVertex2i(521,145);
    glVertex2i(521,153);
    glEnd();
    //LOOKING GLASS
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(380,165);
    glVertex2i(380,155);
    glVertex2i(390,155);
    glVertex2i(390,165);
    glEnd();

//FRONT DOOR HANDLE
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(420,155);
    glVertex2i(420,150);
    glVertex2i(430,150);
    glVertex2i(430,155);
    glEnd();
//BACK DOOR HANDLE
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex2i(460,155);
    glVertex2i(460,150);
    glVertex2i(470,150);
    glVertex2i(470,155);
    glEnd();

//PETROL TANK
     x1=485;  y1=150;  radius1 =5.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	//TIRE1 INSIDE
     x1=370;  y1=120;  radius1 =10.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();

//TIRE1
     x1=370;  y1=120;  radius1 =20.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	//TIRE1 INSIDE
     x1=370;  y1=120;  radius1 =10.0f;
	 triangleAmount = 100; //# of triangles used to draw circle


	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
//TIRE2
     x1=470;  y1=120;  radius1 =20.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(0,0,0);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
	//TIRE2 INSIDE
     x1=470;  y1=120;  radius1 =10.0f;
	 triangleAmount = 100; //# of triangles used to draw circle
	 twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
		glVertex2f(x1, y1); // center of circle
		for(i1 = 0; i1 <= triangleAmount;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi / triangleAmount)),
			    y1 + (radius1 * sin(i1 * twicePi / triangleAmount))
			);
		}
	glEnd();
glPopMatrix();

glFlush();
}









void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,640,0,480);
}





int main(int argc, char** argv)
{
     cout << endl << "*********** Natural View Of A BUSY TOWN ********************" << endl << endl;
       cout << "Press A : To Speed the Boat" << endl << endl;
         cout << "Press D : To Slow the Boat" << endl << endl;
           cout << "Press SPACE : To make the scenario still" << endl << endl;
             cout << "Press M : To Run the scenario" << endl << endl;
              cout << "Press L : To slow down the scenario by half" << endl << endl;

glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize (1520, 800);
glutInitWindowPosition (0, 0);
glutCreateWindow ("BUSY_CITY");
glutDisplayFunc(myDisplay);
myInit ();
glutKeyboardFunc(handleKeypress);
//glutMouseFunc(handleMouse);
glutTimerFunc(1000, update, 0);
glutTimerFunc(1000, updateSun, 0);
glutTimerFunc(1000, updateCloud, 0);
glutTimerFunc(1000, updatesmoke, 0);
glutTimerFunc(1000, updateTrain, 0);
glutTimerFunc(1000, updateCar, 0);
glutMainLoop();
}
