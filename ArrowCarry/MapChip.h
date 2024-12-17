#pragma once
#include"Rect.h"
#include<memory>

class Player;

enum class MapKind
{
	kBack,
	kChip,
	kGoal,
};

class MapChip
{
public:
	MapChip(Player* m_pPlayer);
	~MapChip();

	void Init(int no);
	void Draw();

	bool CheckIsHit(Rect rectA,Rect rectB);

	const MapKind GetKind() const { return m_kind; } // マップチップの種類

	const Rect GetRect() const { return m_rect; } // マップチップの判定

	void DebugDraw();

private:
	Vec2 m_pos;
	Rect m_rect;

	int m_srcX;
	int m_srcY;
	int m_handle;

	std::vector<unsigned __int8>m_data;

	bool IsHit(int x, int y);
	
	Player* m_pPlayer;

	MapKind m_kind;
};
