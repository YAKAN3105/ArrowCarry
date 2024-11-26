#include "Arrow.h"
#include<DxLib.h>
#include "game.h"
#include "Player.h"

namespace
{
	constexpr float kWidth =0;
	constexpr float kHeight = 0;

	unsigned int Color;
}

Arrow::Arrow(Player* playerPointer):
	m_pPlayer(playerPointer)
{

}

Arrow::~Arrow()
{
}

void Arrow::Init()
{

}

void Arrow::Update()
{
	//pos.x = Game::kScreenWidth;
	//pos.y = Game::kScreenHeight;
	m_pos.Top = 600;
	m_pos.Bottom = 680;
	m_pos.Left = 600;
	m_pos.Right = 680;

}

void Arrow::Draw()
{
	0xff0000;
	// 0xff ff ff
	// ç∂Ç©ÇÁèáÇ…RGB(ê‘ÅEóŒÅEê¬)
	// 0Å`255
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
	DrawBox(m_pos.Left,m_pos.Top,m_pos.Right,m_pos.Bottom,Color, TRUE);

	DrawFormatString(0,0,0xffffff,"PlayerPos:%f,%f", m_pPlayer->GetLeft(), m_pPlayer->GetTop());
}

float Arrow::GetLeft()
{
	return 0.0f;
}

float Arrow::GetTop()
{
	return 0.0f;
}

float Arrow::GetRight()
{
	return 0.0f;
}

float Arrow::GetBottom()
{
	return 0.0f;
}

void Arrow::OnPlayerHit()
{
	if (m_pos.Left <= m_pPlayer->GetRight() &&
		m_pos.Right >=m_pPlayer->GetLeft())
	{
		m_pPlayer->IsHitArrow();
		printfDx("ìñÇΩÇ¡ÇΩÅI");
	}
}
