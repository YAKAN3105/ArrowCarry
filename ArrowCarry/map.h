#pragma once
#include <vector>
#include "MapChip.h"
#include <memory>

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
	

	MapKind GetKind(int x, int y);
	Rect GetRect(int x, int y);
	int GetChipIndexX();
	int GetChipIndexY();

private:

	

	// マップとプレイヤーが当たったことを伝える
	void ChangePlayerHitFlag();

private:

	// グラフィックのハンドル
	int m_handle;

	// グラフィックにチップがいくつ含まれているか
	int m_graphChipNumX;
	int m_graphChipNumY;

	std::vector<unsigned __int8>m_data;

	int m_mapchip;

	int m_offsetPosY;

	int m_fileSize; // 外部ファイルの大きさを保存するための変数


	std::vector<MapChip*> m_pMapChip;
};

