#pragma once
#include<cassert>
#include"Vec2.h"
#include "Rect.h"

class Player;

class Arrow
{
public:
	Arrow(Player* playerPointer);
	~Arrow();

	void Init();
	void End();
	void Update();
	void Draw();

	Rect GetRect() const { return m_rect; }

private:

	
	Player* m_pPlayer;
	Vec2 m_pos;
	Rect m_rect;

	int m_radius;

	int m_handleUpArrow;
	int m_handleLeftArrow;
	int m_handleRightArrow;

	int m_isDitLeft;


};

