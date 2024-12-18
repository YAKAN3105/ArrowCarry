#pragma once
#include"Rect.h"
#include<memory>


enum class MapKind
{
	kBack,
	kChip,
	kGoal,
};

class MapChip
{
public:
	MapChip();
	~MapChip();

	void Init(int no);
	void Draw(int m_handle, int x, int y);

//	bool CheckIsHit(Rect rectA,Rect rectB);

	const MapKind GetKind() const { return m_kind; } // マップチップの種類

	const Rect GetRect() const { return m_rect; } // マップチップの判定

	void DebugDraw();

private:
	Vec2 m_pos;
	Rect m_rect;

	int m_srcX;
	int m_srcY;
	int m_handle;

	

	bool IsHit(int x, int y);


	MapKind m_kind;
};
