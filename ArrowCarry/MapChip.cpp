#include "MapChip.h"
#include "DxLib.h"
#include "game.h"
#include "Map.h"
#include <vector>
#include "Player.h"

namespace
{
	// マップチップ1つのサイズ
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;

	// マップチップの要素数
	constexpr int kChipIndexX = 40;	
	constexpr int kChipIndexY = 32;

	constexpr int kOffsetY = kChipHeight * kChipIndexY - Game::kScreenHeight;
}

MapChip::MapChip():
m_handle(-1)
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
	m_srcX = no % 16;
	m_srcY = no / 16;
}

void MapChip::Draw(int m_handle, int x, int y)
{
	
	// チップ番号から切り出し位置を計算する
	int cutX = m_srcX * kChipWidth; // インデックスX番号を用いたマップチップの位置を示す変数
	int cutY = m_srcY * kChipHeight; // インデックスY番号を用いたマップチップの位置を示す変数
	
	

	DrawRectGraph
	(x * kChipWidth,				// グラフィックを描画する座標
	y * kChipHeight - kOffsetY,
	cutX, cutY,					// 描画するグラフィック上の描画したい矩形の左上座標
	kChipWidth, kChipHeight,	// 描画するグラフィックのサイズ
	m_handle, true);			// 透過処理するかどうか
	
	DrawBox(x, y, x * kChipWidth, y * kChipHeight,
		0xff0000, false);
}


//bool MapChip::CheckIsHit(Rect rectA, Rect rectB)
//{
//	bool a = false;
//
//	for (int y = 0; y < kChipIndexY; y++)
//	{
//		for (int x = 0; x < kChipIndexX; x++)
//		{
//			// データから配置するチップを決定する
//			// 二重配列の場合でも、vector配列を先頭から順番に見ていくための処理
//			int chipNo = m_data[(y * kChipIndexX) + x];
//
//			if (chipNo < 0 || chipNo == 243)
//			{
//				// continueは繰り返し文(for,while)の中で使用する命令
//				// continueが呼ばれたら以降の繰り返し処理は行わず次のループに移行する
//				continue;
//			}
//
//			// ここにプレイヤーとマップが当たっているかの判定を行う
//			// あたっていなかったら次のマップチップへ
//			if (!IsHit(x, y))
//			{
//				continue;
//			}
//
//			// ここまで来たら当たっている
//			// 位置を修正してあげる
//			//ChangePlayerHitFlag();
//
//			a = true;
//		}
//	}
//
//	if (!a)
//	{
//		printfDx("あたってない\n");
//	}
//	return false;
//}

void MapChip::DebugDraw()
{
}


