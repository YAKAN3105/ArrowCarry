#pragma once

class Map;

class SceneBase
{
public:
	SceneBase() { m_next = this; }	//this自身のポインタ
	virtual ~SceneBase() {};

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Draw() abstract;

	/// <summary>
	/// 引っ越しする
	/// </summary>
	/// <param name="next">引っ越し先の住所</param>
	void ChangeScene(SceneBase* next) 
	{
		m_next = next;
		m_next->Init();
	}

	SceneBase* m_next;	// 最初、自分の家の住所
};

