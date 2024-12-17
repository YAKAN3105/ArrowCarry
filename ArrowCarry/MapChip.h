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
	void Draw();

	bool CheckIsHit(Rect rectA,Rect rectB);

	const MapKind GetKind() const { return m_kind; } // �}�b�v�`�b�v�̎��

	const Rect GetRect() const { return m_rect; } // �}�b�v�`�b�v�̔���

private:
	Vec2 m_pos;
	Rect m_rect;

	int m_srcX;
	int m_srcY;
	int m_handle;
	int m_offsetPosY;

	MapKind m_kind;
};
