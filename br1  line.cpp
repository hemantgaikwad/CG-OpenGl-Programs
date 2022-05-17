#include <iostream> 
#include <GL/gl.h> 
#include <GL/glut.h> 
#include <stdio.h> 
int x1,y1,x2,y2;
#define w 500 
#define h 500 
void myInit() 
{ 
glClear(GL_COLOR_BUFFER_BIT); 
glClearColor(0.0, 0.0, 0.0, 1.0); 
glMatrixMode(GL_PROJECTION); 
gluOrtho2D(-w/2,w/2,-h/2,h/2); 
} 
void draw_pixel(int x, int y) 
{ 
glBegin(GL_POINTS); 
glVertex2i(x, y); 
glEnd(); 
} 
void dotted () 
{ 
int x1, x2, y1, y2; 
int dx, dy, i, e; 
int incx, incy, inc1, inc2; 
int x,y,length; 
dx = x2-x1; 
dy = y2-y1; 
if (dx < 0) dx = -dx; 
if (dy < 0) dy = -dy; 
incx = 1; 
if (x2 < x1) incx = -1; 
incy = 1; 
if (y2 < y1) incy = -1; 
x = x1; y = y1;
if (dx > dy) 
{ 
draw_pixel(x, y); 
e = 2 * dy-dx; 
inc1 = 2*(dy-dx); 
inc2 = 2*dy; 
for (i=0; i<dx; i++) 
{ 
if (e >= 0) 
{ 
y += incy; 
e += inc1; 
} 
else 
e += inc2; 
x += incx; 
draw_pixel(x, y); 
} 
} 
else 
{ 
draw_pixel(x, y); 
e = 2*dx-dy; 
inc1 = 2*(dx-dy); 
inc2 = 2*dx; 
for (i=0; i<dy; i++) 
{ 
if (e >= 0) 
{ 
x += incx; 
e += inc1; 
} 
else 
e += inc2; 
y += incy; 
draw_pixel(x, y); 
} 
} 
while(i<=length)
{ 
if(i%5==0) 
{ 
glBegin(GL_POINTS); 
draw_pixel(x,y); 
glEnd(); 
} 
x2=x1+incx; 
y2=y1+incy; 
i=i+1; 
} 
} 
void dashed () 
{ 
int x1,x2,y1,y2; 
int dx, dy, i, e; 
int incx, incy, inc1, inc2; 
int x,y,length; 
length=x || length =y; 
dx = x2-x1; 
dy = y2-y1; 
if (dx < 0) dx = -dx; 
if (dy < 0) dy = -dy; 
incx = 1; 
if (x2 < x1) incx = -1; 
incy = 1; 
if (y2 < y1) incy = -1; 
x= x1; y = y1; 
if (dx > dy) 
{ 
draw_pixel(x, y); 
e = 2 * dy-dx; 
inc1 = 2*(dy-dx); 
inc2 = 2*dy; 
for (i=0; i<dx; i++) 
{ 
if (e >= 0) 
{ 
y += incy; 
e += inc1;
} 
else 
e += inc2; 
x += incx; 
draw_pixel(x, y); 
} 
} 
else 
{ 
draw_pixel(x, y); 
e = 2*dx-dy; 
inc1 = 2*(dx-dy); 
inc2 = 2*dx; 
for (i=0; i<dy; i++) 
{ 
if (e >= 0) 
{ 
x += incx; 
e += inc1; 
} 
else 
e += inc2; 
y += incy; 
draw_pixel(x, y); 
} 
} 
while(i<=length) 
{ 
if(i%15==0) 
{ 
glBegin(GL_POINTS); 
draw_pixel(x,y); 
glEnd(); 
} 
x2=x1+incx; 
y2=y1+incy; 
i=i+1; 
}
} 
void myDisplay() 
{ 
glClear(GL_COLOR_BUFFER_BIT); 
glColor3f(1.0f,0.0f,0.0f); 
glFlush(); 
} 
void menu(int item) 
{ 
std::cout<<"|-|-|-|-|-You clicked item : "<<item<<" -|-|-|-|-|"; if(item==1) 
{ 
dotted(); 
} 
if(item==2) 
{ 
dashed(); 
} 
if(item==3) 
{ 
exit(0); 
} 
} 
int main(int argc, char **argv) 
{ 
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); glutInitWindowSize(500, 500); 
glutInitWindowPosition(500,500); 
glutCreateWindow("Bresenham's Line Drawing"); myInit(); 
glutCreateMenu(menu); 
glutAddMenuEntry("Dotted Line",1); 
glutAddMenuEntry("Dashed Line",2); 
glutAddMenuEntry("Exit",3); 
glutAttachMenu(GLUT_RIGHT_BUTTON); 
glutMainLoop(); 
glutDisplayFunc(myDisplay);
glutMainLoop(); 
return 0; 
} 

/* run 
g++ 'br1  line.cpp'       -lGL -lGLU -lglut
 
 alg br
 Step1: Start Algorithm

Step2: Declare variable x1,x2,y1,y2,d,i1,i2,dx,dy

Step3: Enter value of x1,y1,x2,y2
                Where x1,y1are coordinates of starting point
                And x2,y2 are coordinates of Ending point

Step4: Calculate dx = x2-x1
                Calculate dy = y2-y1
                Calculate i1=2*dy
                Calculate i2=2*(dy-dx)
                Calculate d=i1-dx

Step5: Consider (x, y) as starting point and xendas maximum possible value of x.
                If dx < 0
                        Then x = x2
                        y = y2
                          xend=x1
                If dx > 0
                    Then x = x1
                y = y1
                        xend=x2

Step6: Generate point at (x,y)coordinates.

Step7: Check if whole line is generated.
                If x > = xend
                Stop.

Step8: Calculate co-ordinates of the next pixel
                If d < 0
                    Then d = d + i1
                If d ≥ 0
          Then d = d + i2
                Increment y = y + 1

Step9: Increment x = x + 1

Step10: Draw a point of latest (x, y) coordinates

Step11: Go to step 7

Step12: End of Algorithm

Example: Starting and Ending position of the line are (1, 1) and (8, 5). Find intermediate points.

Solution: x1=1
                y1=1
                x2=8
                y2=5
                dx= x2-x1=8-1=7
                dy=y2-y1=5-1=4
                I1=2* ∆y=2*4=8
                I2=2*(∆y-∆x)=2*(4-7)=-6
                d = I1-∆x=8-7=1 
                */
