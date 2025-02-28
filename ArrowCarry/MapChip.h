#pragma once
#include "Rect.h"
#include "Vec2.h"

class Map;
class MapChip
{
public:
	MapChip();
	~MapChip();

	void Init(Vec2 pos,int handle);
	void End();
	void Update();
	void Draw();

private:

	

	Rect m_rect;// 矩形情報
	Vec2 m_pos;	// 中心座標

	int m_chipKind;

	int m_handle1;
};

