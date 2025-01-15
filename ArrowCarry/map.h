#pragma once
class MapChip;

class Map
{
public:
	Map();
	~Map();

	void Init();
	void Update();
	void Draw();

private:
	int m_handle1;
	MapChip* m_mapChips[kChipIndexY][kChipIndexX];

};

