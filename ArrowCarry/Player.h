#pragma once
class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	struct Position
	{
		int x;
		int y;
	};

private:
	Position pos;
	int radius;

};

