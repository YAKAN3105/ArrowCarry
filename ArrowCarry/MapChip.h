#pragma once
#include"Rect.h"

class MapChip
{

	MapChip();
	~MapChip();

	void Init();
	void Draw();

	bool CheckIsHit(Rect rectA,Rect rectB);

private:
	

};
