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

	void IsHitArrow();

	

private:

	Vec2  m_pos;
	
	float m_speed;

	float m_jumpPower;

	bool m_isJump;

	bool m_lastJump;

	// アニメーション関連
	int m_animFrame; // フレーム数を数える
	// 現在再生中のアニメーション
	// true:走っている false:待機
	bool m_isRun;	// 変数

	// playerが左を向いているかどうか
	// true:左向き　false:右向き
	bool m_isDirLeft;	// 変数
 
	// グラフィックハンドル
	int m_handleIdle;
	int m_handleRun;

	int m_playerNowPos;
	

};

