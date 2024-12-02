#pragma once
#include <iostream>
#include <fstream>
#include<vector>
#include<cassert>
#include"Player.h"
#include"game.h"

namespace
{
	//const char* const FILE_NAME = "data/MapChip1.fmf";
}

class Map
{
public:
	Map(Player* playerPointer);
	~Map();

	void Init();
	void End();
	void Update();
	void Draw();
	
	int GetLeft(int x);
	int GetTop(int y);
	int GetRight(int x);
	int GetBottom(int y);
	void CheckHit();

private:

	bool IsHit(int x, int y);
	void FixPos(int x, int y);

private:

	Player* m_pPlayer;

	// グラフィックのハンドル
	int m_handle;

	// グラフィックにチップがいくつ含まれているか
	int m_graphChipNumX;
	int m_graphChipNumY;

	std::vector<unsigned __int8>m_data;

	int m_fileSize; // 外部ファイルの大きさを保存するための変数

	int m_offsetPosY; // マップチップの座標Yの補完


	
};

