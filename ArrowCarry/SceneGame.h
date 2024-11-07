#pragma once
#include "SceneBase.h"
class SceneGame : public SceneBase
{
public:
	SceneGame() {};
	~SceneGame() {};

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() override;

};