
#include<GL/gl.h> //including gl header file
#include<GL/glu.h> //including glu header file
#include<GL/glut.h>
void myInit(void)
{
glClearColor(1.0,1.0,1.0,10.); //specifying clear values for the color buffer
glColor3f(0.0f,0.0f,0.0f); //sets the current color
glPointSize(4.0); //sets the size of the line
glMatrixMode(GL_PROJECTION); //specifying current matrix mode
glLoadIdentity(); //replaces the current matrix with the identity matrix
gluOrtho2D(0.0,640.0,0.0,480.0); //defines a 2D orthographic projection matrix
}
/*Logic to draw home*/
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
glVertex2i(20,20);
glVertex2i(600,20);
//horizontal base line
//clearing buffer to present valueglVertex2i(20,20);
//vertical line 1
glVertex2i(40,200);
glVertex2i(100,20);
glVertex2i(200,300);
glVertex2i(600,20);
glVertex2i(600,300);
glVertex2i(20,300);
glVertex2i(600,300);
glVertex2i(20,300);
glVertex2i(120,400);
glVertex2i(200,300);
glVertex2i(120,400);
glVertex2i(600,300);
glVertex2i(480,400);
glVertex2i(120,400);
glVertex2i(480,400);
glVertex2i(300,100);
glVertex2i(300,200);
glVertex2i(400,100);
glVertex2i(400,200);
//vertical line 2glVertex2i(300,100);
glVertex2i(400,100);
glVertex2i(300,200);
glVertex2i(400,200);
glEnd();
glFlush();
}
/*Main Function*/
int main(int argc,char **argv)
{
glutInit(&argc, argv); //initializing the glut library
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //specifying display mode
glutInitWindowSize(640,480); //specifying the initial size of the window
glutInitWindowPosition(100,150); //specifying the initial position of the window
glutCreateWindow("My sweet Home...");
glutDisplayFunc(myDisplay);
myInit(); //calling myInit()
glutMainLoop(); //starting glutMainLoop
return 0;
}


/* 
run 
g++ home2.cpp -lGL -lGLU -lglut
*/
