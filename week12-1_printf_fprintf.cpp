///Week12-1_printf_fprintf.cpp
/// 要能夠寫檔案
#include <stdio.h>

int main()
{///檔案指標 fout = 開檔案("檔名", "用什麼模式")
    FILE * fout = fopen("file.txt", "w");///w:write

    printf("Hello World\n");
    fprintf(fout, "Hello World在檔案裡\n");

}
