///Week04-3_rotate_translate 程式copy來自 week04-1_rotate
///Step03-2
#include <GL/glut.h>
float angle = 0; ///step02-1 宣告global全域變數 angle
void display()
{
    glEnable(GL_DEPTH_TEST);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景
    glPushMatrix(); ///step02-1 備份矩陣
        glTranslatef(0.6, 0, 0);///step03-2
        glRotatef(angle, 0, 1, 0); ///step02-1 旋轉 angle 角度
        glColor3f(1,1,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();  ///step02-1 還原矩陣
    glPushMatrix(); ///step02-1 備份矩陣
        glRotatef(angle, 0, 1, 0); ///step02-1 旋轉 angle 角度
        glTranslatef(0.6, 0, 0);///step03-2
        glColor3f(1,0,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();  ///step02-1 還原矩陣
    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///step02-1 有空idle時,就重畫畫面
    glutMainLoop();
}
