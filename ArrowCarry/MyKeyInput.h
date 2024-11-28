#pragma once
#include "DxLib.h"

/// <summary>
/// 【ユーザ定義:static】【依存:Dxlib】
/// keybordのみ
/// </summary>
class MyKeyInput
{
private:
	/*staticメンバ変数*/
	//それぞれのKeyの入力フレーム数
	// 定義だけ行い、実態はグローバルで作成
	static int m_keyFrame[];
public:
	
	//
	MyKeyInput();
	~MyKeyInput();


};

// 静的メンバ変数の実態作成
int MyKeyInput::m_keyFrame[256];
