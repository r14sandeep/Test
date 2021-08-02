#include<iostream>
#include<cstring>
#include<unistd.h>
#include<GL/glut.h>
using namespace std;
float pt=0.1f;
void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//      glClearColor(0,1,1,0);
        //glBegin(GL_TRIANGLE_STRIP);
//        glBegin(GL_TRIANGLES);
        //glBegin(GL_TRIANGLE_FAN);
        //glBegin(GL_QUADS);
//        glBegin(GL_POINTS);
	cout<<"***\n";
//	sleep(1);
	glutSolidCube(0.025);
	//glTranslatef(0.5f,-0.8f,-40.0f);
	glLineWidth(2.0f);
	glTranslatef(pt,-0.8f,0.0f);
	//sleep(1);
//              glVertex2f(0.5,0.5);
  //            glVertex2f(0.0,0.5);
//                glVertex3f(pt,0.5,0.0);
  //              glVertex3f(0.5,0.0,0.0);
//                glVertex3f(0.5,0.5,0.0);
//	pt+=0.1f;
        glEnd();

/*	for(int i=0;i<10;i++)
	{
		for(int j=0;j<=i;j++)
			glutSolidCube(0);
		
		glutSolidCube(0.025);
		glVertex2f(0,100);
		glVertex2f(10,300);
	}
*/
/*	cell_t tab[3][4];
	string st="abcd";
	//glRasterPos2f(100.0,300.0);
	for(int i=0;i<4;i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st[i]);

                //glVertex2i(0.5,0.0,0.0);
*/	glutSwapBuffers();



}
void callback(int x)
{
	glLoadIdentity();
	glutSolidCube(0.025);
	cout<<"call"<<endl;
	glTranslatef(pt,-0.8,0.0);
	pt+=0.2f;
	glutTimerFunc(800,callback,0);
        glEnd();
	glutSwapBuffers();


}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,500);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Snake Game");
	glutDisplayFunc(renderScene);
	glutTimerFunc(800,callback,0);
	glutMainLoop();
}
