#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<ctime>
GLfloat pt1,pt2;
using namespace std;
void renderscene(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//	glBegin(GL_TRIANGLES);
	glutSwapBuffers();
	
	int i;

	srand(static_cast <unsigned> (time(0)));
	int f1=0,f2=1,f3=1;
	for(int j=0;j<50;j++)
	{
	//usleep(200000);
	sleep(2);
	glBegin(GL_POINTS);
	for(i=0;i<100;i++)
	{
	
		glColor3f(f1,f2,f3);
		pt1=-1+static_cast <float> (rand()) / static_cast <float> (RAND_MAX/(1+1));
		pt2=-1+static_cast <float> (rand()) / static_cast <float> (RAND_MAX/(1+1));
		//usleep(1500);
		//printf("%f %f\n",pt1,pt2);
		//while(((pt1<1)&&(pt1>-1))&&((pt2>-1)&&(pt2<-1)))
		//{
			//
			glVertex2f(pt1,pt2);
			//pt1+=0.1;
			//pt2+=0.1;
			
		
		f2 ^=f3^=f2^=f3;
		f1^=f2^=f1^=f2;
	
	}
	glEnd();	
	glutSwapBuffers();
	}
//	puts("hh");
//	glVertex2f(0.5,0.5);
//	glVertex2f(0.0,0.0);
//	glVertex2f(0.5,0.0);
	
//	glFlush();

	

}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_DEPTH|GLUT_SINGLE|GLUT_RGBA);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,200);
	glutInitWindowSize(150,200);
	glutCreateWindow("Initialisation");
	glClearColor(0,0,0,0);
	glutDisplayFunc(renderscene);
	glutMainLoop();

}
