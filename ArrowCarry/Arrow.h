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

	// –î‚Ìî•ñ‚ğæ“¾‚·‚é
	float GetLeft();
	float GetTop();
	float GetRight();
	float GetBottom();
	void OnPlayerHit();

	struct Position
	{
		int Top;
		int Bottom;
		int Left;
		int Right;
	};

private:

	
	Player* m_pPlayer;
	Position m_pos;
	int m_radius;

	int m_handleUpArrow;
	int m_handleLeftArrow;
	int m_handleRightArrow;


};

