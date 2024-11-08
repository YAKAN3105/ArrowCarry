#include "SceneGame.h"
#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneResult.h"

void SceneGame::Init()
{
}

void SceneGame::Update()
{
	int i = 0;

	if (CheckHitKey(KEY_INPUT_RETURN)) // Enterキーを押すと
	{
		ChangeScene(new SceneResult); // ResultSceneに引っ越し
		return;
	}
}

void SceneGame::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "SceneGame");// いまゲームシーンにいるよー
}
