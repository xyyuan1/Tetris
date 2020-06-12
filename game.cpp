#include"others.h" 
#include"game.h"
void game::gamestop(HANDLE hOut, int block1[4][4], int block2[4][4], Block& b)//暂停游戏
{
    b.block_delete1(hOut, block1, 5, 15);
    b.block_delete1(hOut, block2, 5, 20);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//字体设置青色
    gotoXY(hOut, 33, 7);
    cout << "Paused！";
    gotoXY(hOut, 38, 9);
    cout << "(空格继续)";
    char select;
    while (1)
    {
        select = _getch();
        if (select == 32)
        {
            gotoXY(hOut, 33, 7);
            cout << "        ";
            gotoXY(hOut, 38, 9);
            cout << "          ";
            b.block_print1(hOut, block1, 5, 15);
            b.block_print1(hOut, block2, 5, 20);
            return;
        }
    }
}
void game::gameover(HANDLE hOut, player& p, Block& b, int block1[4][4], int block2[4][4])  //游戏结束
{
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    b.block_delete1(hOut, block1, 5, 15);
    b.block_delete1(hOut, block2, 5, 20);
	
    gotoXY(hOut, 33, 7);
    cout << "GAME OVER";
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    gotoXY(hOut, 33, 9);
    cout << "ESC退出";
    char key;
    while (1)
    {
        key = _getch();
        if (key == 27)
        {
            exit(0);
        }
    }
}
