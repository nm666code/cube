#include <GL/glut.h>
#include<iostream>
using namespace std;

const float vertexs[][3] = { {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 1.0},
                             {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0} };

void myinit(void)
{
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(20.0f, 1.0, 1.0f, 15.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);

    glEnable(GL_DEPTH_TEST);
}

void drawPoly(int v1,int v2, int v3, int v4) 
{
    glBegin(GL_POLYGON);
    glColor3f(vertexs[v1][0], vertexs[v1][1], vertexs[v1][2]);
    glVertex3f(vertexs[v1][0], vertexs[v1][1], vertexs[v1][2]);
    glColor3f(vertexs[v2][0], vertexs[v2][1], vertexs[v2][2]);
    glVertex3f(vertexs[v2][0], vertexs[v2][1], vertexs[v2][2]);
    glColor3f(vertexs[v3][0], vertexs[v3][1], vertexs[v3][2]);
    glVertex3f(vertexs[v3][0], vertexs[v3][1], vertexs[v3][2]);
    glColor3f(vertexs[v4][0], vertexs[v4][1], vertexs[v4][2]);
    glVertex3f(vertexs[v4][0], vertexs[v4][1], vertexs[v4][2]);
    glEnd();
}

void drawcube()
{
    drawPoly(0, 1, 5, 4);
    drawPoly(0, 2, 3, 1);
    drawPoly(0, 2, 6, 4);
    drawPoly(1, 3, 7, 5);
    drawPoly(2, 6, 7, 3);
    drawPoly(4, 5, 7, 6);
}


void drawAxis()
{
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(3.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 3.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 3.0);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2, 0.2, 0.2, 1.0);
    drawAxis();
    drawcube();
    glutSwapBuffers();
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(512, 512);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("U10916025");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}