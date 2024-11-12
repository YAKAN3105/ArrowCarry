#include "map.h"
#include <DxLib.h>
#include "game.h"

#include <cassert>

// 定数の定義
namespace
{
	// マップチップ1つ
}

Map::Map()
{
}

Map::~Map()
{
}

void Map::Init()
{
}

void Map::End()
{
}

void Map::Update()
{
}

void Map::Draw()
{
	// 画面全体を紫で塗りつぶす
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(206, 128, 255), true);
}
