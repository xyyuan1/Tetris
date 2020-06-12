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
    player(int x, int y, string name);
    
    void setxy(int x, int y);
    
    int getx();

    int gety();

    string getname();

    int player_judge(int block[4][4], int x1, int y1); //判断方块碰撞 

    void left_move(HANDLE hOut, int block[4][4], Block& b);	//左移方块 

    void right_move(HANDLE hOut, int block[4][4], Block& b);//右移方块 

    void rotate_move(HANDLE hOut, int block[4][4], Block& b);//旋转方块 
    
    int down_move(HANDLE hOut, int block[4][4], Block& b); //加速方块下落 未完成
    
    void lineelimination(HANDLE hOut, player& p, game& g, Block& b, int block1[4][4], int block2[4][4]);
    
};
