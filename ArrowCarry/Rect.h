#pragma once

class Rect
{
public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="x">���S���W�FX</param>
	/// <param name="y">���S���W�FY</param>
	/// <param name="width">��</param>
	/// <param name="height">����</param>
	void Init(float x, float y, float width, float height)
	{
		m_width  = width;
		m_height = height;
		m_x = x;
		m_y = y;
	}
	/// <summary>
	/// ���S���X�V
	/// </summary>
	/// <param name="x">X���W</param>
	/// <param name="y">Y���W</param>
	void UpdateCenter(float x, float y)
	{
		m_x = x;
		m_y = y;
	}

	/// <summary>
	/// �������擾
	/// </summary>
	/// <returns>x - widht * 0.5f</returns>
	float GetLeft() const
	{
		return m_x - m_width * 0.5f;
	}
	/// <summary>
	/// �E�����擾
	/// </summary>
	/// <returns>x - widht * 0.5f</returns>
	float GetRight() const
	{
		return m_x + m_width * 0.5f;
	}
	/// <summary>
	/// �㑤���擾
	/// </summary>
	/// <returns>y - hegiht * 0.5f</returns>
	float GetTop() const
	{
		return m_y - m_height * 0.5f;
	}
	/// <summary>
	/// �������擾
	/// </summary>
	/// <returns>y + hegiht * 0.5f</returns>
	float GetBottom() const
	{
		return m_y + m_height * 0.5f;
	}

private:
	// ���E�㉺�̈ʒu
	float m_x;
	float m_y;
	// ����̕��E����
	float m_width;
	float m_height;
};