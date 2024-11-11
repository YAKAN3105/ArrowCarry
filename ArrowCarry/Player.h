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

	struct Position
	{
		int x;
		int y;
	};

private:
	Position pos;

	int radius;
	float speed;

	// �O���t�B�b�N�n���h��
	int m_handleIdle;
	int m_handleRun;


	

};

