#include "map.h"
#include <DxLib.h>
#include "game.h"

#include <cassert>

// �萔�̒�`
namespace
{
	// �}�b�v�`�b�v1��
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
	// ��ʑS�̂����œh��Ԃ�
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(206, 128, 255), true);
}
