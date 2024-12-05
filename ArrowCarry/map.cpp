#include "map.h"
#include <DxLib.h>
#include<vector>
#include <cassert>
#include<string>
#include"Player.h"
#include"game.h"


// �萔�̒�`
namespace
{
	// �}�b�v�`�b�v1�̃T�C�Y
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;


	constexpr int kPartsNumX = 16; // �p�[�c�̑I��͈�
	constexpr int kPartsNumY = 16;

	constexpr int kChipIndexX = 40;	// �}�b�v�`�b�v�̗v�f��
	constexpr int kChipIndexY = 32;

	// �}�b�v�ɕ~���l�߂�`�b�v�̐�
	//constexpr int kChipNumX = Game::kScreenWidth / kChipWidth;
	//constexpr int kChipNumY = Game::kScreenHeight / kChipHeight;

	const char* const FILE_NAME = "data/Mapdata1.fmf";

}



// �R���X�g���N�^�Ń����o�ϐ��̏��������s��
// �R���X�g���N�^�������q���g�p���ď���������
Map::Map(Player*playerPointer):
	m_pPlayer(playerPointer),
	m_handle(-1),
	m_graphChipNumX(0),
	m_graphChipNumY(0),
	m_offsetPosY(kChipHeight* kChipIndexY - Game::kScreenHeight)
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
		std::cerr << "Error: file not opened." << std::endl;
		//return 1;
	}

	//�Ǎ��T�C�Y�𒲂ׂ�
	ifs.seekg(0, std::ios::end);
	int size = ifs.tellg();
	ifs.seekg(0);

	//�T�C�Y��\��
	std::cout << "size: " << size << std::endl;

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
		std::cout << "�z��ԍ�" << i << " : " << static_cast<int>(data[i]) << std::endl;
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
	// ��ʑS�̂����œh��Ԃ�
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(206, 128, 255), true);

	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			// �f�[�^����z�u����`�b�v�����肷��
			// ��d�z��̏ꍇ�ł��Avector�z���擪���珇�ԂɌ��Ă������߂̏���
			int chipNo = m_data[(y * kChipIndexX) + x];

			if (chipNo < 0)
			{
				// continue�͌J��Ԃ���(for,while)�̒��Ŏg�p���閽��
				// continue���Ă΂ꂽ��ȍ~�̌J��Ԃ������͍s�킸���̃��[�v�Ɉڍs����
				continue;
			}

			// 0����n�܂�ʂ��ԍ���
			// �ォ�牽�ځA�����牽�ڂȂ̂��A�Ƃ������ɕϊ�����K�v������
			// �O���t�B�b�N�ɉ��`�b�v���܂܂�Ă��邩�A�Ƃ��������g�p����
			// �v�Z�ŋ��߂�
			int indexX = chipNo % kPartsNumX; // �����牽�ڂ̃`�b�v��
			int indexY = chipNo / kPartsNumY; // �ォ�牽�ڂ̃`�b�v��


			// �`�b�v�ԍ�����؂�o���ʒu���v�Z����
			int cutX = indexX * kChipWidth; // �C���f�b�N�XX�ԍ���p�����}�b�v�`�b�v�̈ʒu�������ϐ�
			int cutY = indexY * kChipHeight; // �C���f�b�N�XY�ԍ���p�����}�b�v�`�b�v�̈ʒu�������ϐ�


			 


			DrawRectGraph
			(x * kChipWidth,				// �O���t�B�b�N��`�悷����W
				y * kChipHeight - m_offsetPosY,
				cutX, cutY,					// �`�悷��O���t�B�b�N��̕`�悵������`�̍�����W
				kChipWidth, kChipHeight,	// �`�悷��O���t�B�b�N�̃T�C�Y
				m_handle, true);			// ���ߏ������邩�ǂ���
		}
	}


	//�}�b�v�`�b�v�����蔻��p�̕`��
	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			// �f�[�^����z�u����`�b�v�����肷��
			// ��d�z��̏ꍇ�ł��Avector�z���擪���珇�ԂɌ��Ă������߂̏���
			int chipNo = m_data[(y * kChipIndexX) + x];

			if (chipNo < 0)
			{
				// continue�͌J��Ԃ���(for,while)�̒��Ŏg�p���閽��
				// continue���Ă΂ꂽ��ȍ~�̌J��Ԃ������͍s�킸���̃��[�v�Ɉڍs����
				continue;
			}

			// 0����n�܂�ʂ��ԍ���
			// �ォ�牽�ځA�����牽�ڂȂ̂��A�Ƃ������ɕϊ�����K�v������
			// �O���t�B�b�N�ɉ��`�b�v���܂܂�Ă��邩�A�Ƃ��������g�p����
			// �v�Z�ŋ��߂�
			int indexX = chipNo % kPartsNumX; // �����牽�ڂ̃`�b�v��
			int indexY = chipNo / kPartsNumY; // �ォ�牽�ڂ̃`�b�v��


			// �`�b�v�ԍ�����؂�o���ʒu���v�Z����
			int cutX = indexX * kChipWidth; // �C���f�b�N�XX�ԍ���p�����}�b�v�`�b�v�̈ʒu�������ϐ�
			int cutY = indexY * kChipHeight; // �C���f�b�N�XY�ԍ���p�����}�b�v�`�b�v�̈ʒu�������ϐ�


			m_offsetPosY = kChipHeight * kChipIndexY - Game::kScreenHeight;


			DrawBox(
				GetLeft(x),				// �O���t�B�b�N��`�悷����W
				GetTop(y),
				GetRight(x),
				GetBottom(y),	// �`�悷��O���t�B�b�N�̃T�C�Y
				0xff0000,
				false);
		}
	}
}

int Map::GetLeft(int x)
{
	return x *kChipWidth;	// �}�b�v�`�b�v�̍����̍��W
}

int Map::GetTop(int y)
{
	return y* kChipHeight- m_offsetPosY;	// �}�b�v�`�b�v��
}

int Map::GetRight(int x)
{
	return x* kChipWidth + kChipWidth;
}

int Map::GetBottom(int y)
{
	return y* kChipHeight - kChipHeight - m_offsetPosY;
}

void Map::CheckHit()
{
	bool a = false;

	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			// �f�[�^����z�u����`�b�v�����肷��
			// ��d�z��̏ꍇ�ł��Avector�z���擪���珇�ԂɌ��Ă������߂̏���
			int chipNo = m_data[(y * kChipIndexX) + x];

			if (chipNo < 0 || chipNo == 243)
			{
				// continue�͌J��Ԃ���(for,while)�̒��Ŏg�p���閽��
				// continue���Ă΂ꂽ��ȍ~�̌J��Ԃ������͍s�킸���̃��[�v�Ɉڍs����
				continue;
			}

			// �����Ƀv���C���[�ƃ}�b�v���������Ă��邩�̔�����s��
			// �������Ă��Ȃ������玟�̃}�b�v�`�b�v��
			if (!IsHit( x, y))
			{
				continue;
			}

			// �����܂ŗ����瓖�����Ă���
			// �ʒu���C�����Ă�����
			ChangePlayerHitFlag();

			a = true;
		}
	}

	if (!a)
	{
		printfDx("�������ĂȂ�\n");
	}
}

bool Map::IsHit(int x, int y)
{
	if ((GetLeft(x) < m_pPlayer->GetRight() &&
		GetRight(x) > m_pPlayer->GetLeft() &&
		GetTop(y) < m_pPlayer->GetBottom() &&
		GetBottom(y) > m_pPlayer->GetTop()))
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
