#pragma once
#include <iostream>
#include <fstream>
#include<vector>

namespace
{
	//const char* const FILE_NAME = "data/MapChip1.fmf";
}

class Map
{
public:
	Map();
	~Map();

	void Init();
	void End();
	void Update();
	void Draw();

private:
	// グラフィックのハンドル
	int m_handle;

	// グラフィックにチップがいくつ含まれているか
	int m_graphChipNumX;
	int m_graphChipNumY;

	std::vector<unsigned __int8>m_data;

	int m_fileSize; // 外部ファイルの大きさを保存するための変数
	
};

