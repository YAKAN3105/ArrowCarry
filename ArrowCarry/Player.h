#pragma once
#include<math.h>
#include "Vec2.h"
#include"map.h"
#include "Rect.h"

class Map;

class Player
{
public:
	Player(Map* mapPointer);
	~Player();

	void Init();
	void End();
	void Update();
	void AnimationUpdate();
	void Draw();

	Rect GetRect() const { return m_rect; }

	void IsHitArrow();
	
	void OnArrow(Vec2 vec);

	
	// 速度を0にする
	void InitVelocity(); 
	void ChangePosMapHit();



private:

	Map* m_pMap;
	Vec2  m_pos;
	Vec2 m_backPos;
	Vec2 m_velocity;
	
	float m_speed;

	float m_jumpPower;

	bool m_isJumpNow;	//ジャンプした瞬間かどうか
	bool m_isFalling; //落下中かどうか
	bool m_isMapHit;//マップにあたっているかどうか

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

