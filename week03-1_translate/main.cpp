///程式碼全刪,換我們上週教的10行
#include <GL/glut.h>
float X=0, Y=0;///step02-2 利用 global 變數,在函式之間傳值 (大寫的)
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///step02-2 清背景
    glPushMatrix(); ///step01-2 備份矩陣
        glTranslatef( X, Y, 0 ); ///step01-2 只有這行?還不夠
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///step01-2 還原矩陣

    glutSwapBuffers();
}
///#include <stdio.h> ///step02-1 為了 printf()
void mouse(int button, int state, int x, int y) ///小寫的
{ ///step02-1 請 mouse函式幫忙
    X = (x-150)/150.0; ///printf("%d %d %d %d\n", button, state, x, y);
    Y = -(y-150)/150.0; ///step02-2 口訣: 減一半、除一半, y負號
}///step02-1 印出來 printf()
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutMouseFunc(mouse); ///step02-1 請 mouse函式幫忙

    glutMainLoop();
}
