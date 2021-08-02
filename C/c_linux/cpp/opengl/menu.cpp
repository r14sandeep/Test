#include<iostream>
#include<GL/glut.h>
#include<unistd.h>
//#include<GLUT/glut.h>
#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4

using namespace std;
float angle=0.0f;
void drawline()
{
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,10.0f,
		 0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f);
	glLineWidth(10.0f);
	glVertex2f(-10.0f,-20.0f);
	glBegin(GL_LINES);
		glVertex2f(0.0f,0.0f);
		glVertex2f(0.75f,0.0f);
		glVertex2f(0.75f,0.0f);
		glVertex2f(0.75f,0.75f);
	glEnd();
	glutSwapBuffers();


}
void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	glRotatef(angle,1.0f,1.0f,0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
//	glutSolidSphere(0.1,10,20);
//	glutSolidCube(0.2);
//	glutWireSphere(4.1,10,20);
	//cout<<"rotate"<<endl;	
//	glBegin(GL_TRIANGLES);
	//	glVertex3f(-2.0f,-2.0f,0.0f);//selecting XY plane
	//	glVertex3f(2.0f,0.0f,0.0f);
	//	glVertex3f(0.0f,2.0f,0.0f);
	angle+=0.1f;
	glutSwapBuffers();

}

void changesize(int w,int h)
{
	if(h==0)
		h=1;
	float ratio=w*1.0/h;
	glMatrixMode(GL_PROJECTION);
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	cout<<"chagesize"<<endl;
	glViewport(0,0,w,h);
	gluPerspective(45,ratio,1,100);
	//glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
}
void fun()
{
	cout<<"a is pressed"<<endl;
}

void processnormalkeys(unsigned char key,int x,int y)
{
	if(key=='a')
		fun();

}
void processspecialkeys(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_F1:
				glClearColor(1,0,0,0);
				//red=1.0;
				//green=0.0;
				//blue=0.0;
				break;
		case GLUT_KEY_F2:
				glClearColor(0,1,0,0);
				//red=0.0;
				//green=1.0;
				//blue=0.0;
				break;
		case GLUT_KEY_F3:
				glClearColor(0,0,1,0);
				//red=0.0;
				//green=0.0;
				//blue=1.0;
				break;
				

	}


}
void processMenuEvents(int option)
{
	switch(option)
	{
		case RED:
			glClearColor(1,0,0,0);break;
		//	red=1.0f;green=0.0f;blue=0.0f;break;
		case GREEN:
			glClearColor(0,1,0,0);break;
			//red=0.0f;green=1.0f;blue=0.0f;break;
		case BLUE:
			glClearColor(0,0,1,0);break;
			//red=0.0f;green=0.0f;blue=1.0f;break;
		case ORANGE:
			glClearColor(1,1,0,0);break;
			//red=1.0f;green=0.5f;blue=0.5f;break;
	

	}

}
void createGLUTMenus()
{
	int menu;
	menu=glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Red",RED);//adds Red button
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("Orange",ORANGE);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
//	glutDetachMenu(GLUT_LEFT_BUTTON);
//	glutDestroyMenu(menu);
}

int main(int argc,char** argv)
{
	int id;
	glutInit(&argc,argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,500);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	id=glutCreateWindow("first");
	cout<<"id:"<<id<<endl;
//	void (*ptr)(int ,int);
//	ptr=changesize;
	glutDisplayFunc(renderScene);	
	glutReshapeFunc(changesize);
	glutIdleFunc(renderScene);

	drawline();	
//	createGLUTMenus();//calling menu creation fn
//	glutDetachMenu(1);
	glutKeyboardFunc(processnormalkeys);
	glutSpecialFunc(processspecialkeys);
//	int i=1;
//	while(i)
//	{
//		cout<<i++<<endl;
//		sleep(1);
//	}
	glutMainLoop();

}
