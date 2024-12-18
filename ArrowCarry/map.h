#pragma once
#include <vector>
#include "MapChip.h"
#include <memory>

namespace
{
	//const char* const FILE_NAME = "data/MapChip1.fmf";
}

class Map
{
public:
	Map();
	~Map();

	void Init();
	void End();
	void Update();
	void Draw();
	

	MapKind GetKind(int x, int y);
	Rect GetRect(int x, int y);
	int GetChipIndexX();
	int GetChipIndexY();

private:

	

	// �}�b�v�ƃv���C���[�������������Ƃ�`����
	void ChangePlayerHitFlag();

private:

	// �O���t�B�b�N�̃n���h��
	int m_handle;

	// �O���t�B�b�N�Ƀ`�b�v�������܂܂�Ă��邩
	int m_graphChipNumX;
	int m_graphChipNumY;

	std::vector<unsigned __int8>m_data;

	int m_mapchip;

	int m_offsetPosY;

	int m_fileSize; // �O���t�@�C���̑傫����ۑ����邽�߂̕ϐ�


	std::vector<MapChip*> m_pMapChip;
};

