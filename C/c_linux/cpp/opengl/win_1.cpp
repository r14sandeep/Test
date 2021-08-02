#include<GL/glut.h>
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE |GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(100,100);
	glutCreateWindow("TEST");
}
