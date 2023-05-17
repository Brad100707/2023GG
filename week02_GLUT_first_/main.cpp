///week02_GLUT_first
#include <GL/glut.h>
void display()
{
    ///glColor3f(0,1,0); ///step01-2 綠色
    ///glutSolidTeapot( 0.5 ); ///step01-2 畫出一個實心的大茶壼, 它的大小 0.5
    glBegin(GL_POLYGON); ///step02-1 開始畫多邊形
        glColor3f(1,0,0);  glVertex2f( 0, 1); ///紅色的頂點 Vertex step02-2
        glColor3f(0,1,0);  glVertex2f(-1,-1); ///綠色的頂點 Vertex step02-2
        glColor3f(0,0,1);  glVertex2f(+1,-1); ///藍色的頂點 Vertex step02-2
    glEnd(); ///step02-1 結束畫

    glColor3f(1,1,0); ///step01-2 黃色
    glutSolidTeapot( 0.3 ); ///step01-1 畫出一個實心的小茶壼, 它的大小 0.3
    glutSwapBuffers(); ///step01-1 請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{ ///step01-1 上面是特別的 main()函式, 有很多參數
    glutInit(&argc, argv); ///step01-1 把 GLUT 開起來
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///上面這行,把顯示的模式設定好!
	glutCreateWindow("GLUT Shapes"); ///step01-1 要開視窗
	glutDisplayFunc(display); ///step01-1 要顯示的對應函式
	glutMainLoop(); ///step01-1 最後用「主要的迴圈」,卡在最後面
}
