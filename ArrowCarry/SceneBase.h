#pragma once
class SceneBase
{
public:
	SceneBase() { m_next = this; }	//this©g‚Ìƒ|ƒCƒ“ƒ^
	~SceneBase() {};

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Draw() abstract;

	/// <summary>
	/// ˆø‚Á‰z‚µ‚·‚é
	/// </summary>
	/// <param name="next">ˆø‚Á‰z‚µæ‚ÌZŠ</param>
	void ChangeScene(SceneBase* next) { m_next = next; }

	SceneBase* m_next;	// Å‰A©•ª‚Ì‰Æ‚ÌZŠ
};

