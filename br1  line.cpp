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

