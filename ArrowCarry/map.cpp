#include "map.h"
#include <DxLib.h>
#include <vector>
#include <cassert>
#include <string>
#include <fstream>
#include"Player.h"
#include"game.h"
#include "MapChip.h"


namespace
{
	// マップチップの要素数
	constexpr int kChipIndexX = 40;
	constexpr int kChipIndexY = 32;

	// パーツの選択範囲
	constexpr int kPartsNumX = 16;
	constexpr int kPartsNumY = 16;

	// マップチップ1つのサイズ
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;
}

// 定数の定義
namespace
{
	// マップに敷き詰めるチップの数
	//constexpr int kChipNumX = Game::kScreenWidth / kChipWidth;
	//constexpr int kChipNumY = Game::kScreenHeight / kChipHeight;

	const char* const FILE_NAME = "data/Mapdata1.fmf";

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
	m_handle = LoadGraph("data/image1/Sprites/Tiles/aaa.jpg");// 素材を持ってくる
	assert(m_handle != -1);	 // 読み込んでるかのチェックをする

	//// 読み込んだグラフィックにチップが何個あるかを教えておく
	//int graph;
	////fmfファイルの読み込み
	//std::ifstream ifs(FILE_NAME);

	////ファイルが開けなかった場合
	//if (!ifs)
	//{
	//	//エラーメッセージを表示
	//	assert(false);
	//}

	////読込サイズを調べる
	//ifs.seekg(0, std::ios::end);
	//m_filesize = ifs.tellg();
	//ifs.seekg(0);

	//printfDx("size:%d\n", m_filesize);

	////20バイト分の無駄なデータを読み飛ばす
	////なぜか最初の20バイトが無駄なデータになっている(ごみ)
	//for (int i = 0; i < 20; i++)
	//{
	//	char tmp;
	//	//1バイトずつ読み込む(計20バイト読み込む)
	//	ifs.read(&tmp, sizeof(char));
	//}

	////データを読み込む(実際に読み込みたいデータ)
	//for (int i = 0; i < m_filesize - 20; i++)
	//{
	//	char tmp;
	//	ifs.read(&tmp, sizeof(char));
	//	m_data.push_back(tmp);
	//}

	//ifs.close();

	//fmfファイルの読み込み
	std::ifstream ifs(FILE_NAME);

	//ファイルが開けなかった場合
	if (!ifs)
	{
		//エラーメッセージを表示
		assert(false && "Error: file not opened.");
		//return 1;
	}

	//読込サイズを調べる
	ifs.seekg(0, std::ios::end);
	int size = ifs.tellg();
	ifs.seekg(0);

	//サイズを表示
	printfDx("size: %d\n", size);

	//20バイト分の無駄なデータを読み飛ばす
	//なぜか最初の20バイトが無駄なデータになっている(ごみ)
	for (int i = 0; i < 20; i++)
	{
	     char tmp;
		//1バイトずつ読み込む(計20バイト読み込む)
		ifs.read(&tmp, sizeof(char));
	}

	//データを読み込む(実際に読み込みたいデータ)
	std::vector<char> data;

	while (true)
	{
		unsigned __int8 tmp;
		ifs.read((char*)&tmp, sizeof(char));

		MapChip* mapchip = new MapChip;	
		mapchip->Init(tmp);

		m_pMapChip.push_back(mapchip);

		m_data.push_back(tmp);

		size--;

		if (size <= 0)
		{
			break;
		}
	}

	//データを表示
	for (int i = 0; i < data.size(); i++)
	{
		printfDx("配列番号%d:%d", i, static_cast<int>(data[i]));
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
	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			m_pMapChip[y * kChipIndexX + x]->Draw(m_handle, x, y);
		}
	}

	//DrawGraph(0, 0, m_handle, true);


	//マップチップ当たり判定用の描画
	for (int y = 0; y < kChipIndexY; y++)
	{
		for (int x = 0; x < kChipIndexX; x++)
		{
			m_pMapChip[y * kChipIndexX + x]->DebugDraw();

			// データから配置するチップを決定する
			// 二重配列の場合でも、vector配列を先頭から順番に見ていくための処理
			int chipNo = m_data[(y * kChipIndexX) + x];

			if (chipNo < 0)
			{
				// continueは繰り返し文(for,while)の中で使用する命令
				// continueが呼ばれたら以降の繰り返し処理は行わず次のループに移行する
				continue;
			}

			// 0から始まる通し番号を
			// 上から何個目、左から何個目なのか、という情報に変換する必要がある
			// グラフィックに何個チップが含まれているか、という情報を使用して
			// 計算で求める
			int indexX = chipNo % kPartsNumX; // 左から何個目のチップか
			int indexY = chipNo / kPartsNumY; // 上から何個目のチップか


			// チップ番号から切り出し位置を計算する
			int cutX = indexX * kChipWidth; // インデックスX番号を用いたマップチップの位置を示す変数
			int cutY = indexY * kChipHeight; // インデックスY番号を用いたマップチップの位置を示す変数


			m_offsetPosY = kChipHeight * kChipIndexY - Game::kScreenHeight;

			const auto& mapRect = m_pMapChip[y * kChipIndexX + x]->GetRect();	//1次変数
			DrawBox(
				mapRect.GetLeft(),				// グラフィックを描画する座標
				mapRect.GetTop(),
				mapRect.GetRight(),
				mapRect.GetBottom(),	// 描画するグラフィックのサイズ
				0xff0000,
				false);
		}
	}
}




MapKind Map::GetKind(int x, int y)
{
	return m_pMapChip[y * kChipIndexX + x]->GetKind();
}

Rect Map::GetRect(int x, int y)
{
	return m_pMapChip[y * kChipIndexX + x]->GetRect();
}

int Map::GetChipIndexX()
{
	return kChipIndexX;
}

int Map::GetChipIndexY()
{
	return kChipIndexY;
}




void Map::ChangePlayerHitFlag()
{
	printfDx("あたってるー\n");
	// プレイヤーに当たったことを伝える
	//m_pPlayer->ChangeHitMap();
}
