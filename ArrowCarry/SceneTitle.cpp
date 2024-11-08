#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
}

void SceneTitle::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN)) // Enterキーを押すと
	{
		ChangeScene(new SceneGame);// ゲームシーンに引っ越しするよー
		return;
	}
}

void SceneTitle::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "SceneTitle");// いまタイトルシーンにいるよー
}
