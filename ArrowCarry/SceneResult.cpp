#include "SceneResult.h"
#include "SceneTitle.h"
#include "DxLib.h"

SceneResult::SceneResult()
{
}

SceneResult::~SceneResult()
{
}

void SceneResult::Init()
{
}

void SceneResult::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		ChangeScene(new SceneTitle); // タイトルシーンに引っ越しするよ
		return;
	}
}

void SceneResult::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "SceneResult"); // いまリザルトシーンにいるよー
}
