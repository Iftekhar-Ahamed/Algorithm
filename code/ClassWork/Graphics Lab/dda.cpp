#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1,y,x2,y2,m,i,j;
float dx,dy;
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    glEnd();

    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);


    if(m>0 && m<=1)
    {
        while(x1<=x2 && y<=y2)
        {
            x1=x1+1;
            y=y+m;
            glVertex3f(x1/100,y/100,0.0);
            printf("%f %f",x1,y);

        }
    }
    else if(m>1)
    {
        while(x1<=x2 && y<=y2)
        {
            x1=x1+(1/m);
            y=y+1;
            glVertex3f(x1/100,y/100,0.0);
            printf("%f %f",x1,y);
        }
    }

    else if(m>-1 && m<=0)
    {
        while(x1>=x2 && y>=y2)
        {
            x1=x1-1;
            y=y-m;
            glVertex3f(x1/100,y/100,0.0);
            printf("%f %f",x1,y);
        }
    }
    else if(m<-1)

    {

        while(x1>=x2 && y>=y2)
        {
            x1=x1-(1/m);
            y=y-1;
            glVertex3f(x1/100,y/100,0.0);
            printf("%f %f",x1,y);
        }
    }

    glEnd();


    glFlush ();
}
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{

    //glVertex3f(x1/100,y/100,0.0);write your code here
    printf("Enter value of X1 :");
    scanf("%f",&x1);
    printf("Enter value of y :");
    scanf("%f",&y);
    printf("Enter value of X2 :");
    scanf("%f",&x2);
    printf("Enter value of Y2 :");
    scanf("%f",&y2);
    dx=x2-x1;
    dy=y2-y;
    m=dy/dx;


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
