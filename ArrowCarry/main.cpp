#include "DxLib.h"
#include "game.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneResult.h"



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部のDxLib関数はDxLib_Init()の前に呼ぶ必要がある

	// フルスクリーンではなく、ウィンドウモードで開く
	ChangeWindowMode(Game::kDefaultWindowMode);
	// 画面のサイズを変更する
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorBitNum);

	SetWindowText("あいうえお");
	

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// *でポインタを指定する
	SceneBase* scene;

	scene = new SceneTitle; // 最初に住んでいるところ

	scene->Init();
	

	

	//scene = new SceneGame;

	//scene = new SceneResult;

	// ゲームループ
	while (ProcessMessage() == 0) // Windowsが行う処理を待つ
	{
		
		// 今回のループが始まった時間を覚えておく
		LONGLONG time = GetNowHiPerformanceCount();

		// 画面全体をクリアする
		ClearDrawScreen();

		// ここにゲームの処理を書く
		
		
		scene->Update(); // 引っ越し先を決める
		
		scene->Draw();
		

		if (scene != scene->m_next)
		{
			SceneBase* next = scene->m_next; // 引っ越し先の住所の確定

			delete scene; // 元住んでいた住所を(delete)壊す
			scene = nullptr; // 何も住む場所がない状態

			scene = next; // 次のシーンに引っ越しする
		}


		// 画面の切り替わりを待つ必要がある
		ScreenFlip();

		// FPS60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}