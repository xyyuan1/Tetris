class Block {
	public:
	friend game;
	friend player;
	Block() { ; }
	void block_delete1(HANDLE hOut, int block[4][4], int x1, int y1);//清除p1玩家方块 

	void block_delete2(HANDLE hOut, int block[4][4], int x1, int y1);//清除p2玩家方块 

	void block_print1(HANDLE hOut, int block[4][4], int x1, int y1);//打印p1玩家方块

	void block_print2(HANDLE hOut, int block[4][4], int x1, int y1);//打印p2玩家方块
	
	void block_create1(HANDLE hOut, int block[4][4]);//随机生成p1玩家方块 
	
	void block_create2(HANDLE hOut, int block[4][4]);//随机生成p2玩家方块 

};
