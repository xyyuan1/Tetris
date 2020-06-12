#include<others.h>
#include<draw.h>
void draw::background_draw(HANDLE hOut) //绘制背景  双人对战 
{
    SetConsoleTitle("我罗斯方块");//控制台名称 
    COORD size = { 100, 25 };//控制台屏幕缓冲区大小
    SetConsoleScreenBufferSize(hOut, size);
    SMALL_RECT rc = { 0, 0, 99, 24 };//矩形左上角，右下角坐标 
    SetConsoleWindowInfo(hOut, true, &rc);
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//隐藏光标
    SetConsoleCursorInfo(hOut, &cursor_info);
}
void draw::foreground_draw(HANDLE hOut)
{
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < 20; ++i)
    {
        cout << "■                    ■○                      ○■                    ■" << endl;
    }
    gotoXY(hOut, 26, 0);
    cout << "○○○○○○○○○○○";
    gotoXY(hOut, 0, 20);
    cout << "■■■■■■■■■■■■○○○○○○○○○○○○○■■■■■■■■■■■■";
    gotoXY(hOut, 26, 4);
    cout << "下一方块：";
    gotoXY(hOut, 36, 4);
    cout << "下一方块：";
    gotoXY(hOut, 26, 10);
    cout << "操作方法：";
    gotoXY(hOut, 29, 11);
    cout << "W ：旋转 ↑：旋转";
    gotoXY(hOut, 29, 12);
    cout << "D ：右移 →：右移";
    gotoXY(hOut, 29, 13);
    cout << "A ：左移 ←：左移";
    gotoXY(hOut, 29, 14);
    cout << "S ：速降 ↓：速降";
    gotoXY(hOut, 29, 15);
    cout << "空格键：暂停";
}
