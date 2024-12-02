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

Arrow::Arrow(Player* playerPointer):
	m_pPlayer(playerPointer),
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
	Color = 0xff0000;
#if _DEBUG
	DrawBox(GetLeft(), GetTop(), GetRight(), GetBottom(), Color, false);
#endif // DEBUG

	DrawRotaGraph(static_cast<int> (m_pos.x), static_cast<int>(m_pos.y - kGraphHeight* 0.5f + 20),0.1f, 0,m_handleUpArrow, true);

	DrawFormatString(0,0,0xffffff,"PlayerPos:%f,%f", m_pPlayer->GetLeft(), m_pPlayer->GetTop());
}

float Arrow::GetLeft()
{
	return (m_pos.x - kHitBoxWidth);
}

float Arrow::GetTop()
{
	return (m_pos.y - kHitBoxHeight);
}

float Arrow::GetRight()
{
	return (m_pos.x + kHitBoxWidth);
}

float Arrow::GetBottom()
{
	return m_pos.y;
}

void Arrow::OnPlayerHit()
{
	if (GetLeft() <= m_pPlayer->GetRight() &&
		GetRight() >= m_pPlayer->GetLeft() &&
		GetTop() <=m_pPlayer->GetBottom() &&
		GetBottom() >=m_pPlayer->GetTop() )
	{
		m_pPlayer->IsHitArrow();
		//printfDx("当たった！\n");
	}
	else
	{
		//printfDx("当たってない\n");
	}
}
