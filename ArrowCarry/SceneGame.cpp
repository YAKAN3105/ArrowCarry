#include "SceneGame.h"
#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneResult.h"

namespace
{
	
}

SceneGame::SceneGame()
{
	player= new Player;
	arrow = new Arrow(player);
	map = new Map;
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	player->Init();
	arrow->Init();
	map->Init();
}

void SceneGame::Update()
{
	player->Update();

	arrow->Update();
	map->Update();
	int i = 0;

	arrow->OnPlayerHit();

	if (CheckHitKey(KEY_INPUT_RETURN)) // Enter�L�[��������
	{
		//ChangeScene(new SceneResult); // ResultScene�Ɉ����z��
		return;
	}
}

void SceneGame::Draw()
{
	map->Draw();
	arrow->Draw();
	player->Draw();
	DrawFormatString(0, 0, 0xffffff, "SceneGame");// ���܃Q�[���V�[���ɂ����[
}
