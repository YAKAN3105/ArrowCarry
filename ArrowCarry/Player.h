#pragma once
#include "Vec2.h"
class Player
{
public:
	Player();
	~Player();

	void Init();
	void End();
	void Update();
	void Draw();

	// プレイヤーの位置情報を取得する
	float GetLeft()const;
	float GetTop()const;
	float GetRight()const;
	float GetBottom()const;

	struct Position
	{
		int x;
		int y;
	};

private:
	Position pos;

	int radius;
	float speed;

	// グラフィックハンドル
	int m_handleIdle;
	int m_handleRun;


	

};

