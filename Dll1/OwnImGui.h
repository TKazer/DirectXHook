#pragma once
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include <d3d11.h>
#include <dxgi.h>
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_internal.h"
#include "Struct.h"
// Datas

/****************************************************
* Copyright (C): Liv
* @file		: OwnImGui.h
* @author	: Liv
* @email		: 1319923129@qq.com
* @version	: 1.0
* @date		: 2022/4/17	15:57
****************************************************/

struct WindowData {
	HWND hWindow;		// Ŀ�괰�ھ��
	RECT WindowRect;	// Ŀ�괰������
	char WindowName[256];
	char WindowClassName[256];
	int  Width, Height; // Ŀ�괰�ڴ�С
};

class OwnImGui
{
public:
	// ���´�����Ϣ
	void UpdateWindowState();
	// ������Ϣ
	WindowData Window;
	// Բ��ѡ���
	void CheckboxEx(const char* Text, bool* Point);
	// �����ı����Ƴ���
	int  CalcTextWidth(const char* Text, float FontSize);
	// �ı�
	void Text(const char* Text, Vec2 Pos,int color);
	// ����
	void Rectangle(Vec2 Pos, int width, int height, int color, int thickness);
	// ��
	void Line(Vec2 From, Vec2 To,int color,int thickness);
	// Բ
	void Circle(Vec2 Center, float radius, int color, float thickness);
	// ���Բ
	void CircleFilled(Vec2 Center, float radius, int color, int num = 360);
	// ������
	void RectangleFilled(Vec2 Pos, int width, int height, int color);
	// ����ı�
	void StrokeText(const char* Text, Vec2 Pos, int color_bg, int color);
	// ���ӵ�
	void ConnectPoint(std::vector<Vec2> Points, int color, float thickness);
	// ��ɫת��
	int  Color(float* Color_);
}Gui;