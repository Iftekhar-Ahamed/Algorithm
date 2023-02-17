#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


int X1 = 2, Y1 = 2, X2 = 8, Y2 = 5;
void midPoint(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glEnd();
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);


    int dx = X2 - X1;
    int dy = Y2 - Y1;

    if(dy<=dx) //m<=0
    {
        int d = dy - (dx/2);
        int x = X1, y = Y1;
        cout << x << "," << y << "\n";
        glVertex3f(x/100,y/100,0.0);

        while (x < X2)
        {
            x++;

            if (d < 0)
                d = d + dy;

            else
            {
                d = d+(dy - dx);
                y++;
            }
            glVertex3f(x/100,y/100,0.0);
            cout << x << "," << y << "\n";
        }
    }

    else if(dx<dy) //m>1
    {
        int d = dx - (dy/2);
        int x = X1, y = Y1;
        cout << x << "," << y << "\n";

        while (y < Y2)
        {
            y++;

            if (d < 0)
                d = d + dx;

            else
            {
                d = d+(dx - dy);
                x++;
            }
            glVertex3f(x/100,y/100,0.0);
            cout << x << "," << y << "\n";
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
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Mid Point");
    init ();
    glutDisplayFunc(midPoint);
    glutMainLoop();
    return 0;
}
