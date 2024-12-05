#pragma once
#include "MapChip.h"

namespace
{
	//const char* const FILE_NAME = "data/MapChip1.fmf";
}

class Map
{
public:
	Map(Player* playerPointer);
	~Map();

	void Init();
	void End();
	void Update();
	void Draw();
	
	int GetLeft(int x);
	int GetTop(int y);
	int GetRight(int x);
	int GetBottom(int y);
	void CheckHit();

private:

	bool IsHit(int x, int y);

	// �}�b�v�ƃv���C���[�������������Ƃ�`����
	void ChangePlayerHitFlag();

private:

	Player* m_pPlayer;

	// �O���t�B�b�N�̃n���h��
	int m_handle;

	// �O���t�B�b�N�Ƀ`�b�v�������܂܂�Ă��邩
	int m_graphChipNumX;
	int m_graphChipNumY;

	std::vector<unsigned __int8>m_data;

	int m_fileSize; // �O���t�@�C���̑傫����ۑ����邽�߂̕ϐ�

	int m_offsetPosY; // �}�b�v�`�b�v�̍��WY�̕⊮


	
};

