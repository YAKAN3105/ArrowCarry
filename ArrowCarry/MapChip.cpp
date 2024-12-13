#include "MapChip.h"
#include "DxLib.h"
#include "game.h"

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

MapChip::MapChip()
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
	m_srcX = no % Width;
	m_srcY = no / Height;
}

void MapChip::Draw()
{
	DrawRectGraph(m_pos.x, m_pos.y, m_srcX, m_srcY, );
	


	// �`�b�v�ԍ�����؂�o���ʒu���v�Z����
	int cutX = m_srcX * kChipWidth; // �C���f�b�N�XX�ԍ���p�����}�b�v�`�b�v�̈ʒu�������ϐ�
	int cutY = m_srcY * kChipHeight; // �C���f�b�N�XY�ԍ���p�����}�b�v�`�b�v�̈ʒu�������ϐ�
	
	DrawRectGraph
	(m_pos.x * kChipWidth,				// �O���t�B�b�N��`�悷����W
	m_pos.y * kChipHeight - m_offsetPosY,
	cutX, cutY,					// �`�悷��O���t�B�b�N��̕`�悵������`�̍�����W
	kChipWidth, kChipHeight,	// �`�悷��O���t�B�b�N�̃T�C�Y
	m_handle, true);			// ���ߏ������邩�ǂ���
}

bool MapChip::CheckIsHit(Rect rectA, Rect rectB)
{
	return false;
}
