#include "SceneGame.h"
#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneResult.h"

namespace
{
	
}

SceneGame::SceneGame()
{
	m_pPlayer= new Player;
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
	m_pMap->CheckHit();
	int i = 0;

	m_pArrow->OnPlayerHit();

	if (CheckHitKey(KEY_INPUT_RETURN)) // Enterキーを押すと
	{
		//ChangeScene(new SceneResult); // ResultSceneに引っ越し
		return;
	}
}

void SceneGame::Draw()
{
	m_pMap->Draw();
	m_pArrow->Draw();
	m_pPlayer->Draw();
	DrawFormatString(0, 0, 0xffffff, "SceneGame");// いまゲームシーンにいるよー
}
