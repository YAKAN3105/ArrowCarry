#pragma once
class Arrow
{
public:
	Arrow();
	~Arrow();

	void Init();
	void Update();
	void Draw();

	// ��̏����擾����
	float GetLeft();
	float GetTop();
	float GetRight();
	float GetBottom();

};

