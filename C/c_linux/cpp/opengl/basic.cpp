#include<iostream>
#include<cstring>
#include<unistd.h>
#include<GL/glut.h>
#include<GL/freeglut.h>
using namespace std;
float pt=0.1f;
void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//      glClearColor(0,1,1,0);
//        glBegin(GL_POINTS);
	cout<<"***\n";
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1, 0, 0, 1, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(1.0f,0.0f,0.0f);
	glLineWidth(20.0f);
//	glutSolidCube(0.025);
	//glTranslatef(0.5f,-0.8f,-40.0f);
//	glTranslatef(pt,-0.8f,0.0f);
	glBegin(GL_LINES);
	//glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(-0.5,0.0f);
		glVertex2f(0.0f,0.5f);
//		glTranslatef(-1.5f,-1.8f,0.0f);
		//glVertex2f(-9.0f,-9.0f);	
//        glVertex3f(0.0f,2.0f,0.0f);
//              glVertex2f(0.5,0.5);
	pt+=0.3f;
glMatrixMode( GL_PROJECTION ) ;
glPushMatrix() ; // save
glLoadIdentity();// and clear
glMatrixMode( GL_MODELVIEW ) ;
glPushMatrix() ;
glLoadIdentity() ;

glDisable( GL_DEPTH_TEST ) ; // also disable the depth test so renders on top


	string gamestatus;
	gamestatus="Game Over, player1 has won| ";
	glRasterPos2f(-0.9,0.9);
	for(int j=0;j<10;j++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,gamestatus[j]);

glEnable( GL_DEPTH_TEST ) ; // Turn depth testing back on

glMatrixMode( GL_PROJECTION ) ;
glPopMatrix() ; // revert back to the matrix I had before.
glMatrixMode( GL_MODELVIEW ) ;
glPopMatrix() ;
	
        glEnd();

/*	cell_t tab[3][4];
	string st="abcd";
	//glRasterPos2f(100.0,300.0);
	for(int i=0;i<4;i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st[i]);

                //glVertex2i(0.5,0.0,0.0);
*/	glutSwapBuffers();



}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(300,400);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Snake Game");
//	glutDisplayFunc(renderScene);
	cout<<"ver:"<<glGetString(GL_VERSION)<<endl;
//	glutTimerFunc(800,callback,0);
	glutMainLoop();
}
