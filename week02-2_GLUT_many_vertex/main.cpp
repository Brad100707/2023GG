///Week02-2GLUT_many_vertex
#include <GL/glut.h>
void myVertex(float x, float y)
{
    glVertex2f( (x-100)/100.0, -(y-100)/100.0 );
}
void display()
{
    glColor3f(247/255.0, 247/255.0, 247/255.0);
    glBegin(GL_POLYGON);
        glVertex2f( 1, 1);
        glVertex2f(-1, 1);
        glVertex2f(-1,-1);
        glVertex2f( 1,-1);
    glEnd();

    glColor3f(244/255.0, 209/255.0, 33/255.0);
    glBegin(GL_POLYGON);
        myVertex(45,134); ///glVertex2f( (45-100)/100.0, -(134-100)/100.0 );
        myVertex(36,171); ///glVertex2f( (36-100)/100.0, -(171-100)/100.0 );
        myVertex(108,179); ///glVertex2f( (108-100)/100.0, -(179-100)/100.0 );
        myVertex(104,117); ///glVertex2f( (104-100)/100.0, -(117-100)/100.0 );
        ///口訣:減一半、除一半、y變負號
    glEnd();

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
