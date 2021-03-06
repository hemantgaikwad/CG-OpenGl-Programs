#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#define w 640               // setting width 
#define h 480               // setting heigth 
using namespace std;

int x1,y2,yf,xx,yy,choice;
float boudaryColor[3]={0,0,0},interiorColor[3]={1,1,1},fillColor[3]={0,0,0}; float 
readPixel[3];                                                                        
void setPixel(int x, int y)                  // setting pixel function 
{
glColor3fv(fillColor);                      // sets tje current color from already existing valuse of color 
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
glFlush();
}
void getPixe(int x ,int y, float *color)
{
glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color);
}
int sing(float arg)
{
if(arg<0) return -1;
else if(arg==0) return 0;
else return 1;
}
void Line(int X1, int Y1 , int X2,int Y2)     //line drawing algo 
{
float x,y,Dx,Dy,s1,s2,interchange,e,temp;
x=X1,y=Y1;             //initialize variable 
Dx=abs(X2-X1);
Dy=abs(Y2-Y1);
s1=sing(X2-X1);
s2=sing(Y2-Y1);
if(Dy>Dx)              //decide interchange
{
temp=Dx;
Dx=temp;
interchange=1;
}
else interchange=0;
e=(2*Dy)-Dx;
glBegin(GL_POINTS);
for(int i=1; i<Dx;i++)    // Loop for Bresenhams alg
{
glVertex2f(x,y);
while(e>=0)
{
if(interchange==1)
x=x+s1;
else y=y+s2;
e=e-(2*Dx);
}
if(interchange==1)
y=y+s2;
else 
x=x+s1;
e=e+(2*Dy);
}
glVertex2f(x,y);
glEnd();
glFlush();
}
void display()       //Display Function 
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0,1.0,0.0);
glLoadIdentity();
gluOrtho2D(0,640,0,480);
glClear(GL_COLOR_BUFFER_BIT);
Line(100,100,150,300);
Line(150,300,200,100);
Line(200,100,100,100);
}
void floodFill(int x ,int y)      //flood fill algo
{
getPixe(x,y,readPixel);
if(readPixel[0]==interiorColor[0]&&readPixel[1]==interiorColor[1]&&readPixel[2]==interiorColor[2])
{
setPixel(x,y);
floodFill(x+1,y);     // four way filling method
floodFill(x,y+1);
floodFill(x-1,y);
floodFill(x,y-1);
glFlush();
}
}
void boundaryFill(int x, int y)    // boundary filling alg
{
getPixe(x,y,readPixel);
if(readPixel[0]!=boudaryColor[0] && readPixel[1]!=boudaryColor[1]&& readPixel[2]!=boudaryColor[2])
{
setPixel(x,y);
boundaryFill(x+1,y);
boundaryFill(x,y+1);
boundaryFill(x-1,y);
boundaryFill(x,y-1);
glFlush();
}
}
void mouse(int btn,int state,int x,int y)    //Mouse function
{
if((btn==GLUT_LEFT_BUTTON)&&(state==GLUT_DOWN))
{
x1=x;
y2=480-y;
if(choice==1)boundaryFill(x1,y2);
else if(choice==2)floodFill(x1,y2);
}
}
void menu(int item)
{
if(item==1)                    //boundary fill 
{
choice=1;
fillColor[0]=0;
fillColor[1]=1;
fillColor[2]=1;
}
else if(item==2)
{
choice=2;                //flood fill
fillColor[0]=0.2;
fillColor[1]=0;
fillColor[2]=0.7;
}
else if(item==3)exit(0);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(w,h);
 glutCreateWindow("Boundary Fill Algorithm"); glutCreateMenu(menu);
 
glutAddMenuEntry("Boundary Fill",1);
glutAddMenuEntry("Flood Fill",2);
glutAddMenuEntry("Exit",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutDisplayFunc(display);
glutMouseFunc(mouse);
glutMainLoop();
return 0;
}



/*run 
g++ 'poly f.cpp'       -lGL -lGLU -lglut

alg 

    Procedure fill (x, y, color, color1: integer)  
    int c;  
    c=getpixel (x, y);  
    if (c!=color) (c!=color1)  
    {  
        setpixel (x, y, color)  
        fill (x+1, y, color, color 1);  
         fill (x-1, y, color, color 1);  
        fill (x, y+1, color, color 1);  
        fill (x, y-1, color, color 1);  
    }  
    */



 
