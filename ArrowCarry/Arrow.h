#pragma once
#include<cassert>
#include"Vec2.h"
#include "Rect.h"

class Player;

enum class ArrowDir
{
	kUp,
	kLeft,
	kRight
};

class Arrow
{
	

public:
	Arrow();
	~Arrow();

	void Init();
	void End();
	void Update();
	void Draw();

	Vec2 GetPower();



	Rect GetRect() const { return m_rect; }	// Arrow(矩形)の当たり判定

private:

	// プレイヤーとArrowがあたったときの処理
	bool IsHitArrow();
	
	Vec2 m_pos;
	Rect m_rect;

	int m_radius;

	int m_handleUpArrow;
	int m_handleLeftArrow;
	int m_handleRightArrow;

	int m_isDitLeft;

	ArrowDir m_dir;
	Player* m_pPlayer;
};

