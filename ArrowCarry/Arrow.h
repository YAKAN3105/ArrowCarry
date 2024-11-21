#pragma once

class Player;

class Arrow
{
public:
	Arrow(Player* playerPointer);
	~Arrow();

	void Init();
	void Update();
	void Draw();

	// ��̏����擾����
	float GetLeft();
	float GetTop();
	float GetRight();
	float GetBottom();

	struct Position
	{
		int Top;
		int Bottom;
		int Left;
		int Right;
	};

private:

	void OnPlayerHit();
	Player* pPlayer;
	Position m_pos;
	int radius;


};

