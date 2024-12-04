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
	void CheckHit();
	// rect1���v���C���[rect2�����Ƃ��}�b�v�`�b�v
	bool IsBoxHit(const Rect& rect1, const Rect& rect2);
	 
	// ������
	Player* m_pPlayer;
	Arrow* m_pArrow;
	Map* m_pMap;
};