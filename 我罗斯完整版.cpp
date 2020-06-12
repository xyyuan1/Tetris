#include<iostream>
#include<string>
#include<ctime>
#include<windows.h>
#include<conio.h>

using namespace std;
int square[19][4][4] =
{
    { { 10,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } },
    { { 11,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } },
    { { 12,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,1,0,0 } },
    { { 13,0,0,0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } },
    { { 14,0,0,0 },{ 0,0,0,0 },{ 0,1,0,0 },{ 1,1,1,0 } },
    { { 15,0,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,1,0,0 } },
    { { 16,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 1,0,0,0 } },
    { { 17,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 } },
    { { 18,0,0,0 },{ 0,0,0,0 },{ 0,0,1,0 },{ 1,1,1,0 } },
    { { 19,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 } },
    { { 20,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,0,1,0 } },
    { { 21,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 1,1,0,0 } },
    { { 22,0,0,0 },{ 0,0,0,0 },{ 1,0,0,0 },{ 1,1,1,0 } },
    { { 23,0,0,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,1,0,0 } },
    { { 24,0,0,0 },{ 0,0,0,0 },{ 0,1,1,0 },{ 1,1,0,0 } },
    { { 25,0,0,0 },{ 1,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } },
    { { 26,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 0,1,1,0 } },
    { { 27,0,0,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 } },
    { { 28,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 1,1,0,0 } },
};
void gotoXY(HANDLE hOut, int x1, int y1)//移动光标到相应位置
{
    COORD pos;
    pos.X = x1;
    pos.Y = y1;
    SetConsoleCursorPosition(hOut, pos);
}
class draw;
class game;
class player;
class Block {
public:
    friend game;
    friend player;
    Block() { ; }
    void block_delete1(HANDLE hOut, int block[4][4], int x1, int y1)//清除方块 
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
    void block_delete2(HANDLE hOut, int block[4][4], int x1, int y1)//清除方块 
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
    void block_print1(HANDLE hOut, int block[4][4], int x1, int y1)//打印p1玩家方块
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
    void block_print2(HANDLE hOut, int block[4][4], int x1, int y1)//打印p2玩家方块
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

    void block_create1(HANDLE hOut, int block[4][4])//随机生成方块 
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

    void block_create2(HANDLE hOut, int block[4][4])//随机生成方块 
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
class game {
public:
    void gamestop(HANDLE hOut, int block1[4][4], int block2[4][4], Block& b)//暂停游戏
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
    void gameover(HANDLE hOut, player& p, Block& b, int block1[4][4], int block2[4][4])  //游戏结束
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
};
class player
{
private:
    int map[21][12], x, y;
    string name;
public:
    friend game;
    friend draw;
    friend Block;
    player() { ; }
    player(int x, int y, string name)
    {
        this->x = x; this->y = y; this->name = name;
        int i, j;
        for (i = 0; i < 20; i++)
        {
            for (j = 1; j < 11; j++)
                map[i][j] = 0;
        }
        for (int i = 0; i < 20; ++i)
        {
            map[i][0] = map[i][11] = 1;
        }
        for (int i = 0; i < 12; ++i)
        {
            map[20][i] = 1;
        }
    }
    void setxy(int x, int y)
    {
        this->x = x; this->y = y;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    string getname()
    {
        return name;
    }
    int player_judge(int block[4][4], int x1, int y1) //判断方块碰撞 
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (x1 + i >= 0 && y1 + j >= 0 && map[x1 + i][y1 + j] == 1 && block[i][j] == 1)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    void left_move(HANDLE hOut, int block[4][4], Block& b)	//左移方块 
    {
        int x1 = x, y1 = y;
        if (player_judge(block, x1, y1 - 1))
        {
            if(name=="player1")
                b.block_delete1(hOut, block, x, y);
            else if(name == "player2")
                b.block_delete2(hOut, block, x, y);
            y--;
        }
    }
    void right_move(HANDLE hOut, int block[4][4], Block& b)//右移方块 
    {
        int x1 = x, y1 = y;
        if (player_judge(block, x1, y1 + 1))
        {
            if (name == "player1")
                b.block_delete1(hOut, block, x, y);
            else if (name == "player2")
                b.block_delete2(hOut, block, x, y);
            y++;
        }
    }
    void rotate_move(HANDLE hOut, int block[4][4], Block& b)//旋转方块 
    {
        int x1 = x, y1 = y;
        switch (block[0][0])
        {
        case 10:
            if (player_judge(square[1], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                        block[i][j] = square[1][i][j];
                }
            }
            break;
        case 11:
            if (player_judge(square[0], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[0], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[0], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            else if (player_judge(square[0], x1, y1 + 2) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y += 2;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[0][i][j];
            }
            break;
        case 12:
            if (player_judge(square[3], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[3], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[3], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[3][i][j];
            }
            break;
        case 13:
            if (player_judge(square[4], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[4], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[4], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[4][i][j];
            }
            break;
        case 14:
            if (player_judge(square[5], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[5], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[5], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[5][i][j];
            }
            break;
        case 15:
            if (player_judge(square[2], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[2], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[2], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[2][i][j];
            }
            break;
        case 16:
            if (player_judge(square[7], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[7], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[7], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[7][i][j];
            }
            break;
        case 17:
            if (player_judge(square[8], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[8], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[8], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[8][i][j];
            }
            break;
        case 18:
            if (player_judge(square[9], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[9], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[9], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[9][i][j];
            }
            break;
        case 19:
            if (player_judge(square[6], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[6], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[6], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[6][i][j];
            }
            break;
        case 20:
            if (player_judge(square[11], x1, y1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[11], x1, y1 - 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[11], x1, y1 + 1) == 1)
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                    block[i][j] = square[11][i][j];
            }
            break;
        case 21:
            if (player_judge(square[12], x1, y1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[12], x1, y1 - 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);;
                y--;
            }
            else if (player_judge(square[12], x1, y1 + 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = square[12][i][j];
                }
            }
            break;

        case 22:
            if (player_judge(square[13], x1, y1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[13], x1, y1 - 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[13], x1, y1 + 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = square[13][i][j];
                }
            }
            break;

        case 23:
            if (player_judge(square[10], x1, y1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[10], x1, y1 - 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[10], x1, y1 + 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = square[10][i][j];
                }
            }
            break;

        case 24:
            if (player_judge(square[15], x1, y1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[15], x1, y1 - 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[15], x1, y1 + 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = square[15][i][j];
                }
            }
            break;
        case 25:
            if (player_judge(square[14], x1, y1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[14], x1, y1 - 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[14], x1, y1 + 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = square[14][i][j];
                }
            }
            break;
        case 26:
            if (player_judge(square[17], x1, y1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[17], x1, y1 - 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[17], x1, y1 + 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = square[17][i][j];
                }
            }
            break;
        case 27:
            if (player_judge(square[16], x1, y1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
            }
            else if (player_judge(square[16], x1, y1 - 1))
            {
                if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y--;
            }
            else if (player_judge(square[16], x1, y1 + 1))
            {
               if (name == "player1")
                    b.block_delete1(hOut, block, x, y);
                else if (name == "player2")
                    b.block_delete2(hOut, block, x, y);
                y++;
            }
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = square[16][i][j];
                }
            }
            break;
        default:
            break;
        }
    }
    int down_move(HANDLE hOut, int block[4][4], Block& b) //加速方块下落 未完成
    {
        int x1 = x, y1 = y;
        if (player_judge(block, x1 + 1, y1))
        {
            if (name == "player1")
                b.block_delete1(hOut, block, x1, y1);
            else b.block_delete2(hOut, block, x1, y1);
            x++;
            return 0;
        }
        if (x1 < 0) return 2;
        int k = 0;
        if (name == "player2")
            k = 50;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (block[i][j] == 1)
                {
                    map[x1 + i][y1 + j] = 1;
                    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                    gotoXY(hOut, 2 * (y + j) + k, x + i);
                    cout << "■";
                }
        return 1;
    }
    void lineelimination(HANDLE hOut, player& p, game& g, Block& b, int block1[4][4], int block2[4][4])
    {
        int i, j, flag = 1, t, k;
        int a1 = 0, a2 = 50;
        if (name == "player2")
        {
            a1 = 50; a2 = 0;
        }
        for (i = 19; i >= 0; i--)
        {
            flag = 1;
            for (j = 1; j <= 10; j++)
            {
                if (map[i][j] != 1)
                {
                    flag = 0; break;
                }
            }
            if (flag == 1)
            {
                for (j = i; j > 0; j--)
                {
                    for (t = 1; t < 11; t++)
                    {
                        map[j][t] = map[j - 1][t];
                        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                        gotoXY(hOut, 2 * t+a1, j);
                        if (map[j][t] == 1)
                            cout << "■";
                        else
                            cout << "  ";
                    }
                }
                int flag1 = 1;
                for (j = 1; j < 11; j++)
                {
                    if (p.map[0][j] == 1)
                    {
                        flag1 = 0; break;
                    }
                }
                if (flag1 == 0)
                {
                    g.gameover(hOut, p, b, block1, block2);
                }
                else
                {
                    for (k = 1; k < 20; k++)//将整体map坐标上移
                    {
                        for (j = 1; j < 11; j++)
                        {
                            p.map[k - 1][j] = p.map[k][j];
                        }
                    }
                    for (k = 0; k < 20; k++)
                    {
                        for (j = 1; j < 11; j++)
                        {
                            gotoXY(hOut, 2 * j + a2, k);
                            cout << "  ";
                            
                        }
                    }
                    srand((unsigned)time(NULL));
                    for (j = 1; j < 11; j++)
                    {
                        p.map[19][j] = rand() % 2;
                    }
                    for (k = 0; k < 20; k++)
                    {
                        for (j = 1; j < 11; j++)
                        {
                            if (p.map[k][j] == 1)
                            {
                                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                                gotoXY(hOut, 2 * j + a2, k);
                                cout << "■";
                            }
                        }
                    }
                }
                i++;
            }
        }
    }
};
class draw {
public:
    void background_draw(HANDLE hOut) //绘制背景  双人对战 
    {
        SetConsoleTitle("我罗斯方块");//控制台名称 
        COORD size = { 100, 25 };//控制台屏幕缓冲区大小
        SetConsoleScreenBufferSize(hOut, size);
        SMALL_RECT rc = { 0, 0, 99, 24 };//矩形左上角，右下角坐标 
        SetConsoleWindowInfo(hOut, true, &rc);
        CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//隐藏光标
        SetConsoleCursorInfo(hOut, &cursor_info);
    }
    void foreground_draw(HANDLE hOut)
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
};

int main()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出设备句柄
    draw boundary;
    boundary.background_draw(hOut);
    boundary.foreground_draw(hOut);
initial:
    player p1(-3, 4, "player1"), p2(0, 0, "player2");
    Block b1, b2;
    game g1, g2;
    Block b;
    char input;
    int i, j;
    int flag1 = 1, flag2 = 1, time1 = 40, time2 = 40;
    int block1[4][4], block2[4][4], blocknext1[4][4], blocknext2[4][4];//定义
    srand((unsigned)time(NULL));
    b1.block_create1(hOut, blocknext1);  b2.block_create2(hOut, blocknext2);
    while (1)
    {
        if (flag1)
        {
            p1.lineelimination(hOut, p2, g1, b1, blocknext1, blocknext2);
            p1.setxy(-3, 4);
            if (p1.player_judge(blocknext1, -3, 4))
            {
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        block1[i][j] = blocknext1[i][j];
                    }
                }
                b1.block_create1(hOut, blocknext1);
            }
            else
            {
            	gotoXY(hOut, 33, 2);
                cout << p1.getname();
                g1.gameover(hOut, p1, b1, blocknext1, blocknext2);
                
                goto initial;
            }
            flag1 = 0;
        }
        b1.block_print1(hOut, block1, p1.getx(), p1.gety());
        if (flag2)
        {
            p2.lineelimination(hOut, p1, g2, b2, blocknext1, blocknext2);
            p2.setxy(-3, 4);
            if (p1.player_judge(blocknext2, -3, 4))
            {
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        block2[i][j] = blocknext2[i][j];
                    }
                }
                b1.block_create2(hOut, blocknext2);
            }
            else
            {
            	gotoXY(hOut, 33, 2);
                cout << p2.getname();
                g2.gameover(hOut, p2, b2, blocknext1, blocknext2);
            }
            flag2 = 0;
        }
        b2.block_print2(hOut, block2, p2.getx(), p2.gety());

        if (_kbhit())
        {
            input = _getch();
            switch (input)
            {
            case 119:
                p1.rotate_move(hOut, block1, b1);
                break;
            case 97:
                p1.left_move(hOut, block1, b1);
                break;
            case 100:
                p1.right_move(hOut, block1, b1);
                break;
            case 115:
                switch (p1.down_move(hOut, block1, b1))
                {
                case 0:
                    flag1 = 0;
                    break;
                case 1:
                    flag1 = 1;
                    break;
                case 2:
                	gotoXY(hOut, 33, 2);
                    cout << p2.getname();
                    g1.gameover(hOut, p1, b1, blocknext1, blocknext2);
                default:
                    break;
                }
                break;
            case 72:
                p2.rotate_move(hOut, block2, b2);
                break;
            case 75:
                p2.left_move(hOut, block2, b2);
                break;
            case 77:
                p2.right_move(hOut, block2, b2);
                break;
            case 80:
                switch (p2.down_move(hOut, block2, b2))
                {
                case 0:
                    flag2 = 0;
                    break;
                case 1:
                    flag2 = 1;
                    break;
                case 2:
                	gotoXY(hOut, 33, 2);
                    cout << p1.getname();
                    g2.gameover(hOut, p2, b2, blocknext1, blocknext2);
                default:
                    break;
                }
                break;
            case 32:
                g1.gamestop(hOut, blocknext1, blocknext2, b);
                break;
            default:
                break;
            }
        }
        Sleep(20);//控制下落速度
        if (--time1 == 0)
        {
            switch (p1.down_move(hOut, block1, b1))
            {
            case 0:
                flag1 = 0; break;
            case 1:
                flag1 = 1; break;
            case 2:
            	gotoXY(hOut, 33, 2);
                cout << p1.getname();
                g1.gameover(hOut, p1, b1, blocknext1, blocknext2);
                break;
            }
            time1 = 40;
        }
        if (--time2 == 0)
        {
            switch (p2.down_move(hOut, block2, b2))
            {
            case 0:
                flag2 = 0; break;
            case 1:
                flag2 = 1; break;
            case 2:
            	gotoXY(hOut, 33, 2);
                cout << p2.getname();
                g2.gameover(hOut, p2, b2, blocknext1, blocknext2);
                break;
            }
            time2 = 40;
        }
    }

    return 0;
}
