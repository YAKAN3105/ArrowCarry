#include "Player.h"
#include <DxLib.h>
#include<cassert>
namespace
{
	unsigned int Color;

	constexpr float kPlayerRadius = 30; // ‰~‚Ì”¼Œa
}

Player::Player()
{
	radius = kPlayerRadius;
	speed = 2;
}

Player::~Player()
{
}

void Player::Init()
{
	m_handleIdle = LoadGraph("data/image/Idle.png");
	assert(m_handleIdle != -1);

	pos.x = 100;
	pos.y = 600;
}

void Player::End()
{
}

void Player::Update()
{
	pos.x+= speed;
}

void Player::Draw()
{
	Color = GetColor(0, 0, 255);
	DrawCircle(pos.x, pos.y, radius, Color, TRUE);
}

float Player::GetLeft() const
{
	return 0.0f;
}

float Player::GetTop() const
{
	return 0.0f;
}

float Player::GetRight() const
{
	return 0.0f;
}

float Player::GetBottom() const
{
	return 0.0f;
}
