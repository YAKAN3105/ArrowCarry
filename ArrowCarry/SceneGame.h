#pragma once
#include "SceneBase.h"

class Map;
class Player;
class Arrow;
class Rect;

class SceneGame : public SceneBase
{
public:
	SceneGame();
	virtual ~SceneGame();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;


private:
	/// <summary>
	/// 
	/// </summary>
	void CheckMapHit();

	/// <summary>
	/// rect1がプレイヤーrect2が矢印とかマップチップ
	/// </summary>
	/// <param name="rect1">当たり判定1</param>
	/// <param name="rect2">当たり判定2</param>
	/// <returns>あたったかどうか</returns>
	bool IsBoxHit(const Rect& rect1, const Rect& rect2);
	 
	// 初期化
	Player* m_pPlayer;
	Arrow* m_pArrow;
	Map* m_pMap;
};