#include <windows.h>
#include "ImGuiHook.hpp"
#include "OwnImGui.h"

/****************************************************
* Copyright (C): Liv
* @file		: dllmain.cpp
* @author	: Liv
* @email	: 1319923129@qq.com
* @version	: 1.0
* @date		: 2022/6/5	20:04
****************************************************/

void DrawMain()
{
    switch (imgui_hook::get().DxType)
    {
    case DXTYPE::D3D9:
        ImGui::Text("This is a [Direct 9 Hook] test.");
        break;
    case DXTYPE::D3D11:
        ImGui::Text("This is a [Direct 11 Hook] test.");
        break;
    }
    Gui.Text("Text", Vec2(5, 5), IM_COL32(255, 255, 0, 255));
    Gui.Rectangle(Vec2(50, 50), 20, 20, IM_COL32(255, 0, 255, 0), 2);
    if (ImGui::Button("UnInstall"))
    {
        imgui_hook::get().End();
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{   
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        // 入口
        imgui_hook::get().Begin("Menu", hModule, DrawMain, DXTYPE::AUTO);
    }
    return TRUE;
}
