///Week06-1_TRT_robot2 貼上上週的week05-2_TRT_robot
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSolidSphere(0.02, 30, 30); ///正中心的圓球

    glPushMatrix();
        glTranslatef(-0.5, 0.5, 0);     ///(3) 掛上去
        glRotatef(angle, 0, 0, 1);      ///(2) 就可以轉動了
        glTranslatef( 0.46, -0.05, 0 ); ///(1) 把轉動的中心,放中心
        glutSolidTeapot(0.3);
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
