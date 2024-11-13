#include "map.h"
#include <DxLib.h>
#include "game.h"

#include <cassert>

// �萔�̒�`
namespace
{
	// �}�b�v�`�b�v1�̃T�C�Y
	constexpr int kChipWidth = 16;
	constexpr int kChipHeight = 16;

	// �}�b�v�ɕ~���l�߂�`�b�v�̐�
	constexpr int kChipNumX = Game::kScreenWidth / kChipWidth;
	constexpr int kChipNumY = Game::kScreenHeight / kChipHeight;

	const char* const FILE_NAME = "data/MapChip1.fmf";

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
	m_handle = LoadGraph("data/image1/Sprites/Tiles/Terrain.png");// �f�ނ������Ă���
	assert(m_handle != -1);	 // �ǂݍ���ł邩�̃`�F�b�N������

	// �ǂݍ��񂾃O���t�B�b�N�Ƀ`�b�v�������邩�������Ă���
	int graph;
	//fmf�t�@�C���̓ǂݍ���
	std::ifstream ifs(FILE_NAME);

	//�t�@�C�����J���Ȃ������ꍇ
	if (!ifs)
	{
		//�G���[���b�Z�[�W��\��
		std::cerr << "Error: file not opened." << std::endl;
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
}
