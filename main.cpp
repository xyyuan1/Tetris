#include<iostream>
#include<string>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include"player.h"
#include"draw.h"
#include"game.h"
#include"Block.h"
#include"others.h" 

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
