#pragma once
#include "Vec2.h"

class Rect
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="x">中心座標：X</param>
	/// <param name="y">中心座標：Y</param>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	void Init(float x, float y, float width, float height)
	{
		m_pos.x = x;
		m_pos.y = y;
		m_width  = width;
		m_height = height;
	}
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="pos">中心座標</param>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	void Init(const Vec2& pos, float width, float height)
	{
		m_pos = pos;
		m_width = width;
		m_height = height;
	}

	/// <summary>
	/// 中心を更新
	/// </summary>
	/// <param name="x">X座標</param>
	/// <param name="y">Y座標</param>
	void UpdateCenter(float x, float y)
	{
		m_pos.x = x;
		m_pos.y = y;
	}
	/// <summary>
	/// 中心を更新
	/// </summary>
	/// <param name="pos">座標</param>
	void UpdateCenter(const Vec2& pos)
	{
		m_pos = pos;
	}

	/// <summary>
	/// 左側を取得
	/// </summary>
	/// <returns>x - widht * 0.5f</returns>
	float GetLeft() const
	{
		return m_pos.x - m_width * 0.5f;
	}
	/// <summary>
	/// 右側を取得
	/// </summary>
	/// <returns>x - widht * 0.5f</returns>
	float GetRight() const
	{
		return m_pos.x + m_width * 0.5f;
	}
	/// <summary>
	/// 上側を取得
	/// </summary>
	/// <returns>y - hegiht * 0.5f</returns>
	float GetTop() const
	{
		return m_pos.y - m_height * 0.5f;
	}
	/// <summary>
	/// 下側を取得
	/// </summary>
	/// <returns>y + hegiht * 0.5f</returns>
	float GetBottom() const
	{
		return m_pos.y + m_height * 0.5f;
	}

private:
	// 中心
	Vec2 m_pos;
	// 判定の幅・高さ
	float m_width;
	float m_height;
};