#include<GL/glut.h>
#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;
int tictac[3][3],playerid=0;
int symbol[2]={1,2};
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
//	glColor3f(1.0f,1.0f,1.0f);
	glClearColor(0,1,1,1);
	glBegin(GL_LINES);

	glVertex2f(-0.334, -0.99);
	glVertex2f(-0.334, -0.334);
	glVertex2f(-0.334, -0.334);
	glVertex2f(-0.334, 0.334);
	glVertex2f(-0.334, 0.334);
	glVertex2f(-0.334, 0.99);


	glVertex2f(0.334, -0.99);
	glVertex2f(0.334, -0.334);
	glVertex2f(0.334, -0.334);
	glVertex2f(0.334, 0.334);
	glVertex2f(0.334, 0.334);
	glVertex2f(0.334, 0.99);


	glVertex2f(-0.99, 0.334);
	glVertex2f(-0.334, 0.334);
	glVertex2f(-0.334, 0.334);
	glVertex2f(0.334, 0.334);
	glVertex2f(0.334, 0.334);
	glVertex2f(0.99, 0.334);


	glVertex2f(-0.99, -0.334);
	glVertex2f(-0.334, -0.334);
	glVertex2f(-0.334, -0.334);
	glVertex2f(0.334, -0.334);
	glVertex2f(0.334, -0.334);
	glVertex2f(0.99, -0.334);
	glColor3f(1.0f,0.0f,0.0f);
	/*glRasterPos2f(0.5,0.5);
	char s[2];
	strcpy(s,"AB");
	for(int i=0;i<2;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
	*/


	glEnd();
	glutSwapBuffers();

}

int checkstatus(int i,int j)
{
	//int i,j;
	
	if(tictac[i][j]==0)
	{	
		tictac[i][j]=symbol[playerid];
		
		return 1;
	}
	else
		return 0;
}
void is_gameover(int player)
{
	int temp,cnt;
	cout<<"checking..."<<endl;
	for(int i=0;i<3;i++)
	{
		temp=tictac[i][0];
		cnt=0;
		for(int j=0;j<3;j++)
		{
			if(temp!=0)
			if((temp==tictac[i][j]))
				cnt++;
			
		}

		if(cnt==3)
		{
			glutMouseFunc(NULL);
			//cout<<"i:"<<i<<" j:"<<j<<" t:"<<tictac[i][j-1]<<endl;
			string gamestatus;
			if(player==0)
				gamestatus="Game Over, player1 has won ";
			if(player==1)
				gamestatus="Game Over, player2 has won ";		
			//cout<<"***** player"<<player<<" ****** has won"<<endl;
			cout<<gamestatus<<endl;
			glRasterPos2f(-0.2,0.8);
				
			//gamestatus+=char(player);
			//gamestatus+=" has won";
				
			for(int j=0;gamestatus[j];j++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,gamestatus[j]);
			glEnd();
			glutSwapBuffers();
			//return 0;
		}
	}
	for(int i=0;i<3;i++)
	{
		temp=tictac[0][i];
		cnt=0;
		for(int j=0;j<3;j++)
		{
			if(temp!=0)
				if((temp==tictac[j][i]))
					cnt++;
		}
		if(cnt==3)
		{
			glutMouseFunc(NULL);
			//if(a[i][j])
			//cout<<"i:"<<i<<" j:"<<j<<" t:"<<tictac[i][j-1]<<endl;
			string gamestatus;
			if(player==0)
				gamestatus="Game Over, player1 has won| ";
			if(player==1)
				gamestatus="Game Over, player2 has won| ";		
			cout<<gamestatus<<endl;
		
			
			//string gamestatus="Game Over, player ";	
			//gamestatus+=char(player);
			//gamestatus+=" has won";
			glRasterPos2f(-0.2,0.5);
			for(int j=0;gamestatus[j];j++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,gamestatus[j]);
			glEnd();
			glutSwapBuffers();
				//return 0;
		}
	}


}
void mouse(int button,int state,int x,int y)
{
	int status,i,j;
	//cout<<"button:"<<button<<endl;
	//cout<<"st:"<<state<<endl;
	//cout<<"x:"<<x<<endl;
	//cout<<"y:"<<y<<endl;
	glColor3f(1.0f,0.0f,0.0f);
	
	//glRasterPos2f(-0.3f,1.0f);
	

	i=(x/101);
	j=(y/134);
	static int clickcnt=0;	
	if(state==1)
	{
		//cout<<"x:"<<x<<" y:"<<y<<endl;
		//cout<<"i:"<<i<<" j:"<<j<<endl;
		status=checkstatus(j,i);
		if(status==1)
		{
			//cout<<"st:"<<status<<endl;
			clickcnt++;
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			glLoadIdentity();
			//glTranslatef(-0.65, 0.65, 0.0f);
			//cout<<"i:"<<i<<" j:"<<j<<endl;
			//cout<<((i/10)*0.3-0.5)<<" "<<(j/10-0.5)<<endl;
//			glTranslatef((i*0.65)-0.9, (-j*0.68)+0.4, 0.0f);
		//	glBegin(GL_POINTS);
			if(playerid==0)
			{
				glTranslatef((i*0.65)-0.9, (-j*0.68)+0.4, 0.0f);
				glBegin(GL_LINES);
				glVertex2f(0.0, 0.5);
				glVertex2f(0.5, 0.0);
				glVertex2f(0.0, 0.0);
				glVertex2f(0.5, 0.5);
				if(clickcnt>3)
					is_gameover(playerid);
			}
			else if(playerid==1)
				{
					glTranslatef((i*0.65)-0.65, (-j*0.6)+0.6, 0.0f);
					cout<<"i:"<<i<<" j:"<<j<<endl;
					cout<<((i/10)*0.3-0.5)<<" "<<(j/10-0.5)<<endl;
					glBegin(GL_POINTS);
					for(int k=0;k<1000;++k)
						glVertex3f(cos(2*3.14159*k/1000.0)*0.25,sin(2*3.14159*k/1000.0)*0.25,0);
					if(clickcnt>3)
						is_gameover(playerid);

				}

			playerid++;	
		}

	}
	if(playerid>1)
		playerid=0;
//	for(int i=0;i<2;i++)
//		for(int j=0;j<5;j++)
//			if(i==0)
//				glVertex2f((0.5-j/10),j/10);
			//else
			//	glVertex2f((0.5-j/10),j/10);		
	/*for(int i=0;i<1000;++i)
	{

		glVertex3f(cos(2*3.14159*i/1000.0)*0.3,sin(2*3.14159*i/1000.0)*0.3,0);

	}
*/
	glEnd();
	glutSwapBuffers();
}
int main(int argc,char **argv)
{
	bzero(tictac,sizeof(tictac));
	glutInit(&argc,argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(300,400);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Tic Tac Toe");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	string name="player1 turn";
	glRasterPos2f(-0.2,0.5);
	cout<<"name"<<endl;
	for(int j=0;name[j];j++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,name[j]);
	glEnd();
	//glutSwapBuffers();
	glutMainLoop();
	

}
