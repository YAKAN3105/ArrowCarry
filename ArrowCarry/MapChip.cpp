#include "MapChip.h"
#include "DxLib.h"
#include "game.h"

namespace
{
	// マップチップ1つのサイズ
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;

	// パーツの選択範囲
	constexpr int kPartsNumX = 16; 
	constexpr int kPartsNumY = 16;

	// マップチップの要素数
	constexpr int kChipIndexX = 40;	
	constexpr int kChipIndexY = 32;

	constexpr int kOffsetY = kChipHeight * kChipIndexY - Game::kScreenHeight;
}

MapChip::MapChip()
{
}

MapChip::~MapChip()
{
}

void MapChip::Init(int no)
{
	// 0から始まる通し番号を
	// 上から何個目、左から何個目なのか、という情報に変換する必要がある
	// グラフィックに何個チップが含まれているか、という情報を使用して
	// 計算で求める
	m_srcX = no % Width;
	m_srcY = no / Height;
}

void MapChip::Draw()
{
	DrawRectGraph(m_pos.x, m_pos.y, m_srcX, m_srcY, );
	


	// チップ番号から切り出し位置を計算する
	int cutX = m_srcX * kChipWidth; // インデックスX番号を用いたマップチップの位置を示す変数
	int cutY = m_srcY * kChipHeight; // インデックスY番号を用いたマップチップの位置を示す変数
	
	DrawRectGraph
	(m_pos.x * kChipWidth,				// グラフィックを描画する座標
	m_pos.y * kChipHeight - m_offsetPosY,
	cutX, cutY,					// 描画するグラフィック上の描画したい矩形の左上座標
	kChipWidth, kChipHeight,	// 描画するグラフィックのサイズ
	m_handle, true);			// 透過処理するかどうか
}

bool MapChip::CheckIsHit(Rect rectA, Rect rectB)
{
	return false;
}
