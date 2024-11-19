#pragma once
#include "SceneBase.h"
#include"Player.h"
#include "Arrow.h"
#include "map.h"
class SceneGame : public SceneBase
{
public:
	SceneGame();
	virtual ~SceneGame();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;

private:
	// ‰Šú‰»
	Player* player;
	Arrow* arrow;
	Map* map;
};