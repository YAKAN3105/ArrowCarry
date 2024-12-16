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

	//// �ǂݍ��񂾃O���t�B�b�N�Ƀ`�b�v�������邩�������Ă���
	//int graph;
	////fmf�t�@�C���̓ǂݍ���
	//std::ifstream ifs(FILE_NAME);

	////�t�@�C�����J���Ȃ������ꍇ
	//if (!ifs)
	//{
	//	//�G���[���b�Z�[�W��\��
	//	assert(false);
	//}

	////�Ǎ��T�C�Y�𒲂ׂ�
	//ifs.seekg(0, std::ios::end);
	//m_filesize = ifs.tellg();
	//ifs.seekg(0);

	//printfDx("size:%d\n", m_filesize);

	////20�o�C�g���̖��ʂȃf�[�^��ǂݔ�΂�
	////�Ȃ����ŏ���20�o�C�g�����ʂȃf�[�^�ɂȂ��Ă���(����)
	//for (int i = 0; i < 20; i++)
	//{
	//	char tmp;
	//	//1�o�C�g���ǂݍ���(�v20�o�C�g�ǂݍ���)
	//	ifs.read(&tmp, sizeof(char));
	//}

	////�f�[�^��ǂݍ���(���ۂɓǂݍ��݂����f�[�^)
	//for (int i = 0; i < m_filesize - 20; i++)
	//{
	//	char tmp;
	//	ifs.read(&tmp, sizeof(char));
	//	m_data.push_back(tmp);
	//}

	//ifs.close();

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

	while (true)
	{
		char tmp;
		ifs.read(&tmp, sizeof(char));

		auto mapchip = new MapChip;
		mapchip->Init(tmp);

		m_data.push_back(tmp);

		size--;

		if (size <= 0)
		{
			break;
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
	
}


void Map::CheckHit()
{
	
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

bool Map::IsHit(int x, int y)
{
	if ((GetRect(x,y) < m_pPlayer->GetRight() &&
		GetRect(x,y) > m_pPlayer->GetLeft() &&
		GetRect(x,y) < m_pPlayer->GetBottom() &&
		GetRect(x,y) > m_pPlayer->GetTop()))
	{
		return true;
	}
	return false;
}

void Map::ChangePlayerHitFlag()
{
	printfDx("�������Ă�[\n");
	// �v���C���[�ɓ����������Ƃ�`����
	m_pPlayer->ChangeHitMap();
}
