#include "MapChip.h"
#include <DxLib.h>
namespace 
{
	// マップチップ1つのサイズ
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;
}

MapChip::MapChip()
{
}

MapChip::~MapChip()
{
}

void MapChip::Init(Vec2 pos, int handle)
{
	// 初期化
	m_pos = pos;
	m_rect.Init( m_pos ,kChipWidth, kChipHeight);
	m_handle1 = handle;
}

void MapChip::End()
{
}

void MapChip::Update()
{
}

void MapChip::Draw()
{
	// 柱ブロックと壁ブロックの情報取得と生成
	//if (map.data[map.kChipIndexY][map.kChipIndexX] == 67) // 柱ブロック
	//{
	//	DrawGraph(kChipWidth, kChipHeight, m_handle1, false);
	//}
	//if (map.data[map.kChipIndexY][map.kChipIndexX] == 82) // 壁ブロック
	//{
	//	DrawGraph(kChipWidth, kChipHeight, m_handle1, false);
	//}
}
