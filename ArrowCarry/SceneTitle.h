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

	// �O���t�B�b�N�̃n���h��
	int m_handle;
};

