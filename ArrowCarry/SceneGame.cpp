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

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		ChangeScene(new SceneResult); // ResultScene‚Éˆø‚Á‰z‚µ
		return;
	}
}

void SceneGame::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "SceneGame");
}
