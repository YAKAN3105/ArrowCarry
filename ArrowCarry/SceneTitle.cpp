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
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		ChangeScene(new SceneGame);
		return;
	}
}

void SceneTitle::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "SceneTitle");
}
