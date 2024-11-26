#include "Player.h"
#include <DxLib.h>
#include<cassert>
namespace
{
	unsigned int Color;

	constexpr float kPlayerRadius = 30; // 円の半径

	// キャラクターのグラフィックのの幅と高さ
	constexpr int kGraphWidth = 78;
	constexpr int kGraphHeight = 58;

	// アニメーションのコマ数
	constexpr int kIdleAnimNum = 11;
	constexpr int kRunAnimNum = 8;

	// アニメーション1コマのフレーム数
	constexpr int kSingleAnimFrame = 4;

	constexpr float kPlayerPosX = 100;
	constexpr float kPlayerPosY = 672;

	constexpr float kPlayerHitWidth = 40;
	constexpr float kPlayerHitHeight = 40;

	constexpr float kGravity = -0.3f;

	constexpr float kJumpSpeed = 10;

}

Player::Player() :
	m_handleIdle(-1),
	m_handleRun(-1),
	m_animFrame(0),
	m_isRun(false),
	m_isDirLeft(false),
	m_isJump(false),
	m_lastJump(false)
{
	m_speed = 2;
	m_playerNowPos = kPlayerPosX;
	m_jumpPower = 0;
}

Player::~Player()
{
}

void Player::Init()
{
	m_handleIdle = LoadGraph("data/image1/Sprites/King/Idle.png");
	assert(m_handleIdle != -1);

	m_handleRun = LoadGraph("data/image1/Sprites/King/Run.png");
	assert(m_handleRun != -1);

	m_pos.x = kPlayerPosX;
	m_pos.y = kPlayerPosY;
}

void Player::End()
{
	// グラフィックの解放
	DeleteGraph(m_handleIdle);
	DeleteGraph(m_handleRun);
}

void Player::Update()
{ 
	
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_isRun = true;
		
	}
	else if (CheckHitKey(KEY_INPUT_0))
	{
		m_isRun = false;
		m_pos.x = m_playerNowPos;
	}

	// アニメーションの更新
	m_animFrame++;

	// 待機中とあるいているときのフレーム数は0^78

	int totalFlame = kIdleAnimNum * kSingleAnimFrame;
	if (m_isRun)
	{
		totalFlame = kRunAnimNum * kSingleAnimFrame;
	}

	// アニメーションの合計フレーム数を超えたら最初に戻す
	if (m_animFrame >= totalFlame)
	{
		m_animFrame = 0;
	}

	// 前回のアニメーションの状態を覚えておく
	//bool isLastRun = m_isRun;

	if (m_isRun)
	{
		m_pos.x += m_speed;
	}
	else if (m_isRun = false)
	{

	}

	if (m_isJump != m_lastJump && m_isJump == true)	// 
	{
		m_jumpPower = -kJumpSpeed;
	}

	m_jumpPower -= kGravity;
	m_pos.y += m_jumpPower;

	if (m_pos.y > kPlayerPosY)
	{
		m_pos.y = kPlayerPosY;
	}


	m_lastJump = m_isJump;
	m_isJump = false;

	////処理を行った結果、アニメーションが変わっていた場合の処理
	//if (m_isRun != isLastRun)
	//{
	//	m_animFrame = 0;
	//}
}



float Player::GetLeft() const
{
	return m_pos.x - kGraphWidth * 0.5f;
}

float Player::GetTop() const
{
	return m_pos.y - kGraphHeight;
}

float Player::GetRight() const
{
	return m_pos.x + kGraphWidth / 2;
}

float Player::GetBottom() const
{
	return m_pos.y;
}

void Player::IsHitArrow()
{
	m_isJump = true;
}

void Player::Draw()
{
	/*Color = GetColor(0, 0, 255);
	DrawCircle(m_pos.x, m_pos.y, radius, Color, TRUE);*/

	// アニメーションのフレーム数と一コマ一コマ
	int animNo = m_animFrame / kSingleAnimFrame;

	// 使用するグラフィックのハンドルを一旦別のint型変数に格納する
	int useHandle = m_handleIdle;
	if (m_isRun)
	{
		useHandle = m_handleRun;
	}

	DrawRectGraph(static_cast<int>(m_pos.x - kGraphWidth / 2), static_cast<int>(m_pos.y - kGraphHeight / 2),
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		useHandle, true, m_isDirLeft);

	// あたりはんていをつける
	DrawBox(m_pos.x - kPlayerHitWidth * 0.5f, m_pos.y - kPlayerHitHeight * 0.5f,
		m_pos.x + kPlayerHitWidth * 0.5f, m_pos.y + kPlayerHitHeight * 0.5f,
		0xff0000, false);
}
