#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"
#include "game.h"
#include <cassert>

SceneTitle::SceneTitle():
m_handle(-1)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	// グラフィックの読み込みをする
	m_handle = LoadGraph("data/Title.png");
	assert(m_handle != -1);
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
	// タイトル画面の描画
	DrawGraph(Game::kScreenWidth, Game::kScreenHeight, m_handle, false);
	DrawFormatString(0, 0, 0xffffff, "SceneTitle");// いまタイトルシーンにいるよー
}
