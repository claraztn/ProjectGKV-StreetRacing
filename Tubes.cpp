// Anggota:
// Izazava Putri Asari 			24060122120038
// Asy’syifa Shabrina Munir		24060122130055
// Clara Zita Nabilla			24060122130057
// Keisya Intan Nabila			24060122130063
// Lab GKV B2

#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
#include <stdlib.h>
#define rad (3.1416/180)
#define EN_SIZE 20

#define checkImageWidth 512
#define checkImageHeight 512

const double PI = 3.141592653589793;
int i, j, radius1, jumlah_titik, x_tengah, y_tengah;

using namespace std;

typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned char uchar;

using namespace std;

int score = 0;
float zoom = 3;
int tola[5000][5000];
float tX=0, tY=0, tZ=-8, rX=0, rY=0, rZ=4;
float tZ1=-20, tZ2=-40, tZ3=-60, tZ4=-80, tZ5=-100, tZ6=-120;
float tolZ1=-20, tolZ2=-40, tolZ3=-60, tolZ4=-80, tolZ5=-100, tolZ6=-120;
float rotX=0, rotY=0, rotZ=0;
float cosX=0, cosY=1, cosZ=0;
float angle=0;
float xEye=0.0f, yEye=5.0f, zEye=30.0f;
float cenX=0, cenY=0, cenZ=0, roll=0;
float radius=0;
float theta=0, slope=0;
float speed=0.1;
float angleBackFrac=0.2;
bool saheedMinarVisible=false;
float r[]={0.1, 0.4, 0.0, 0.9, 0.2, 0.5, 0.0, 0.7, 0.5, 0.0};
float g[]={0.2, 0.0, 0.4, 0.5, 0.2, 0.0, 0.3, 0.9, 0.0, 0.2};
float b[]={0.4, 0.5, 0.0, 0.7, 0.9, 0.0, 0.1, 0.2, 0.5, 0.0};
int TIME=0;
bool START=false;

float cubePosX[4]={2, -3, 4, -1};
bool rot=false;

static void resize(int width, int height)
{
	const float ar = (float) width/ (float) height;
	
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void drawCar() {
    // Kubus Bawah
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Kubus Atas
    glColor3f(0.8, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.4, 0.5, 0);
    glScalef(1.2, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
    
      // Kaca depan
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(-0.21, 0.5, 0.0); 
	glRotatef(90.0, 0.0, 1.0, 0.0); 
	glTranslatef(-0.5, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(0.05, 0.2);
	glVertex2f(0.95, 0.2);
	glVertex2f(0.95, -0.2);
	glVertex2f(0.05, -0.2);
	glEnd();
	glPopMatrix();
	
	// Kaca Samping
	glColor3f(1.0f, 1.0f, 1.0f); 
	glPushMatrix();
	glTranslatef(0.1,0.5,-0.409);
	glScalef(1.2, 1, 0.5);
	glutSolidCube(0.4);
	glPopMatrix();
	
	glColor3f(1.0f, 1.0f, 1.0f); 
	glPushMatrix();
	glTranslatef(0.7,0.5,-0.409);
	glScalef(1.2, 1, 0.5);
	glutSolidCube(0.4);
	glPopMatrix();
	
	glColor3f(1.0f, 1.0f, 1.0f); 
	glPushMatrix();
	glTranslatef(0.1,0.5, 0.409);
	glScalef(1.2, 1, 0.5);
	glutSolidCube(0.4);
	glPopMatrix();
	
	glColor3f(1.0f, 1.0f, 1.0f); 
	glPushMatrix();
	glTranslatef(0.7,0.5, 0.409);
	glScalef(1.2, 1, 0.5);
	glutSolidCube(0.4);
	glPopMatrix();
	
	// Kaca belakang
    glColor3f(1.0f, 1.0f, 1.0f); 
	glPushMatrix();
	glTranslatef(0.775, 0.5, -0.01);
	glScalef(1.2, 1, 2.2);
	glutSolidCube(0.4);
	glPopMatrix();
	
	glColor3f(0.7686f, 0.8706f, 0.9647f);
	glPushMatrix();
	glTranslatef(1.01, 0.5, 0.0); 
	glRotatef(90.0, 0.0, 1.0, 0.0); 
	glTranslatef(-0.5, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(0.05, 0.2);
	glVertex2f(0.95, 0.2);
	glVertex2f(0.95, -0.2);
	glVertex2f(0.05, -0.2);
	glEnd();
	glPopMatrix();

	//Bawah kap
    glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-1.01, 0.0, 0.0); 
	glRotatef(90.0, 0.0, 1.0, 0.0); 
	glTranslatef(-0.5, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(0.05, 0.2);
	glVertex2f(0.95, 0.2);
	glVertex2f(0.95, -0.2);
	glVertex2f(0.05, -0.2);
	glEnd();
	glPopMatrix();

    // Roda
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(-0.6, -0.3, 0.6);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.6, -0.3, -0.6);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, -0.3, 0.6);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, -0.3, -0.6);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();
    
    // roda cadangan
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0); 
    glTranslatef(0.0, 0.23, 1.11);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();

    // Bumper
	glColor3f(0.4549f, 0.4549f, 0.4549f);
	glPushMatrix();
	glTranslatef(1.01, 0.0, 0.0); 
	glRotatef(90.0, 0.0, 1.0, 0.0); 
	glTranslatef(-0.5, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(0.05, -0.045);
	glVertex2f(0.95, -0.045);
	glVertex2f(0.95, -0.2);
	glVertex2f(0.05, -0.2);
	glEnd();
	glPopMatrix();
    
    // Lampu belakang
	glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(1.0, -0.12, 0.3);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0, -0.12, -0.3);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // Lampu depan
	glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(-1.0, -0.05, 0.3);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0, -0.05, -0.3);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();
}

//Membuat objek gerbang 
void gatePoint(int x, float *z){

	glPushMatrix();
	glColor3d(0.5,0.6,0.8);
	glColor3d(0.77, 0.71, 0.73);
	glColor3d(0.99, 0.97, 0.87);
	
	glTranslated(cubePosX[x], 1, *z);
	glScaled(0.5, 4, 0.5);
	glutSolidSphere(1, 50, 50);
	glutSolidCube(1);
	
	glTranslated(-5, 0, 0);
	glutSolidCube(1);
	glutSolidSphere(1, 50, 50);
	glColor3d(0.99, 0.97, 0.87);
	
	glTranslated(2.5, 0.425, 0);
	glScaled(5, 0.15, 1.1);
	glutSolidCube(1);
	glPopMatrix();
	if(cubePosX[x]+tX > -0.2 && cubePosX[x]+tX < 2.2){
		if (*z > 0 && *z < 1){
			score += 1;
			speed += 0.001;
		}
	}
	*z += speed;
	if (*z > 28){
		*z = -110;
	}
}

// Garis jalan lurus
void markLine(){
	double Mark = 10;
	glPushMatrix();
	glColor3d(1, 1, 1);
	glScaled(Mark-9.9, 0.4, 35);
	glutSolidCube(1);
	glPopMatrix();
}

// Garis jalan putus-putus
void markLine2(){
	double Mark = 10;
	glPushMatrix();
	glColor3d(1, 1, 1);
	glScaled(Mark-9.9, 0.4, 5);
	glutSolidCube(1);
	glPopMatrix();
}

// Membuat tanah
void ground(){
	glColor3d(0.60, 0.46, 0.32);
	glColor3d(0.22, 0.12, 0);
	
	glPushMatrix();
	glTranslated(0, -1.5, 0);
	glScaled(EN_SIZE*10.2, 0.3, EN_SIZE*4);
	glutSolidCube(1);
	glPopMatrix();
}

// Membuat dinding pembatas kanan
void rightWall(){
	glColor3d(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslated(5, 0, 0);
	glScaled(1, 1, 40);
	glutSolidCube(1);
	glPopMatrix();
}

// Membuat dinding pembatas kiri
void leftWall(){
	glColor3d(0.4, 0.4, 0.4);
	glPushMatrix();
	glTranslated(-7, 0, 0);
	glScaled(1, 1, 40);
	glutSolidCube(1);
	glPopMatrix();
}

// Membuat tiang listrik
void listrikkanan(){
	// tiang
	glColor3d(0.5, 0.52, 0.51);
	glPushMatrix();
	glTranslated(7.5, 0, 0);
	glScaled(0.3, 8, 0.3);
	glutSolidCube(1);
	glPopMatrix();
	
	// penyangga
	glColor3d(0.5, 0.52, 0.51);
	glPushMatrix();
	glTranslated(7.5, 4, 0);
	glScaled(2.3, 0.3, 0.3);
	glutSolidCube(1);
	glPopMatrix();
	
	// kabel 
	glColor3d(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(7.5, 4, 0);
	glScaled(0.05, 0.05, 50);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(8.5, 4, 0);
	glScaled(0.05, 0.05, 50);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(6.5, 4, 0);
	glScaled(0.05, 0.05, 50);
	glutSolidCube(1);
	glPopMatrix();
}

void listrikkiri(){
	// tiang
	glColor3d(0.5, 0.52, 0.51);
	glPushMatrix();
	glTranslated(-15.5, 0, 0);
	glScaled(0.3, 10, 0.3);
	glutSolidCube(1);
	glPopMatrix();
	
	// penyangga
	glColor3d(0.5, 0.52, 0.51);
	glPushMatrix();
	glTranslated(-15, 5, 0);
	glScaled(2.3, 0.3, 0.3);
	glutSolidCube(1);
	glPopMatrix();
	
	// kabel 
	glColor3d(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslated(-15, 5, 0);
	glScaled(0.05, 0.05, 50);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-16, 5, 0);
	glScaled(0.05, 0.05, 50);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-14, 5, 0);
	glScaled(0.05, 0.05, 50);
	glutSolidCube(1);
	glPopMatrix();
}

// Matahari
void sun() {
    glPushMatrix();
    glColor3f(0.81, 0.47, 0.06);
    glTranslatef(-5.0, 20.0, -60.0); 
    glutSolidSphere(2.0, 50, 50); 
    glPopMatrix();
}

//Membuat gedung di belakang tiang listrik
void gedung(){
    float gedungHeight1 = 9.0; // Tinggi gedung pertama
    float gedungHeight2 = 15.0; // Tinggi gedung kedua

    // Posisi gedung pertama
    float gedungPosX1 = 20.0;
    float gedungPosZ1 = 15.0;
    
    // Gedung 1
    glPushMatrix();
        glTranslatef(gedungPosX1, gedungHeight1 / 3, gedungPosZ1); 
        glColor3f(0.74, 0.12, 0.22);
        glScalef(15.0, gedungHeight1, 35.0); 
        glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(gedungPosX1, (8.0 / 2), gedungPosZ1 + 7.0); 
        glColor3f(0.44, 0.85, 0.93);
        glScalef(15.1, 5.0, 7.0);
        glutSolidCube(1);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(gedungPosX1, (8.0 / 2), gedungPosZ1 - 5.0); 
        glColor3f(0.89, 0.97, 0.36);
        glScalef(15.1, 5.0, 7.0);
        glutSolidCube(1);
    glPopMatrix();
}

// Membuat pohon 
void pohon(){
	//batang 
	glPushMatrix();
	glColor3ub(122, 61, 31);
	glRotated(270, 1, 0, 0);
	glTranslatef(-7.5, -15.2, -1);
	gluCylinder(gluNewQuadric(), 1, 1, 3, 3, 3);
	glPopMatrix();
	
	//daun
	glPushMatrix();
	glColor3ub(25, 148, 19);
	glScaled(1, 1, 1);
	glRotated(90, 0, 1, 0);
	glTranslatef(-15, 4.2, -7.5);
	glutSolidDodecahedron();
	glPopMatrix();
	
	glPushMatrix();
	glColor3ub(18, 118, 13);
	glScaled(1, 1, 1);
	glRotated(90, 0, 1, 0);
	glTranslatef(-15, 3.2, -6.5);
	glutSolidDodecahedron();
	glPopMatrix();
	
	glPushMatrix();
	glColor3ub(30, 130, 25);
	glScaled(1, 1, 1);
	glRotated(90, 0, 1, 0);
	glTranslatef(-15, 3.2, -8.5);
	glutSolidDodecahedron();
	glPopMatrix();
}

// Membuat semak-semak 
void semaksemak(){
	//semak1
	glPushMatrix();
	glColor3ub(25, 148, 19);
	glScaled(2, 2, 2);
	glRotated(90, 0, 1, 0);
	glTranslatef(-15, 1, -14);
	glutSolidDodecahedron();
	glPopMatrix();
	
	glPushMatrix();
	glColor3ub(18, 118, 13);
	glScaled(2, 2, 2);
	glRotated(90, 0, 1, 0);
	glTranslatef(-15, 1, -13);
	glutSolidDodecahedron();
	glPopMatrix();
	
	glPushMatrix();
	glColor3ub(30, 130, 25);
	glScaled(2, 2, 2);
	glRotated(90, 0, 1, 0);
	glTranslatef(-15, 1, -15);
	glutSolidDodecahedron();
	glPopMatrix();
	
	// semak2
	glPushMatrix();
	glColor3ub(25, 148, 19);
	glScaled(1, 1, 1);
	glRotated(90, 0, 1, 0);
	glTranslatef(-15, 1, -14);
	glutSolidDodecahedron();
	glPopMatrix();
	
	glPushMatrix();
	glColor3ub(18, 118, 13);
	glScaled(1, 1, 1);
	glRotated(90, 0, 1, 0);
	glTranslatef(-15, 1, -13);
	glutSolidDodecahedron();
	glPopMatrix();
	
	glPushMatrix();
	glColor3ub(30, 130, 25);
	glScaled(1, 1, 1);
	glRotated(90, 0, 1, 0);
	glTranslatef(-15, 1, -15);
	glutSolidDodecahedron();
	glPopMatrix();
}

// lampu 
void lampu1(){
	glColor3d(0.5, 0.52, 0.51);
	glPushMatrix();
	glTranslatef(-10.0, 0.0, 8.0);
	glScaled(0.1, 2, 0.1);
	glutSolidCube(2);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-10.0, 2.0, 8.0);
	glutSolidSphere(0.6, 8, 8);
	glPopMatrix();
}

void lampu2(){
	glColor3d(0.5, 0.52, 0.51);
	glPushMatrix();
	glTranslatef(-10.0, 0.0, 2.0);
	glScaled(0.1, 2, 0.1);
	glutSolidCube(2);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-10.0, 2.0, 2.0);
	glutSolidSphere(0.6, 8, 8);
	glPopMatrix();
}

// Awan 
void awan(){
	// awan kiri
	glPushMatrix();
	glTranslatef(-20, 20, 30);
	glColor3f(1, 1, 1);
	glutSolidSphere(6, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-15, 20, 30);
	glutSolidSphere(4, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-25, 20, 30);
	glutSolidSphere(4, 50, 50);
	glPopMatrix();
	
	// awan kanan
	glPushMatrix();
	glTranslatef(15, 20, 1);
	glColor3f(1, 1, 1);
	glutSolidSphere(6, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(20, 20, 1);
	glutSolidSphere(4, 50, 50);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(10, 20, 1);
	glutSolidSphere(4, 50, 50);
	glPopMatrix();
}

void environment(){
	// Jalan 
	glColor3d(0.25, 0.25, 0.25);
	glPushMatrix();
	glTranslated(0, 0, 0);
	glScaled(EN_SIZE*0.7, 0.3, EN_SIZE*4);
	glutSolidCube(1);
	glPopMatrix();
	
    awan();
	
	// garis jalan tengah
	glTranslated(0, 0, 0);
	markLine();
	
	// garis jalan kiri kanan
	glTranslated(-3, 0, 0);
	markLine2();
	
	// garis jalan kiri kanan
	glTranslated(6, 0, 0);
	markLine2();
	
	glTranslated(-3, 0, 0);
	glColor3d(1, 1, 1);
	
	glTranslated(1, 0.5, 1);
	rightWall();
	leftWall();
	pohon();
	semaksemak();
    lampu1();
    lampu2();
	listrikkanan();
	listrikkiri();
	gedung();
	ground();
}

void draw(){
	double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	double a = t*90.0;
	
	TIME = t;
	
	// Mobil
	glPushMatrix();
    glTranslated(0, 0.7, 0);
	glRotated(270, 0, 1, 0);
    glScaled(0.8, 0.8, 0.8);
    drawCar();
	glPopMatrix();
	
	// lingkungan
	if(tX >= 5.2)tX = 5.2;
	if(tX <= -5.2)tX = -5.2;
	if(tY > 0.1)tY = 0.1;
	if(tY < -15)tY = -15;
	
	glPushMatrix();
	glTranslated(tX, tY, tZ);
	environment();
	glPopMatrix();
	glPushMatrix();
	glTranslated(tX, 0, 0);
	gatePoint(8, &tolZ1);
	
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, tY, tZ1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, tY, tZ2);
	environment();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, 0, 0);
	gatePoint(3, &tolZ2);
	
	sun();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, tY, tZ3);
	environment();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, 0, 0);
	gatePoint(2, &tolZ3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, tY, tZ4);
	environment();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, 0, 0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, tY, tZ5);
	environment();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, 0, 0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, tY, tZ6);
	environment();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(tX, 0, 0);
	gatePoint(2, &tolZ6);
	glPopMatrix();
	
	tZ += speed;
	tZ1 += speed;
	tZ2 += speed;
	tZ3 += speed;
	tZ4 += speed;
	tZ5 += speed;
	tZ6 += speed;
	
	if(tZ >=20)tZ =- 110;
	if(tZ1 >= 20)tZ1 = -110;
	if(tZ2 >= 20)tZ2 = -110;
	if(tZ3 >= 20)tZ3 = -110;
	if(tZ4 >= 20)tZ4 = -110;
}

void drawBitmapText(char *str, float x, float y, float z)
{
	char *c;
	glRasterPos3f(x, y+8, z);
	
	for (c = str; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

void drawStrokeText(char* str, int x, int y, int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x-1, y+8, z);
	glScalef(0.004f, 0.004f, z);
	
	for (c = str; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}

void drawStrokeText2(char* str, int x, int y, int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x-0.5, y+8, z);
	glScalef(0.0065f, 0.0065f, z);
	
	for (c = str; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}

void drawStrokeText3(char* str, int x, int y, int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x, y+8, z);
	glScalef(0.002f, 0.002f, z);
	
	for (c = str; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}

void drawStrokeChar(char c, float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y+8, z);
	glScalef(0.002f, 0.002f, z);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	glPopMatrix();
}

static void display(void){
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	double a = t*80.0;
	double aa = a;
	double b = t*20.0;
	double bb = b;
	
	if(!rot){
		a = 0;
	}
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(	0.0, 3.2, 10.0,
				0,  4, 0,
				0,  1.0f, 0.0f);
	if(START){
		glPushMatrix();
		glTranslated(0,0,-1);
		glScaled(zoom, zoom, zoom);
		glRotated(a, 0,1,0);
		glRotated(10,1,0,0);
		draw();
		glPopMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		drawStrokeText3("LEFT: A, RIGHT: D, RESUME: R", -8, 0.9, 0);
		drawStrokeText3("TIME: ", 0.9,0,0);
		int mod, number = 0;
		while(TIME){
			mod = TIME%10;
			number = number*10+mod;
			TIME = TIME / 10;
		}
		float tmp = 0;
		
		while(number){
			mod = number%10;
			drawStrokeChar(mod+48, 1.2+tmp,0,0);
			number = number / 10;
			tmp+= 0.2;
		}
		
		//menampilkan skor
		char score2[100];
		int score3 = sprintf(score2, "SCORE: %d", score);
		drawStrokeText3(score2, 3, 0,0);	
		
	}
	else{
		glPushMatrix();
		glTranslated(0,2,0);
		glRotated(aa, 0,3,0);
		glScaled(2.5,2.5,2.5);
        drawCar();
		glPopMatrix();
		
		glColor3f(1.0, 1.0, 1.0);
		drawStrokeText("Press Space to Start", -1, -2, 0);
		drawStrokeText2("Street Racing", -2,-1,0);
	}
	glutSwapBuffers();	
}

static void key(unsigned char key, int x, int y){
	float frac = 0.3; 
	float rotFrac = 1;
	switch (key){
		case 27:
		case 'q':
			exit(0);
			break;
		case 'a':
			tX += frac;
			break;
		case 'd':
			tX -= true;
			break;
		case ' ':
			START = true;
			break;
		case 'r':
			START = false;
			break;
	}
	glutPostRedisplay();
} 

static void idle(void)
{
	glutPostRedisplay();
}

const GLfloat light_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f}; // Kurangi pengaruh ambient
const GLfloat light_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f}; // Warna utama dari cahaya
const GLfloat light_specular[] = {0.5f, 0.5f, 0.5f, 1.0f}; // Highlight yang lebih halus
const GLfloat light_position[] = {2.0f, 5.0f, 5.0f, 0.0f};

const GLfloat mat_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f}; // Warna ambient dari material
const GLfloat mat_diffuse[] = {1.0f, 0.5f, 0.0f, 1.0f}; // Warna utama dari material
const GLfloat mat_specular[] = {0.5f, 0.5f, 0.5f, 1.0f}; // Highlight dari material
const GLfloat high_shininess[] = {50.0f}; // Mengatur kilap material

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1366, 720);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_RGBA);
	glutCreateWindow("TUGAS BESAR GKV");
	
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);
	
    glClearColor(0.64, 0.73, 0.89, 1);
    glClearColor(0.16, 0.39, 0.76, 1);
    glClearColor(0.94, 0.78, 0.54, 1);
    glClearColor(1, 0.58, 0.29, 1);
    glClearColor(0.31, 0.66, 1, 1);
    glClearColor(0.44, 0.8, 1, 1);
    
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	
	glutMainLoop();
	
	return EXIT_SUCCESS;
}
