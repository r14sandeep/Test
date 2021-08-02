#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include<unistd.h>
#include<math.h>
//#include<GLUT/glut.h>
#define RED 1
#define GREEN 2
#define BLUE 3
#define ORANGE 4

using namespace std;
/*void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glClearColor(0,1,1,0);
	//glBegin(GL_TRIANGLE_STRIP);
//	glutSolidCube(0.2);

	glBegin(GL_TRIANGLES);
	//glBegin(GL_TRIANGLE_FAN);
	//glBegin(GL_QUADS);
	//glBegin(GL_LINES);
//		glVertex2f(0.5,0.5);
//		glVertex2f(0.0,0.5);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(0.5,0.5,0.0);
	glEnd();

        glutSwapBuffers();
}*/
float angle=0.0f;
void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(0.0f,0.0f,10.0f,
		 0.0f,0.0f,0.0f,
		  0.0f,1.0f,0.0f);
//	glRotatef(angle,1.0f,1.0f,0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
//	glutSolidSphere(0.1,10,20);
//	glutSolidCube(0.2);
//	glutWireSphere(4.1,10,20);
	//cout<<"rotate"<<endl;	
//	glBegin(GL_TRIANGLES);
	//glBegin(GL_POINTS);
	//	glVertex2f(0.0f,4.0f);
	//	glVertex2f(2.0f,0.0f);
	//	glVertex2f(0.0f,2.0f);
//		glVertex3f(-2.0f,-2.0f,0.0f);//selecting XY plane
//		glVertex3f(2.0f,0.0f,0.0f);
//		glVertex3f(0.0f,2.0f,0.0f);


/*			string str="abc";
			glRasterPos2f(0.5f,0.5f);
			for(int i=0;str[i];i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
*/
/*string String="hello";
glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 0, 0, 0, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2f(0.0,0.5);
    for (int i=0; i<String.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
*/
 glBegin(GL_POINTS);
//	glRasterPos2f(-0.8f,0.8f);
//glVertex2d( 0.3 * cos(0.0) , 0.3 * sin(0.0));
glPoint(-0.8,0.8,0);
 for(int i=0;i<1000;++i)
  {
  glVertex3f(cos(2*3.14159*i/1000.0)*0.3,sin(2*3.14159*i/1000.0)*0.3,0);
//  glVertex3f(cos(2*2.0*i/1000.0),sin(2*2.0*i/1000.0),0);
  }
// glEnd();
	glEnd();
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
int menu;
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
	//int menu;
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

	createGLUTMenus();//calling menu creation fn
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
