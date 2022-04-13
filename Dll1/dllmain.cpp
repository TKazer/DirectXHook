// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include <windows.h>
#include "ImGuiHook.hpp"

void DrawMain()
{
    ImGui::Text("This is a [Direct 11 Hook] test.");
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        //DX11
        imgui_hook::get().Begin("Menu", hModule, DrawMain, DXTYPE::D3D11);
        //DX9
        //imgui_hook::get().Begin("Menu", hModule, DrawMain, DXTYPE::D3D9);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

