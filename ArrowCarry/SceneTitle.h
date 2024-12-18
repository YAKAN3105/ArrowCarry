#pragma once
#include "SceneBase.h"
class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	~SceneTitle();

	void Init();
	void Update();
	void Draw();
private:

	// グラフィックのハンドル
	int m_handle;
};

