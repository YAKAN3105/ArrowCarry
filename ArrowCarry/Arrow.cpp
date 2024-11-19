#include "Arrow.h"
#include<DxLib.h>
#include "game.h"

namespace
{
	constexpr float kWidth =0;
	constexpr float kHeight = 0;

	unsigned int Color;
}

Arrow::Arrow()
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
	pos.x = 200;
	pos.y = 200;
	pos.x1 = 50;
	pos.y1 = 50;
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
	DrawBox(600,600,680,680,Color, TRUE);
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
