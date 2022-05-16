
#include<GL/glut.h>
#include<GL/glu.h>
#include<iostream>
#include<math.h>
#define w 1000
#define h 1000
using namespace std;
float xstart,ystart,xend,yend;
void setPixel(int x,int y)
{
glColor3f(0.0,0.0,0.0);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void simple_line(float a,float b, float c, float d){
float x,y,dx,dy,length; //Step 1
float x1 = a;
float x2 = c;
float y1 = b;
float y2 = d;
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx>=dy)
length=dx;
else
length=dy;
dx=(x2-x1)/length;  //Step 2
dy=(y2-y1)/length;
x=x1; 
y=y1;
int i=0;
glBegin(GL_POINTS);
glVertex2f(x,y);
glEnd();
while(i<=length)
{
glBegin(GL_POINTS);
glVertex2f(x,y);
glColor3f(0.0f,1.0f,0.0f);
glEnd();
x=x+dx;
y=y+dy;
i=i+1;
}
}

//dashed line
void DashedLine(){
float length, dx, dy, xinc, yinc,x,y;
cout<<"Enter 1st coordinate"<<endl;
cin>>xstart>>ystart;
cout<<endl;
cout<<"Enter 2nd coordinate"<<endl;
cin>>xend>>yend;
cout<<endl;
dx = xend - xstart;
dy = yend - ystart;
length = abs(dy);
if(abs(dx) > abs(dy))
{
length = abs(dx);
}
xinc = dx/length;
yinc = dy/length;

x = xstart ;
y = ystart ;

int i = 0;

glColor3f(1,0,0);
while(i<=length){
if(i%10>=4)
{
glBegin(GL_POINTS);
glVertex2f(round(x),round(y));
glEnd();
}
x += xinc;
y += yinc;
i++;
}
glFlush();
}

//dotted line

void DottedLine(){
float length, dx, dy, xinc, yinc,x,y;
cout<<"Enter 1st coordinate"<<endl;
cin>>xstart>>ystart;
cout<<endl;
cout<<"Enter 2nd coordinate"<<endl;
cin>>xend>>yend;
cout<<endl;
dx = xend - xstart;
dy = yend - ystart;
length = abs(dy);
if(abs(dx) > abs(dy))
{
length = abs(dx);
}
xinc = dx/length;
yinc = dy/length;
x = xstart ;
y = ystart ;
int i = 0;
glColor3f(1,0,0);
while(i<=length){
if(i%5==0)
{
glBegin(GL_POINTS);
glVertex2f(round(x),round(y));
glEnd();
}
x += xinc;
y += yinc;
i++;
}
glFlush();
}

//simple line

void SimpleLine(){
float length, dx, dy, xinc, yinc,x,y;
cout<<"Enter 1st coordinate"<<endl;
cin>>xstart>>ystart;
cout<<endl;
cout<<"Enter 2nd coordinate"<<endl;
cin>>xend>>yend;
cout<<endl;
dx = xend - xstart;
dy = yend - ystart;
length = abs(dy);
if(abs(dx) > abs(dy))
{
length = abs(dx);
}
xinc = dx/length;
yinc = dy/length;
x = xstart ;
y = ystart ;
int i = 0;
glColor3f(1,0,0);
while(i<=length){
glBegin(GL_POINTS);
glVertex2f(round(x),round(y));
glEnd();
x += xinc;
y += yinc;
i++;
}
glFlush();
}
int sign(float x)
{
if(x>0)
return 1;
else if(x<0)
return -1;
else
return 0;
}
void boat()
{
glColor3f(0.0,0.0,0.0);
simple_line(-300,100,-100,100);
simple_line(-250,35,-150,35);
simple_line(-300,100,-250,35);
simple_line(-100,100,-150,35);
simple_line(-250,100,-200,160);
simple_line(-200,100,-200,160);
}
void Menu(int id){
if(id==1)
{SimpleLine();
}
else if(id==2)
{
DashedLine();
}
else if(id==3)
{
DottedLine();
}
else if(id==4)
{
boat();
}
else
{
exit(0);
}
}
void draw(){

int j = -w;
while(j<=w){
setPixel(j,0);
setPixel(0,j);j++;
}
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitWindowPosition(0,0);
glutInitWindowSize(1200,700);
glutCreateWindow("DDA");
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(-w/2,w/2,-h/2,h/2);
glutDisplayFunc(draw);
glutCreateMenu(Menu);
glutAddMenuEntry("Simple Line", 1);
glutAddMenuEntry("Dashed Line",2);
glutAddMenuEntry("Dotted Line",3);
glutAddMenuEntry("Boat",4);
glutAddMenuEntry("Exit",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glPointSize(2);
glutMainLoop();
return 0;
}





/*OUTPUT ::
Enter 1st coordinate
50
50
Enter 2nd coordinate
400
400
Enter 1st coordinate
-50
-50
Enter 2nd coordinate
-400
-400
Enter 1st coordinate
400
-50
Enter 2nd coordinate
50
-400

Alg of DDA
1 start
2 declere x1,y1,x2,y2,dx,dy,dx,x as int var
3 enter value of x1,y1,x2,y2
4 calculet dx=x2-x1
5 cal dy=y2-y1
6 if abs[(dx)>(dy)] then step =abs (dx) else
7 xinc=dx/step yinc=dy/step assign x=x1 assign y =y1
8 set pixel(x,y)
9 x=x+xinc y=y+yinc set pixel (round (x),round(y))
10 Repeat step 9 unit x=x2
11 end 

run 
g++ 'DDA line.cpp' -lGL -lGLU -lglut
./a.out
*/

