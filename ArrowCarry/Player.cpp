#include "Player.h"
#include <DxLib.h>

namespace
{
	unsigned int Color;

	constexpr float kPlayerRadius = 30;
}

Player::Player()
{
	radius = kPlayerRadius;
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
	pos.x++;
	pos.y = 50;
	radius++;
}

void Player::Draw()
{
	Color = GetColor(0, 0, 255);
	DrawCircle(pos.x, pos.y, radius, Color, TRUE);
}
