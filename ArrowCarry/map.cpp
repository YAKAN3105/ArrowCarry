#include "map.h"
#include <DxLib.h>
#include <vector>
#include <cassert>
#include <string>
#include <fstream>
#include"Player.h"
#include"game.h"
#include "MapChip.h"


namespace
{
	// �}�b�v�`�b�v�̗v�f��
	constexpr int kChipIndexX = 40;
	constexpr int kChipIndexY = 32;

	// �p�[�c�̑I��͈�
	constexpr int kPartsNumX = 16;
	constexpr int kPartsNumY = 16;

	// �}�b�v�`�b�v1�̃T�C�Y
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;
}

// �萔�̒�`
namespace
{
	// �}�b�v�ɕ~���l�߂�`�b�v�̐�
	//constexpr int kChipNumX = Game::kScreenWidth / kChipWidth;
	//constexpr int kChipNumY = Game::kScreenHeight / kChipHeight;

	const char* const FILE_NAME = "data/Mapdata1.fmf";

}



// �R���X�g���N�^�Ń����o�ϐ��̏��������s��
// �R���X�g���N�^�������q���g�p���ď���������
Map::Map():
	m_handle(-1),
	m_graphChipNumX(0),
	m_graphChipNumY(0)
{
}

Map::~Map()
{
}

void Map::Init()
{
	// �O���t�B�b�N�̓ǂݍ��݂�����
	m_handle = LoadGraph("data/image1/Sprites/Tiles/aaa.jpg");// �f�ނ������Ă���
	assert(m_handle != -1);	 // �ǂݍ���ł邩�̃`�F�b�N������


	//fmf�t�@�C���̓ǂݍ���
	std::ifstream ifs(FILE_NAME);

	//�t�@�C�����J���Ȃ������ꍇ
	if (!ifs)
	{
		//�G���[���b�Z�[�W��\��
		assert(false && "Error: file not opened.");
		//return 1;
	}

	//�Ǎ��T�C�Y�𒲂ׂ�
	ifs.seekg(0, std::ios::end);
	int size = ifs.tellg();
	ifs.seekg(0);

	//�T�C�Y��\��
	printfDx("size: %d\n", size);

	//20�o�C�g���̖��ʂȃf�[�^��ǂݔ�΂�
	//�Ȃ����ŏ���20�o�C�g�����ʂȃf�[�^�ɂȂ��Ă���(����)
	for (int i = 0; i < 20; i++)
	{
	     char tmp;
		//1�o�C�g���ǂݍ���(�v20�o�C�g�ǂݍ���)
		ifs.read(&tmp, sizeof(char));
	}

	//�f�[�^��ǂݍ���(���ۂɓǂݍ��݂����f�[�^)
	std::vector<char> data;

	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			unsigned _int8 tmp;
			ifs.read((char*)&tmp, sizeof(char));

			MapChip* mapchip = new MapChip;
			mapchip->Init(tmp,x,y,kChipWidth,kChipHeight);
			m_pMapChip.push_back(mapchip);
			// MapChip�������o�ϐ��ɕۑ����Ȃ��Ƃ����Ȃ�
		}
	}
	
	//�f�[�^��\��
	for (int i = 0; i < data.size(); i++)
	{
		printfDx("�z��ԍ�%d:%d", i, static_cast<int>(data[i]));
	}
}

void Map::End()
{
	// �������̉��
	DeleteGraph(m_handle);
}

void Map::Update()
{
}

void Map::Draw()
{
	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			// �}�b�v�`�b�v�̉摜�̕`��
			m_pMapChip[y * kChipIndexX + x]->Draw(m_handle, x, y);
		}
	}

	//DrawGraph(0, 0, m_handle, true);


	//�}�b�v�`�b�v�����蔻��p�̕`��
	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			m_pMapChip[y * kChipIndexX + x]->DebugDraw();


			m_offsetPosY = kChipHeight * kChipIndexY - Game::kScreenHeight;

			const auto& mapRect = m_pMapChip[y * kChipIndexX + x]->GetRect();	//1���ϐ�
			DrawBox(
				mapRect.GetLeft(),				// �O���t�B�b�N��`�悷����W
				mapRect.GetTop(),
				mapRect.GetRight(),
				mapRect.GetBottom(),	// �`�悷��O���t�B�b�N�̃T�C�Y
				0xff0000,
				false);
		}
	}
}




MapKind Map::GetKind(int x, int y)
{
	return m_pMapChip[y * kChipIndexX + x]->GetKind();
}

Rect Map::GetRect(int x, int y)
{
	return m_pMapChip[y * kChipIndexX + x]->GetRect();
}

int Map::GetChipIndexX()
{
	return kChipIndexX;
}

int Map::GetChipIndexY()
{
	return kChipIndexY;
}




void Map::ChangePlayerHitFlag()
{
	printfDx("�������Ă�[\n");
	// �v���C���[�ɓ����������Ƃ�`����
	//m_pPlayer->ChangeHitMap();
}
