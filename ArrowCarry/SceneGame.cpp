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

void SceneGame::CheckHit()
{
	// プレイヤーと全マップチップとの当たり判定
	
	// プレイヤーと全矢印との当たり判定
	
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
