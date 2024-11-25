#include "Player.h"
#include <DxLib.h>
#include<cassert>
namespace
{
	unsigned int Color;

	constexpr float kPlayerRadius = 30; // �~�̔��a

	// �L�����N�^�[�̃O���t�B�b�N�̂̕��ƍ���
	constexpr int kGraphWidth = 78;
	constexpr int kGraphHeight = 58;

	// �A�j���[�V�����̃R�}��
	constexpr int kIdleAnimNum = 11;
	constexpr int kRunAnimNum = 8;

	// �A�j���[�V����1�R�}�̃t���[����
	constexpr int kSingleAnimFrame = 4;

	constexpr float kPlayerPosX = 100;
	constexpr float kPlayerPosY = 672;
}

Player::Player() :
	m_handleIdle(-1),
	m_handleRun(-1),
	m_animFrame(0),
	m_isRun(false),
	m_isDirLeft(false)
{
	speed = 2;
	m_PlayerNowPos = kPlayerPosX;
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
	// �O���t�B�b�N�̉��
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
		m_pos.x = m_PlayerNowPos;
	}

	// �A�j���[�V�����̍X�V
	m_animFrame++;

	// �ҋ@���Ƃ��邢�Ă���Ƃ��̃t���[������0^78

	int totalFlame = kIdleAnimNum * kSingleAnimFrame;
	if (m_isRun)
	{
		totalFlame = kRunAnimNum * kSingleAnimFrame;
	}

	// �A�j���[�V�����̍��v�t���[�����𒴂�����ŏ��ɖ߂�
	if (m_animFrame >= totalFlame)
	{
		m_animFrame = 0;
	}

	// �O��̃A�j���[�V�����̏�Ԃ��o���Ă���
	//bool isLastRun = m_isRun;

	if (m_isRun)
	{
		m_pos.x += speed;
	}
	else if (m_isRun = false)
	{

	}


	////�������s�������ʁA�A�j���[�V�������ς���Ă����ꍇ�̏���
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

void Player::Draw()
{
	/*Color = GetColor(0, 0, 255);
	DrawCircle(m_pos.x, m_pos.y, radius, Color, TRUE);*/

	// �A�j���[�V�����̃t���[�����ƈ�R�}��R�}
	int animNo = m_animFrame / kSingleAnimFrame;

	// �g�p����O���t�B�b�N�̃n���h������U�ʂ�int�^�ϐ��Ɋi�[����
	int useHandle = m_handleIdle;
	if (m_isRun)
	{
		useHandle = m_handleRun;
	}

	DrawRectGraph(static_cast<int>(m_pos.x - kGraphWidth / 2), static_cast<int>(m_pos.y - kGraphHeight / 2),
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		useHandle, true, m_isDirLeft);
}
