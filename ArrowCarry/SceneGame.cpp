#include "SceneGame.h"
#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneResult.h"
#include"Player.h"
#include "Arrow.h"
#include "map.h"
#include "Rect.h"
#include "game.h"

namespace
{
	
}

SceneGame::SceneGame()
{
	m_pPlayer= new Player();
	m_pArrow = new Arrow();
	m_pMap = new Map();
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

	CheckMapHit();

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
	// 画面全体を紫で塗りつぶす
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(206, 128, 255), true);
	m_pMap->Draw();
	m_pArrow->Draw();
	m_pPlayer->Draw();
	DrawFormatString(0, 0, 0xffffff, "SceneGame");// いまゲームシーンにいるよー
}

//void SceneGame::CheckMapHit()
//{
//	for (int x = 0; x < m_pMap->GetChipIndexX(); x++)
//	{
//		for (int y = 0; y < m_pMap->GetChipIndexY(); y++)
//		{
//			// プレイヤーと全マップチップとの当たり判定
//			if (IsBoxHit(m_pPlayer->GetRect(), m_pMap->GetRect(x, y)))
//			{
//				// どこのマップの種類(Kind)なのかを呼ぶ
//				const auto kind = m_pMap->GetKind(x, y); 
//
//				if (kind == MapKind::kGoal)
//				{
//					// クリア処理
//					ChangeScene(new SceneResult); // ResultSceneに引っ越し
//					return;
//				}
//				else if (kind == MapKind::kChip)
//				{
//					// 押し出し処理
//
//				}
//
//			}
//		}
//	}
//	
//}

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
