#include<iostream>
#include<string>
#include<ctime>
#include<windows.h>
#include<conio.h>
using namespace std;
class block {
public:
	int block0[4][4] = { { 10,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } };
	int block1[4][4] = { { 11,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } };
	int block2[4][4] = { { 12,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,1,0,0 } };
	int block3[4][4] = { { 13,0,0,0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } };
	int block4[4][4] = { { 24,0,0,0 },{ 0,0,0,0 },{ 0,1,0,0 },{ 1,1,1,0 } };
	int block5[4][4] = { { 25,0,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,1,0,0 } };
	int block6[4][4] = { { 26,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 1,0,0,0 } };
	int block7[4][4] = { { 27,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 } };
	int block8[4][4] = { { 30,0,0,0 },{ 0,0,0,0 },{ 0,0,1,0 },{ 1,1,1,0 } };
	int block9[4][4] = { { 31,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 } };
	int block10[4][4] = { { 32,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,0,1,0 } };
	int block11[4][4] = { { 33,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 1,1,0,0 } };
	int block12[4][4] = { { 44,0,0,0 },{ 0,0,0,0 },{ 1,0,0,0 },{ 1,1,1,0 } };
	int block13[4][4] = { { 45,0,0,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,1,0,0 } };
	int block14[4][4] = { { 46,0,0,0 },{ 0,0,0,0 },{ 0,1,1,0 },{ 1,1,0,0 } };
	int block15[4][4] = { { 47,0,0,0 },{ 1,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } };
	int block16[4][4] = { { 50,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 0,1,1,0 } };
	int block17[4][4] = { { 51,0,0,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 } };
	int block18[4][4] = { { 52,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 1,1,0,0 } };

    void block_create(HANDLE hOut, int block[4][4])	//随机生成方块 
    {
        clearBlock(hOut, block, 5, 15);
        switch (rand() % 19)
        {
        case 0:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block0[i][j];
                }
            }
            break;
        case 1:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block1[i][j];
                }
            }
            break;
        case 2:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block2[i][j];
                }
            }
            break;
        case 3:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block3[i][j];
                }
            }
            break;
        case 4:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block4[i][j];
                }
            }
            break;
        case 5:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block5[i][j];
                }
            }
            break;
        case 6:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block6[i][j];
                }
            }
            break;
        case 7:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block7[i][j];
                }
            }
            break;
        case 8:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block8[i][j];
                }
            }
            break;
        case 9:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block9[i][j];
                }
            }
            break;
        case 10:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block10[i][j];
                }
            }
            break;
        case 11:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block11[i][j];
                }
            }
            break;
        case 12:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block12[i][j];
                }
            }
            break;
        case 13:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block13[i][j];
                }
            }
            break;
        case 14:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block14[i][j];
                }
            }
            break;
        case 15:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block15[i][j];
                }
            }
            break;
        case 16:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block16[i][j];
                }
            }
            break;
        case 17:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block17[i][j];
                }
            }
            break;
        case 18:
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block18[i][j];
                }
            }
            break;
        default:
            break;
        }
        printBlock(hOut, block, 5, 15);
}
	void block_print1(HANDLE hOut, int block[4][4], int x, int y)//打印p1玩家方块
	{
		switch (block[0][0]%10)
		{
		case 0:
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
			break;
		case 1:
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 2:
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 3:
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		case 4:
		case 7:
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 5:
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		case 6:
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		default:
			break;
		}
		for (int i = 0; i < 4; ++i)
		{
			if (i + x >= 0)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (block[i][j] == 1)
					{
						gotoXY(hOut, 2 * (y + j), x + i);
						cout << "■";
					}
				}
			}
		}
	}
	void block_print2(HANDLE hOut, int block[4][4], int x, int y)//打印p2玩家方块
	{
		switch (block[0][0] % 10)
		{
		case 0:
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
			break;
		case 1:
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 2:
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 3:
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		case 4:
		case 7:
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 5:
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		case 6:
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		default:
			break;
		}
		for (int i = 0; i < 4; ++i)
		{
			if (i + x >= 0)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (block[i][j] == 1)
					{
						gotoXY(hOut, 2 * (y + j) + 50, x + i);
						cout << "■";
					}
				}
			}
		}
	}
	void block_delete(HANDLE hOut, int block[4][4], int x, int y)//清除方块 
	{
		for (int i = 0; i < 4; ++i)
		{
			if (i + x >= 0)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (block[i][j] == 1)
					{
						gotoXY(hOut, 2 * (y + j), x + i);
						cout << "  ";
					}
				}
			}
		}
	}
	void block_fall();      //方块自动下落
};
