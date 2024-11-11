#pragma once
class Arrow
{
public:
	Arrow();
	~Arrow();

	void Init();
	void Update();
	void Draw();

	// –î‚Ìî•ñ‚ğæ“¾‚·‚é
	float GetLeft();
	float GetTop();
	float GetRight();
	float GetBottom();

};

