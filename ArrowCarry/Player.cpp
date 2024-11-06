#include "Player.h"
#include <DxLib.h>

namespace
{
	unsigned int Color;
	constexpr float kCircleX = 320;
	constexpr float kCircleY = 240;
	constexpr float kCircleR = 100;
}

Player::Player()
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	Color = GetColor(0, 0, 255);
	DrawCircle(kCircleX, kCircleY, kCircleR, Color, TRUE);
}
