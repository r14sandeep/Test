#include<GL/glut.h>
#include<iostream>

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
	
	GLfloat arr[200],temp1[200],temp2[200];

	srand(static_cast <unsigned> (time(0)));
	int f1=0,f2=1,f3=1;
	for(int j=0;j<199;j++)
	{
		arr[j]=-1+static_cast <float> (rand()) / static_cast <float> (RAND_MAX/(1+1));
		arr[j+1]=(-1+static_cast <float> (rand()) / static_cast <float> (RAND_MAX/(1+1)));
		
	}
	while(1)
	{
	
	for(int j=0;j<=199;j++)
	{
		temp1[j]=arr[j];temp2[j]=arr[j];
	}
	for(i=0;i<600;i++)
	{
		glColor3f(f1,f2,f3);
		
		for(int j=0;j<199;j+=2)
		{
			glPointSize(3.5);
			glBegin(GL_POINTS);
			
			pt1=temp1[j];
			pt2=temp1[j+1];
			if(((pt1<1)&&(pt1>-1))&&((pt2>-1)&&(pt2<1)))
				glVertex2f(pt1,pt2);
			/*if(i>0)
				for(int k=99;k>99-j;k--)
				{
					glColor3f(1,0,0);
					glVertex2f(temp[k-1],temp[k]);
				
				}
*/
		}
//		cout<<j<<endl;
		usleep(10000);
		glEnd();
			
		glutSwapBuffers();
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);		

		for(int j=0;j<199;j++)
		{
			if((arr[j]>-1)&&(arr[j]<0))
				temp1[j]-=0.0005;
			else
				temp1[j]+=0.0005;
			if((arr[j+1]>-1)&&(arr[j+1]<0))
				temp1[j+1]-=0.0005;
			else
				temp1[j+1]+=0.0005;
		}
		
		
	}
	
	}
	

	

}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_DEPTH|GLUT_SINGLE|GLUT_RGBA);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,200);
	glutInitWindowSize(650,700);
	glutCreateWindow("Initialisation");
	glClearColor(0,0,0,0);
	glutDisplayFunc(renderscene);
	glutMainLoop();

}
