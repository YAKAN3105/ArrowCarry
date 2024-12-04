#pragma once
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

	constexpr float kGravity = -0.1f;

	constexpr float kJumpSpeed = 10;

}

Player::Player(Map* mapPointer) :
	m_pMap(mapPointer),
	m_handleIdle(-1),
	m_handleRun(-1),
	m_animFrame(0),
	m_isRun(false),
	m_isDirLeft(false),
	m_isJumpNow(false),
	m_isFalling(false),
	m_isMapHit(false),
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
	m_velocity.x = 0;
	m_velocity.y = 0;
}

void Player::End()
{
	// グラフィックの解放
	DeleteGraph(m_handleIdle);
	DeleteGraph(m_handleRun);
}

void Player::Update()
{ 
	//マップと当たっているかどうか
	CheckHitMap();
	//if (m_isMapHit)
	//{
	//	ChangePosMapHit();
	//	m_isMapHit = false;
	//	m_isFalling = false;
	//}

	//前のフレームの位置の保存
	m_backPos = m_pos;

	//位置の更新
	m_pos = m_pos + m_velocity;

	//キー入力の確認
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_isRun = true;
		
	}
	else if (CheckHitKey(KEY_INPUT_0))
	{
		m_isRun = false;
		m_pos.x = m_playerNowPos;//初期位置に戻る
	}


#if _DEBUG
	// 一旦キーを押して動かせるようにする
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_isRun = true;
		m_velocity.x = m_speed;
		m_isDirLeft = false;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_isRun = true;
		m_velocity.x = -m_speed;
		m_isDirLeft = true;
	}
#endif // DEBUG


	//アニメーションの更新
	AnimationUpdate();

	//速度の更新
	/*if (m_isRun)
	{
		m_velocity.x = m_speed;
	}*/

	//ジャンプ
	if (m_isJumpNow)
	{
		m_velocity.y -= 0.4f;
		m_isJumpNow = false;
		m_isFalling = true;
	}
	//落下
	if (m_isFalling)
	{
		m_velocity.y -= kGravity;
	}



}

void Player::AnimationUpdate()
{
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
	return m_pos.x + kGraphWidth * 0.2f;
}

float Player::GetBottom() const
{
	return m_pos.y;
}

void Player::IsHitArrow()
{
	m_isJumpNow = true;
}

void Player::ChangeHitMap()
{
	if (GetLeft() > m_pMap->GetRight(32) &&
		GetRight() < m_pMap->GetLeft(32) &&
		GetTop() < m_pMap->
		GetBottom(32) && GetBottom() < m_pMap->GetTop(32));
	m_isMapHit = true;
}
void Player::CheckHitMap()
{
	// 全マップチップと判定を行う

	// 当たっていた場合はChangePosMapHit()これを呼ぶ？
}
void Player::InitVelocity()
{
	Vec2 zero{0,0};
	m_velocity = zero;
}

void Player::ChangePosMapHit()
{
	//速度を止める
	InitVelocity();
	//1フレーム前の位置に戻す
	m_pos = m_backPos;
	m_isRun = true;
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

	DrawRectGraph(static_cast<int>(m_pos.x - kGraphWidth *0.4f), static_cast<int>(m_pos.y - kGraphHeight * 0.5f),
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		useHandle, true, m_isDirLeft);

	// あたりはんていをつける
	DrawBox(m_pos.x - kPlayerHitWidth * 0.5f, m_pos.y - kPlayerHitHeight * 0.5f,
		m_pos.x + kPlayerHitWidth * 0.5f, m_pos.y + kPlayerHitHeight * 0.5f,
		0x0000ff, false);
}
