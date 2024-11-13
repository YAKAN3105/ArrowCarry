#include "map.h"
#include <DxLib.h>
#include "game.h"

#include <cassert>

// 定数の定義
namespace
{
	// マップチップ1つのサイズ
	constexpr int kChipWidth = 16;
	constexpr int kChipHeight = 16;

	// マップに敷き詰めるチップの数
	constexpr int kChipNumX = Game::kScreenWidth / kChipWidth;
	constexpr int kChipNumY = Game::kScreenHeight / kChipHeight;

	const char* const FILE_NAME = "data/MapChip1.fmf";

}

// コンストラクタでメンバ変数の初期化を行う
// コンストラクタ初期化子を使用して初期化する
Map::Map():
	m_handle(-1),
	m_graphChipNumX(0),
	m_graphChipNumY(0)
{
}

Map::~Map()
{
}

void Map::Init()
{
	// グラフィックの読み込みをする
	m_handle = LoadGraph("data/image1/Sprites/Tiles/Terrain.png");// 素材を持ってくる
	assert(m_handle != -1);	 // 読み込んでるかのチェックをする

	// 読み込んだグラフィックにチップが何個あるかを教えておく
	int graph;
	//fmfファイルの読み込み
	std::ifstream ifs(FILE_NAME);

	//ファイルが開けなかった場合
	if (!ifs)
	{
		//エラーメッセージを表示
		std::cerr << "Error: file not opened." << std::endl;
	}

}

void Map::End()
{
	// メモリの解放
	DeleteGraph(m_handle);
}

void Map::Update()
{
}

void Map::Draw()
{

	// 画面全体を紫で塗りつぶす
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(206, 128, 255), true);
}
