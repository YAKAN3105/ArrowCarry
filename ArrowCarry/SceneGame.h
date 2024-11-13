#pragma once
#include "SceneBase.h"
#include"Player.h"
#include "Arrow.h"
#include "map.h"
class SceneGame : public SceneBase
{
public:
	SceneGame() {};
	~SceneGame() {};

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;

private:
	// ‰Šú‰»
	Player* player = new Player;
	Arrow* arrow = new Arrow;
	Map* map = new Map;
};