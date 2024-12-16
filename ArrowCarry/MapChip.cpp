#include "MapChip.h"
#include "DxLib.h"
#include "game.h"
#include "map.h"

namespace
{
	// �}�b�v�`�b�v1�̃T�C�Y
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;

	// �p�[�c�̑I��͈�
	constexpr int kPartsNumX = 16; 
	constexpr int kPartsNumY = 16;

	// �}�b�v�`�b�v�̗v�f��
	constexpr int kChipIndexX = 40;	
	constexpr int kChipIndexY = 32;

	constexpr int kOffsetY = kChipHeight * kChipIndexY - Game::kScreenHeight;
}

MapChip::MapChip():
m_handle(-1)
{
}

MapChip::~MapChip()
{
}

void MapChip::Init(int no)
{
	// 0����n�܂�ʂ��ԍ���
	// �ォ�牽�ځA�����牽�ڂȂ̂��A�Ƃ������ɕϊ�����K�v������
	// �O���t�B�b�N�ɉ��`�b�v���܂܂�Ă��邩�A�Ƃ��������g�p����
	// �v�Z�ŋ��߂�
	m_srcX = no % Game:: kScreenWidth;
	m_srcY = no / Game::kScreenHeight;
}

void MapChip::Draw()
{
	
	// �`�b�v�ԍ�����؂�o���ʒu���v�Z����
	int cutX = m_srcX * kChipWidth; // �C���f�b�N�XX�ԍ���p�����}�b�v�`�b�v�̈ʒu�������ϐ�
	int cutY = m_srcY * kChipHeight; // �C���f�b�N�XY�ԍ���p�����}�b�v�`�b�v�̈ʒu�������ϐ�
	
	DrawRectGraph
	(m_pos.x * kChipWidth,				// �O���t�B�b�N��`�悷����W
	m_pos.y * kChipHeight - kOffsetY,
	cutX, cutY,					// �`�悷��O���t�B�b�N��̕`�悵������`�̍�����W
	kChipWidth, kChipHeight,	// �`�悷��O���t�B�b�N�̃T�C�Y
	m_handle, true);			// ���ߏ������邩�ǂ���

	// ��ʑS�̂����œh��Ԃ�
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(206, 128, 255), true);

	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			m_pMapChip[y * kChipIndexX + x]->Draw();
		}
	}


	//�}�b�v�`�b�v�����蔻��p�̕`��
	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			m_pMapChip[y * kChipIndexX + x]->DebugDraw();

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

bool MapChip::CheckIsHit(Rect rectA, Rect rectB)
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
			if (!IsHit(x, y))
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
	return false;
}
