#pragma once
#include<cassert>
#include"Vec2.h"
#include "Rect.h"

class Player;

class Arrow
{
private:
	enum class Dir
	{
		kUp,
		kLeft,
		kRight
	};

public:
	Arrow(Player* m_pPlayer);
	~Arrow();

	void Init();
	void End();
	void Update();
	void Draw();

	Vec2 GetPower();


	Rect GetRect() const { return m_rect; }

private:

	
	
	Vec2 m_pos;
	Rect m_rect;

	int m_radius;

	int m_handleUpArrow;
	int m_handleLeftArrow;
	int m_handleRightArrow;

	int m_isDitLeft;

	Dir m_dir;
};

