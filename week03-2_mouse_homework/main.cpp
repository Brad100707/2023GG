#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot( 0.3 );
    glBegin(GL_POLYGON);
    glVertex2f(-0.268, 0.160);
    glVertex2f(-0.304, 0.204);
    glVertex2f(-0.332, 0.264);
    glVertex2f(-0.352, 0.384);
    glVertex2f(-0.344, 0.484);
    glVertex2f(-0.308, 0.532);
    glVertex2f(-0.236, 0.552);
    glVertex2f(-0.204, 0.496);
    glVertex2f(-0.204, 0.404);
    glVertex2f(-0.204, 0.348);
    glVertex2f(-0.180, 0.280);
    glVertex2f(-0.156, 0.228);
    glVertex2f(-0.156, 0.212);
    glVertex2f(-0.152, 0.188);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.040, 0.200);
    glVertex2f(0.032, 0.248);
    glVertex2f(0.028, 0.328);
    glVertex2f(0.028, 0.404);
    glVertex2f(0.040, 0.480);
    glVertex2f(0.064, 0.540);
    glVertex2f(0.096, 0.572);
    glVertex2f(0.152, 0.616);
    glVertex2f(0.208, 0.604);
    glVertex2f(0.260, 0.524);
    glVertex2f(0.240, 0.468);
    glVertex2f(0.192, 0.428);
    glVertex2f(0.164, 0.384);
    glVertex2f(0.152, 0.328);
    glVertex2f(0.148, 0.276);
    glVertex2f(0.148, 0.244);
    glVertex2f(0.140, 0.212);
    glVertex2f(0.140, 0.188);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-0.196, 0.044);
    glVertex2f(-0.188, 0.068);
    glVertex2f(-0.112, 0.096);
    glVertex2f(-0.060, 0.096);
    glVertex2f(-0.048, 0.068);
    glVertex2f(-0.088, 0.048);
    glVertex2f(-0.140, 0.032);
    glVertex2f(-0.188, 0.032);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.212, 0.152);
    glVertex2f(-0.256, 0.116);
    glVertex2f(-0.272, 0.064);
    glVertex2f(-0.300, -0.084);
    glVertex2f(-0.292, -0.140);
    glVertex2f(-0.220, -0.224);
    glVertex2f(-0.124, -0.252);
    glVertex2f(0.080, -0.260);
    glVertex2f(0.156, -0.256);
    glVertex2f(0.224, -0.224);
    glVertex2f(0.264, -0.160);
    glVertex2f(0.288, -0.152);
    glVertex2f(0.284, 0.004);
    glVertex2f(0.256, 0.092);
    glVertex2f(0.232, 0.164);
    glVertex2f(0.068, 0.180);
    glVertex2f(0.000, 0.192);
    glVertex2f(-0.144, 0.176);
    glEnd();

    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y) ///小寫的
{
    float X = (x-250)/250.0;
    float Y = -(y-250)/250.0; ///口訣: 減一半、除一半, y負號
    if(state==GLUT_DOWN){  ///只有按下mouse,才印出程式,等下要剪貼!
        printf("    glVertex2f(%.3f, %.3f);\n", X, Y);
    }
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///step02-1 請 mouse函式幫忙

    glutMainLoop();
}
