#include"game.h"
#include"player.h"
#include"others.h"
Block() { ; }
void Block::block_delete1(HANDLE hOut, int block[4][4], int x1, int y1)//清除方块 
{
    for (int i = 0; i < 4; ++i)
    {
        if (i + x1 >= 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (block[i][j] == 1)
                {
                    gotoXY(hOut, 2 * (y1 + j), x1 + i);
                    cout << "  ";
                }
            }
        }
    }
}
void Block::block_delete2(HANDLE hOut, int block[4][4], int x1, int y1)//清除方块 
{
    for (int i = 0; i < 4; ++i)
    {
        if (i + x1 >= 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (block[i][j] == 1)
                {
                    gotoXY(hOut, 2 * (y1 + j)+50, x1 + i);
                    cout << "  ";
                }
            }
        }
    }
}
void Block::block_print1(HANDLE hOut, int block[4][4], int x1, int y1)//打印p1玩家方块
{
    switch (block[0][0])
    {
    case 10:
    case 11:
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 16:
    case 17:
    case 18:
    case 19:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 20:
    case 21:
    case 22:
    case 23:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 24:
    case 25:
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 26:
    case 27:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 28:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        break;
    default:
        break;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (i + x1 >= 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (block[i][j] == 1)
                {
                    gotoXY(hOut, 2 * (y1 + j), x1 + i);
                    cout << "■";
                }
            }
        }
    }
}
void Block::block_print2(HANDLE hOut, int block[4][4], int x1, int y1)//打印p2玩家方块
{
    switch (block[0][0])
    {
    case 10:
    case 11:
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 16:
    case 17:
    case 18:
    case 19:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 20:
    case 21:
    case 22:
    case 23:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 24:
    case 25:
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 26:
    case 27:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 28:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        break;
    default:
        break;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (i + x1 >= 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (block[i][j] == 1)
                {
                    gotoXY(hOut, 2 * (y1 + j) + 50, x1 + i);
                    cout << "■";
                }
            }
        }
    }
}

void Block::block_create1(HANDLE hOut, int block[4][4])//随机生成方块 
{
block_delete1(hOut, block, 5, 15);
int x = rand() % 19;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            block[i][j] = square[x][i][j];
        }
    }
    block_print1(hOut, block, 5, 15);
}

void Block::block_create2(HANDLE hOut, int block[4][4])//随机生成方块 
{
    block_delete1(hOut, block, 5, 20);
    int x = rand() % 19;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            block[i][j] = square[x][i][j];
        }
    }
    block_print1(hOut, block, 5, 20);
}
};
