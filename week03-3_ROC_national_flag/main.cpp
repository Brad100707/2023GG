#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
void rect(float x1, float y1, float x2, float y2)
{
    glBegin(GL_POLYGON);
        glVertex2f(x1,y1); glVertex2f(x1,y2); glVertex2f(x2,y2); glVertex2f(x2, y1);
    glEnd();
}
void circle(float x, float y, float r)
{
    glBegin(GL_POLYGON);
    for(float a=0; a<3.1415926*2; a+=0.01){
        glVertex2f(x+r*cos(a), y+r*sin(a));
    }
    glEnd();
}
float pinX[12], pinY[12], baseX[12], baseY[12];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,0,0); rect(-0.9, -0.6, +0.9, +0.6);
    glColor3f(0,0,1); rect(-0.9, +0.6, 0, 0);
    glColor3f(1,1,1);
    for(int i=0; i<12; i++){
        float angle = 2*3.1415926*i/12;
        pinX[i] = -0.45+cos(angle)*0.9/4;
        pinY[i] = 0.30+sin(angle)*0.9/4;
        baseX[i] = -0.45+cos(angle-0.2618)*0.9/8*(1+2.0/15);
        baseY[i] = 0.30 + sin(angle-0.2618)*0.9/8*(1+2.0/15);
    }
    for(int i=0; i<12; i++){
        glBegin(GL_POLYGON);
        glVertex2f(baseX[i], baseY[i]);
        glVertex2f(pinX[i], pinY[i]);
        glVertex2f(baseX[(i+1)%12], baseY[(i+1)%12]);
        glEnd();
    }
    glColor3f(0,0,1); circle(-0.45, +0.3, 0.9/8*(1+2.0/15));
    glColor3f(1,1,1); circle(-0.45, +0.3, 0.9/8);

    glutSwapBuffers();
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("week03");
    glutDisplayFunc(display);
    glutMainLoop();
}
