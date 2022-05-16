



#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>    // Header File For The OpenGL32 Library
#include <GL/glu.h>  
#include <stdlib.h>
#include <math.h>

int carStatus=1;
float carX=0;
float carY=0;
float  counter=0.0;
void car();
void road();
void wheel();
void scenery();


void initOpenGl()
{
   glClearColor(1.0f,1.0f,1.0f,1.0f); //Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,700,0,500);
}

void wheel(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(1,1,1);
   for(int i=0;i<360;i++)
   {
       th=i*(3.1416/180);
       glVertex2f(x+13*cos(th),y+13*sin(th));
   }

   glEnd();

}

void drawcar()                       //draw the structure of car
{

glPushMatrix();
  glBegin(GL_POLYGON);
glColor3f(1.0,0.0,1.0);
   glVertex2f(50,140);
   glVertex2f(150,140);
   glVertex2f(150,170);
   glVertex2f(50,170);
  glEnd();
 glBegin(GL_POLYGON);
glColor3f(1.0,0.0,1.0);
   glVertex2f(60,170);
  glVertex2f(75,185);
  glVertex2f(110,185);
  glVertex2f(130,170);
  glEnd();

 wheel(77,140);
 wheel(127,140);
 glPopMatrix();
}

void scenery()                         //function to draw scenery
{
glPushMatrix();
glBegin(GL_POLYGON);                     //hill
glColor3f(0.0,0.5,1.0f);
glVertex2f(0,600); 
glVertex2f(900,600);
glColor3f(0.0,0.5,1.0f);
glVertex2f(900,0);
//glVertex2f(900,400);
glVertex2f(0,0);
glEnd();

glBegin(GL_POLYGON);                            // field
glColor3f(0.0,1.0,0.0);
glVertex2f(0,200);
glVertex2f(0,230);
glVertex2f(100,300);
glVertex2f(150,320);
glVertex2f(220,350);
glVertex2f(300,310);
glVertex2f(400,300);
glVertex2f(590,325);
glVertex2f(700,315);
glColor3f(0.0,1.0,0.0);
glVertex2f(0,200);
glVertex2f(700,200);
glVertex2f(700,315);
glEnd();


glBegin(GL_POLYGON);                           //river
glColor3f(0.4f,0.4f,1.1f);
glVertex2f(0,0);
glVertex2f(700,0);
glVertex2f(700,100);
glVertex2f(0,100);
glEnd();

glBegin(GL_POLYGON);                          //tree-trunk
glColor3f(1.2f,0.5f,0.4f);
glVertex2f(105,205);
glVertex2f(113,205);
glVertex2f(113,235);
glVertex2f(105,235);
glEnd();

glBegin(GL_POLYGON);                           //tree
glColor3f(0.0f, 0.5f, 0.5f);
glVertex2f(90,220);
glVertex2f(115,260);
glVertex2f(130,220);
glEnd();



glBegin(GL_POLYGON);          //1st house
glColor3f(0.0f, 0.5f, 0.5f);
glVertex2f(200,227);
glVertex2f(270,227);
glVertex2f(270,270);
glVertex2f(200,270);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.1f, 0.0f, 0.0f);
glVertex2f(200,270);
glVertex2f(235,290);
glVertex2f(270,270);
glEnd();


glBegin(GL_LINE_STRIP);
glColor3f(1.0,1.0,1.0);
glVertex2f(215,227);
glVertex2f(215,250);
glVertex2f(235,250);
glVertex2f(235,227);
glEnd();



glBegin(GL_POLYGON);                           //2nd house
glColor3f(0.0f, 0.5f, 0.5f);
glVertex2f(400,227);
glVertex2f(470,227);
glVertex2f(470,270);
glVertex2f(400,270);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.1f, 0.0f, 0.0f);
glVertex2f(400,270);
glVertex2f(435,290);
glVertex2f(470,270);
glEnd();


glBegin(GL_LINE_STRIP);
glColor3f(1.0,1.0,1.0);
glVertex2f(415,227);
glVertex2f(415,250);
glVertex2f(435,250);
glVertex2f(435,227);
glEnd();



glBegin(GL_POLYGON);                       //2nd tree-trunk
glColor3f(1.2f,0.5f,0.4f);
glVertex2f(505,205);
glVertex2f(513,205);
glVertex2f(513,235);
glVertex2f(505,235);
glEnd();

glBegin(GL_POLYGON);                       //2nd tree
glColor3f(0.0f, 0.5f, 0.5f);
glVertex2f(490,220);
glVertex2f(515,260);
glVertex2f(530,220);
glEnd();



glPopMatrix();
}





void road()                            //function to draw road
{
glPushMatrix();
  glBegin(GL_POLYGON);
glColor3f(0.0f,0.0f,0.0f);   
   glVertex2f(0,100);
  glVertex2f(790,100);
  glVertex2f(790,200);
  glVertex2f(0,200);
  glEnd();

 glBegin(GL_LINES);                       //func to draws lane
  glColor3f(1.0,1.0,1.0);
  glPointSize(12.0);
 glVertex2f(-10,150);
 glVertex2f(30,150);
  glEnd();
 glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glPointSize(12.0);
 glVertex2f(40,150);
 glVertex2f(120,150);
  glEnd();
 glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glPointSize(12.0);
 glVertex2f(130,150);
 glVertex2f(230,150);
  glEnd();
 glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glPointSize(12.0);
 glVertex2f(240,150);
 glVertex2f(340,150);
  glEnd();
 glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glPointSize(12.0);
 glVertex2f(350,150);
 glVertex2f(450,150);
  glEnd();
 glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glPointSize(12.0);
 glVertex2f(460,150);
 glVertex2f(560,150);
  glEnd();

 glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glPointSize(12.0);
 glVertex2f(570,150);
 glVertex2f(670,150);
  glEnd();
 glBegin(GL_LINES);
  glColor3f(1.0,1.0,1.0);
  glPointSize(12.0);
 glVertex2f(680,150);
 glVertex2f(770,150);
  glEnd();
 glPopMatrix();



}


void Keyboard(unsigned char Key,int x,int y)
{
switch(Key)
  { 
   case 'c':
     carStatus==1;
     break;
   case 'r':
     carStatus==0;
     break;
   
   default:
     break;
  }
}

void car()
{
 	if(carStatus==1)
    {
        carX += .05;
    }
      if(carX>1000)
    {
       carX = -600;
    }
glPushMatrix();
glTranslatef(carX,carY,0.0);         //function use to move the car
drawcar();
glPopMatrix();
}

void display(void)
{

 glClear(GL_COLOR_BUFFER_BIT);     //clear the screen.
scenery();
road();                         // use to call functions
car();
  glFlush();
glutPostRedisplay();
  glutSwapBuffers();

}



int main(int argc, char **argv)               //main method
{
    glutInit(&argc,argv);                       // to initialize the toolkit;
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  // sets the display mode
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);        // sets the starting position for the window
    glutCreateWindow("Car Moving");     //open the screen window                   
glutKeyboardFunc(Keyboard);               
    glutDisplayFunc(display);             //register the draw function
   initOpenGl();                      //call initOpenGL() method 
    glutMainLoop();
    
}



/*run 
g++ anim.cpp  -lGL -lGLU -lglut

./a.out
*/
