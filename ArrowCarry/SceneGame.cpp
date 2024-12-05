#include "SceneGame.h"
#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneResult.h"
#include"Player.h"
#include "Arrow.h"
#include "map.h"
#include "Rect.h"

namespace
{
	
}

SceneGame::SceneGame()
{
	m_pPlayer= new Player(m_pMap);
	m_pArrow = new Arrow(m_pPlayer);
	m_pMap = new Map(m_pPlayer);
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	m_pPlayer->Init();
	m_pArrow->Init();
	m_pMap->Init();
}

void SceneGame::Update()
{
	m_pPlayer->Update();
	m_pArrow->Update();
	m_pMap->Update();

	CheckHit();

	//m_pMap->CheckHit();
	//int i = 0;

	//m_pArrow->OnPlayerHit();

	if (CheckHitKey(KEY_INPUT_RETURN)) // Enter�L�[��������
	{
		//ChangeScene(new SceneResult); // ResultScene�Ɉ����z��
		return;
	}

}

void SceneGame::Draw()
{
	m_pMap->Draw();
	m_pArrow->Draw();
	m_pPlayer->Draw();
	DrawFormatString(0, 0, 0xffffff, "SceneGame");// ���܃Q�[���V�[���ɂ����[
}

void SceneGame::CheckHit()
{
	// �v���C���[�ƑS�}�b�v�`�b�v�Ƃ̓����蔻��
	
	// �v���C���[�ƑS���Ƃ̓����蔻��
	
}

bool SceneGame::IsBoxHit(const Rect& rect1, const Rect& rect2)
{
	if (rect2.GetLeft() <= rect1.GetRight() &&
		rect2.GetRight() >= rect1.GetLeft() &&
		rect2.GetTop() <= rect1.GetBottom() &&
		rect2.GetBottom() >= rect1.GetTop())
	{
		return true;
	}
	else
	{
		return false;
	}
}
