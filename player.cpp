#include"game.h"
#include"draw.h"
#include"Block.h"
#include"player.h"
player::player() { ; }
player::player(int x, int y, string name)
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
void player::setxy(int x, int y)
{
    this->x = x; this->y = y;
}
int player::getx()
{
    return x;
}
int player::gety()
{
    return y;
}
string player::getname()
{
    return name;
}
int player::player_judge(int block[4][4], int x1, int y1) //判断方块碰撞 
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
void player::left_move(HANDLE hOut, int block[4][4], Block& b)	//左移方块 
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
void player::right_move(HANDLE hOut, int block[4][4], Block& b)//右移方块 
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
void player::rotate_move(HANDLE hOut, int block[4][4], Block& b)//旋转方块 
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
int player::down_move(HANDLE hOut, int block[4][4], Block& b) //加速方块下落 未完成
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
void player::lineelimination(HANDLE hOut, player& p, game& g, Block& b, int block1[4][4], int block2[4][4])
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
