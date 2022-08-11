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
	HWND hWindow;		// 目标窗口句柄
	RECT WindowRect;	// 目标窗口数据
	char WindowName[256];
	char WindowClassName[256];
	int  Width, Height; // 目标窗口大小
};

class OwnImGui
{
public:
	// 更新窗口信息
	void UpdateWindowState();
	// 窗口信息
	WindowData Window;
	// 圆角选择框
	void CheckboxEx(const char* Text, bool* Point);
	// 计算文本绘制长度
	int  CalcTextWidth(const char* Text, float FontSize);
	// 文本
	void Text(const char* Text, Vec2 Pos,int color);
	// 矩形
	void Rectangle(Vec2 Pos, int width, int height, int color, int thickness);
	// 线
	void Line(Vec2 From, Vec2 To,int color,int thickness);
	// 圆
	void Circle(Vec2 Center, float radius, int color, float thickness);
	// 填充圆
	void CircleFilled(Vec2 Center, float radius, int color, int num = 360);
	// 填充矩形
	void RectangleFilled(Vec2 Pos, int width, int height, int color);
	// 描边文本
	void StrokeText(const char* Text, Vec2 Pos, int color_bg, int color);
	// 连接点
	void ConnectPoint(std::vector<Vec2> Points, int color, float thickness);
	// 颜色转换
	int  Color(float* Color_);
}Gui;