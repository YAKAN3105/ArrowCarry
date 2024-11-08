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
	if (CheckHitKey(KEY_INPUT_RETURN)) // Enter�L�[��������
	{
		ChangeScene(new SceneGame);// �Q�[���V�[���Ɉ����z�������[
		return;
	}
}

void SceneTitle::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "SceneTitle");// ���܃^�C�g���V�[���ɂ����[
}
