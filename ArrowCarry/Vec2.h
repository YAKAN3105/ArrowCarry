#pragma once

// 2次元ベクトルクラス
class Vec2
{
public:
	float x;
	float y;

public:
	Vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Vec2(float _x,float _y):
		x(_x),
		y(_y)
	{

	}
};

//演算子オーバーロード
//a+b ,a.x+b.X ....
static Vec2 operator+(const Vec2& Left,const Vec2& Right)
{
	Vec2 ans;
	ans.x = Left.x + Right.x;
	ans.y = Left.y + Right.y;
	return ans;
}

