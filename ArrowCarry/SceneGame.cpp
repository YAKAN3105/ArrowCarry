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

	if (CheckHitKey(KEY_INPUT_RETURN)) // Enter�L�[��������
	{
		ChangeScene(new SceneResult); // ResultScene�Ɉ����z��
		return;
	}
}

void SceneGame::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "SceneGame");// ���܃Q�[���V�[���ɂ����[
}
