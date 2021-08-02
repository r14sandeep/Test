#include <GL/gl.h>
#include <GL/glut.h>
void renderScene(void) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//      glClearColor(0,1,1,0);
        //glBegin(GL_TRIANGLE_STRIP);
//      glutSolidCube(0.2);

        glBegin(GL_TRIANGLES);
        //glBegin(GL_TRIANGLE_FAN);
        //glBegin(GL_QUADS);
        //glBegin(GL_LINES);
//              glVertex2f(0.5,0.5);
//              glVertex2f(0.0,0.5);
                glVertex3f(-0.5,-0.5,0.0);
                glVertex3f(0.5,0.0,0.0);
                glVertex3f(0.5,0.5,0.0);
        glEnd();

        glutSwapBuffers();
}
 
void display(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_LINES);
 
//glVertex2f(0.0, 0.1); glVertex2f(1.0, 0.1);
//glVertex2f(0.0, 0.2); glVertex2f(1.0, 0.2);
//glVertex2f(0.0, 0.3); glVertex2f(1.0, 0.3);
//glVertex2f(0.0, 0.4); glVertex2f(1.0, 0.4);
 
for(int i=1; i<9; i++){
glVertex2f(0.0, i/10);
glVertex2f(1.0, i/10);
glVertex2f(i/10, 0.0);
glVertex2f(i/10, 1.0);}
    glEnd();
    glFlush ();
        glutSwapBuffers();
}


int main(int argc,char** argv)
{
        int id;
        glutInit(&argc,argv);
        glutInitWindowPosition(100,100);
        glutInitWindowSize(400,500);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
        id=glutCreateWindow("first");
        //cout<<"id:"<<id<<endl;
//      void (*ptr)(int ,int);
//      ptr=changesize;
        glutDisplayFunc(display);
//        glutReshapeFunc(changesize);
//        glutIdleFunc(renderScene);
//        createGLUTMenus();//calling menu creation fn
//      glutDetachMenu(1);
//	glutKeyboardFunc(processnormalkeys);
//        glutSpecialFunc(processspecialkeys);
	display();
        glutMainLoop();
}


