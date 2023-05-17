///Week11-3_PlaySound.cpp 可是它卻不能執行 因為找不到 PlaySoundA
///C:\Users\Administrator\Desktop\week11-3_PlaySound.o:week11-3_PlaySound.cpp:(.text+0x2e):
///  undefined reference to `PlaySoundA@12'
///PlaySoundA() 其實在 winmm 裡面 所以, step02-1 要手動把 winmm 加到 lib 咒語裡
/// 比較: OpenCV 要 3咒語, GLUT 要 5咒語。 PlaySound 要 1咒語
/// Setting-Compiler... 的 Linker Settings 要加上 winmm
#include <windows.h>
int main()
{                         ///要等待同步 SND_SYNC, 不然會瞬間結束
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\do.wav", NULL, SND_SYNC);
    PlaySound("do_re_mi\\re.wav", NULL, SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\mi.wav", NULL, SND_SYNC);
}
///Build log 會寫: Checking for existence: C:\Users\Administrator\Desktop\week11-3_PlaySound.exe
///Executing: '"C:\Program Files (x86)\CodeBlocks/cb_console_runner.exe" "C:\Users\Administrator\Desktop\week11-3_PlaySound.exe"' (in 'C:\Users\Administrator\Desktop')
/// 它的執行目錄, 是在 C:\Users\Administrator\Desktop 我們的 do.wav re.wav mi.wav 在 相對目錄裡
