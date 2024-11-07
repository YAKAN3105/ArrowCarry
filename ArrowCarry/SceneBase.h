#pragma once
class SceneBase
{
public:
	SceneBase() { m_next = this; }	//this���g�̃|�C���^
	~SceneBase() {};

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Draw() abstract;

	/// <summary>
	/// �����z������
	/// </summary>
	/// <param name="next">�����z����̏Z��</param>
	void ChangeScene(SceneBase* next) { m_next = next; }

	SceneBase* m_next;	// �ŏ��A�����̉Ƃ̏Z��
};

