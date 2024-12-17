#pragma once
#include "Arrow.h"
#include<DxLib.h>
#include "game.h"
#include "Player.h"

namespace
{
	constexpr float kWidth =0;
	constexpr float kHeight = 0;

	unsigned int Color;

	// Arrowのグラフィックの大きさ
	constexpr int kGraphWidth = 100;
	constexpr int kGraphHeight = 100;

	constexpr int kHitBoxWidth = 30;
	constexpr int kHitBoxHeight = 60;

}

Arrow::Arrow(Player* m_pPlayer):
	m_handleLeftArrow(-1),
	m_handleRightArrow(-1),
	m_handleUpArrow(-1),
	m_pos(300.0f,720.0f-32.0f)
{

}

Arrow::~Arrow()
{
}

void Arrow::Init()
{
	m_handleUpArrow = LoadGraph("data/Arrow/up.png");
	assert(m_handleUpArrow != -1);
}

void Arrow::End()
{
	// グラフィックの開放
	DeleteGraph(m_handleUpArrow);
}

void Arrow::Update()
{
	//pos.x = Game::kScreenWidth;
	//pos.y = Game::kScreenHeight;
}

void Arrow::Draw()
{
	0xff0000;
	int useHandle = m_handleUpArrow;
	// 0xff ff ff
	// 左から順にRGB(赤・緑・青)
	// 0～255
	// 
	// 0x0f = 15;
	// 0x10 = 16;
	// 0x20 = 32;
	// 0xf0 = 240;
	// 
	// 
	// 0b0101 0101  0101 0101  0101 0101
	// 
	//	Color = GetColor(255, 0, 0);
	Color = 0xffff00;
	// 矢印の当たり判定
#if _DEBUG
	DrawBox(m_rect.GetLeft(), m_rect.GetTop(), m_rect.GetRight(), m_rect.GetBottom(), Color, false);
#endif // DEBUG

	DrawRotaGraph(static_cast<int> (m_pos.x), static_cast<int>(m_pos.y - kGraphHeight* 0.5f + 20),0.1f, 0,m_handleUpArrow, true);
}

Vec2 Arrow::GetPower()
{
	Vec2 ans;
	ans.x = 0;
	ans.y = 0;
	ans.y = 0;
	if (m_dir == Dir::kUp)	// 矢印が上に力を加える
	{
		ans.y += 2;
	}
	else if (m_dir == Dir::kLeft)  // 矢印が左方向に力を加える
	{
		ans.x += 2;
	}
	else if (m_dir == Dir::kRight)	// 矢印が右方向に力を加える
	{
		ans.x -= 2;
	}
	return ans;
}

