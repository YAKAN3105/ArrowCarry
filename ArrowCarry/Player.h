#pragma once
#include "Vec2.h"
class Player
{
public:
	Player();
	~Player();

	void Init();
	void End();
	void Update();
	void Draw();

	// �v���C���[�̈ʒu�����擾����
	float GetLeft()const;
	float GetTop()const;
	float GetRight()const;
	float GetBottom()const;

	void IsHitArrow();

	

private:

	Vec2  m_pos;
	
	float m_speed;

	float m_jumpPower;

	bool m_isJump;

	bool m_lastJump;

	// �A�j���[�V�����֘A
	int m_animFrame; // �t���[�����𐔂���
	// ���ݍĐ����̃A�j���[�V����
	// true:�����Ă��� false:�ҋ@
	bool m_isRun;	// �ϐ�

	// player�����������Ă��邩�ǂ���
	// true:�������@false:�E����
	bool m_isDirLeft;	// �ϐ�
 
	// �O���t�B�b�N�n���h��
	int m_handleIdle;
	int m_handleRun;

	int m_playerNowPos;
	

};

