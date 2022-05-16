#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#define w 700 
#define h 700
using namespace std;
int r, xc,yc;
void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0f,0.0f,0.0f);
glPointSize(4.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-w/2,w/2,-h/2,h/2);       //defining axis 
}
void setPixel(int x,int y)          //setting axes
{
glColor3f(0.3f,0.3f,0.3f);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void Plot(int x , int y)
{
setPixel(xc+x,yc+y);       //8 way apporach
setPixel(xc-y,yc+y);
setPixel(xc+x,yc-y);
setPixel(xc-x, yc-y);
setPixel(xc+y,yc+x);
setPixel(xc-y,yc+x);
setPixel(xc+y,yc-x);
setPixel(xc-y,yc-x);
}
void DrawCircle()            // to draw simple circle
{
int x =0;
int y = r;
int d = 3-(2*r);
while (x <=y)
{
if (d <=0)
{
d=d+(4*x)+6;
x +=1;
}
else 
{
d = d + 4*(x-y)+10;
x += 1;
y -=1;
}
Plot(x,y);
}
}
void concentric()
{                             //to drawing concentric circle 
DrawCircle();
r=r*(0.7);
DrawCircle();                  // for drawing radius for inner circle
}
void Olympic()                 // fopr drawing olympic logo 
{
glClear(GL_COLOR_BUFFER_BIT);
r = 100 ,xc =-205 , yc =100;
int xin, yin;
DrawCircle();
xin = xc,yin =yc;
xc += 2*r + 10;
DrawCircle();
xc += 2*r + 10;
DrawCircle();
yc =yin -r -10;
xc =xin +r;
DrawCircle();
xc +=2*r+10;
DrawCircle();
}
void PlotSpiral(int i, int x, int y)     //for poltting point of spiral
{
if(i % 2 ==0)
{
setPixel(xc+x,yc+y);
setPixel(xc-x,yc+y);
setPixel(xc+y,yc+x);
setPixel(xc-y,yc+x);
}
else 
{
setPixel(xc+x,yc-y);
setPixel(xc-x,yc-y);
setPixel(xc+y, yc-x);
setPixel(xc-y, yc-x);
}
}
void Drawsemi(int i)
{
int x = 0;
int y = r;
int d = 3-(2*r);
while (x <=y)
{
if (d <=0)
{
d =d +(4*x)+6;
x += 1;
}
else 
{
d = d+4*(x-y)+10;
x += 1;
y -= 1;
}
PlotSpiral(i,x,y);
}
}
void Spiral()      // to draw spiral 
{
int i;
r = 100;
int prevr = r;
int n = 20;
for (i = 0; i < n; i++)       // number of turns
{
Drawsemi(i);
xc += (i % 2 == 0 ? -r : r);
r += 10;
xc += (i % 2 == 0 ? r : -r);
}
}
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
for (int i = -w; i < w; i++)
{
setPixel(i, 0);
setPixel(0, i);               // to drawing axes
}
glFlush();
}
void Menu(int option)       // Menu creation 
{
if (option == 1)
DrawCircle();
else if (option == 2)
concentric();
else if (option == 3)
{
Olympic();
}
else if (option == 4 )
{
Spiral();
}
else if (option == 5)
{
exit(0);
}
}
int main(int argc, char **argv)
{
cout<<"Enter Radius:- ";
cin>>r;
cout<<"Enter Centre Coordinates :- ";
cin>> xc >>yc;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(100,150);
glutInitWindowSize(w,h);
glutCreateWindow("Circle");
glutDisplayFunc(myDisplay);
glutCreateMenu(Menu);
glutAddMenuEntry("circle",1);
glutAddMenuEntry("Concentric Circles" ,2);
glutAddMenuEntry("Olympic Logo" , 3);
glutAddMenuEntry("Spiral" , 4);
glutAddMenuEntry("Exit",5);
glutAttachMenu(GLUT_RIGHT_BUTTON);         // Using mouse right button 
myInit();
glutMainLoop();
return 0;
}



/* Algo 
Step1: Start Algorithm

Step2: Declare p, q, x, y, r, d variables
        p, q are coordinates of the center of the circle
        r is the radius of the circle

Step3: Enter the value of r

Step4: Calculate d = 3 - 2r

Step5: Initialize       x=0
          &nbsy= r

Step6: Check if the whole circle is scan converted
            If x > = y
            Stop

Step7: Plot eight points by using concepts of eight-way symmetry. The center is at (p, q). Current active pixel is (x, y).
                putpixel (x+p, y+q)
                putpixel (y+p, x+q)
                putpixel (-y+p, x+q)
                putpixel (-x+p, y+q)
                putpixel (-x+p, -y+q)
                putpixel (-y+p, -x+q)
                putpixel (y+p, -x+q)
                putpixel (x+p, -y-q)

Step8: Find location of next pixels to be scanned
            If d < 0
            then d = d + 4x + 6
            increment x = x + 1
            If d ≥ 0
            then d = d + 4 (x - y) + 10
            increment x = x + 1
            decrement y = y - 1

Step9: Go to step 6

Step10: Stop Algorithm

Example: Plot 6 points of circle using Bresenham Algorithm. When radius of circle is 10 units. The circle has centre (50, 50).

Solution: Let r = 10 (Given)

Step1: Take initial point (0, 10)
                d = 3 - 2r
                d = 3 - 2 * 10 = -17
                d < 0 ∴ d = d + 4x + 6
                      = -17 + 4 (0) + 6
                      = -11

Step2: Plot (1, 10)
          d = d + 4x + 6 (∵ d < 0)
                = -11 + 4 (1) + 6
                = -1

Step3: Plot (2, 10)
           d = d + 4x + 6 (∵ d < 0)
                = -1 + 4 x 2 + 6
                = 13

Step4: Plot (3, 9) d is > 0 so x = x + 1, y = y - 1
                          d = d + 4 (x-y) + 10 (∵ d > 0)
                = 13 + 4 (3-9) + 10
                = 13 + 4 (-6) + 10
                = 23-24=-1

Step5: Plot (4, 9)
            d = -1 + 4x + 6
                = -1 + 4 (4) + 6
                = 21

Step6: Plot (5, 8)
            d = d + 4 (x-y) + 10 (∵ d > 0)
                = 21 + 4 (5-8) + 10
                = 21-12 + 10 = 19

So P1 (0,0)⟹(50,50)
            P2 (1,10)⟹(51,60)
            P3 (2,10)⟹(52,60)
            P4 (3,9)⟹(53,59)
            P5 (4,9)⟹(54,59)
            P6 (5,8)⟹(55,58)
*/


