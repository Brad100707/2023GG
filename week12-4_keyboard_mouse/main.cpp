///week12-4_keyboard_mouse 要用 keyboard mouse 來操控茶壼, 而且可存檔、會自己動
///在按mosue時,除了改 teapotX, teapotY 座標, 並重畫, 還要再存座標
///存檔時,會在工作執行目錄 working_dir
///在CodeBlocks Project-Properties 裡面的第二個Build targets 下面可以設定
///把它從 C:\Users\Administrator\Desktop\freeglut\bin 改成 . (小數點,現在目錄的意思)
/// 記得, Debug 和 Release 兩個都要改
/// 而且要 File-Save Everything (Ctrl-Shift-S全部存檔)才會將 .cbp 專案檔存檔
#include <stdio.h>
#include <GL/glut.h>
FILE * fout = NULL; ///step02-2 一開始,檔案沒有開, NULL
FILE * fin = NULL; ///step02-2 要讀檔用的指標, 一開始也是 NULL
float teapotX=0, teapotY=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        if(fout==NULL) fout = fopen("file4.txt", "w"); ///step02-2 沒開檔,就開
        fprintf(fout, "%f %f\n", teapotX, teapotY); ///step02-2 要再存座標
    }
    display();
}
void keyboard(unsigned char key, int x, int y) ///step02-2 keyboard函式
{
    if(fin==NULL){ ///step02-2 如果檔案還沒 fopen(), 就開它
        fclose(fout); ///前面mouse會開fout指標, 所以要關掉
        fin = fopen("file4.txt", "r"); ///step02-2 沒開檔,就開
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY); ///step02-2 真的讀檔
    display(); ///step02-2 重畫畫面
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard); ///step02-2 keyboard要做事囉(開檔、讀檔)

    glutMainLoop();
}
