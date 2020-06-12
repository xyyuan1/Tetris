class game
{
public:
    void gamestop(HANDLE hOut, int block1[4][4], int block2[4][4], Block& b);//暂停游戏
    void gameover(HANDLE hOut, player& p, Block& b, int block1[4][4], int block2[4][4]); //游戏结束
};
