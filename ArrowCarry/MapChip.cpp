#include "MapChip.h"
#include "DxLib.h"
#include "game.h"
#include "Map.h"
#include <vector>
#include "Player.h"

namespace
{
	// �}�b�v�`�b�v1�̃T�C�Y
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;

	// �}�b�v�`�b�v�̗v�f��
	constexpr int kChipIndexX = 40;	
	constexpr int kChipIndexY = 32;

	constexpr int kOffsetY = kChipHeight * kChipIndexY - Game::kScreenHeight;
}

MapChip::MapChip(Player* m_pPlayer):
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

void MapChip::DebugDraw()
{
}

bool MapChip::IsHit(int x, int y)
{
	if ((GetRect().GetLeft() < m_pPlayer->GetRect().GetRight() &&
		GetRect().GetRight() > m_pPlayer->GetRect().GetLeft() &&
		GetRect().GetTop() < m_pPlayer->GetRect().GetBottom() &&
		GetRect().GetBottom() > m_pPlayer->GetRect().GetTop()))
	{
		return true;
	}
	return false;

	return false;
}