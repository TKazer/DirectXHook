#include "OwnImGui.h"

int  OwnImGui::CalcTextWidth(const char* Text,float FontSize)
{
    if (strcmp(Text, "") == 0)
        return 0;
    return ImGui::GetFont()->CalcTextSizeA(FontSize, FLT_MAX, 0, Text).x;
}

void OwnImGui::Text(const char* Text, Vec2 Pos, int color)
{
    ImGui::GetForegroundDrawList()->AddText(ImVec2(Pos.x, Pos.y), color, Text);
}

void OwnImGui::Rectangle(Vec2 Pos, int width, int height,int color, int thickness)
{
    ImGui::GetForegroundDrawList()->AddRect(ImVec2(Pos.x, Pos.y), ImVec2(Pos.x+width, Pos.y+height), color, 0, 15, thickness);
}

void OwnImGui::Line(Vec2 From, Vec2 To, int color, int thickness)
{
    ImGui::GetForegroundDrawList()->AddLine(ImVec2(From.x,From.y), ImVec2(To.x,To.y), color, thickness);
}

void OwnImGui::Circle(Vec2 Center,float radius,int color,float thickness)
{

    ImGui::GetForegroundDrawList()->AddCircle(ImVec2(Center.x,Center.y), radius, color, max(radius, 50), thickness);
}

void OwnImGui::CircleFilled(Vec2 Center, float radius, int color, int num)
{
    ImGui::GetForegroundDrawList()->AddCircleFilled(ImVec2(Center.x, Center.y), radius, color, num);
}

void OwnImGui::RectangleFilled(Vec2 Pos, int width, int height, int color)
{
    ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(Pos.x, Pos.y), ImVec2(Pos.x + width, Pos.y + height), color, 0, 0);
}

void OwnImGui::StrokeText(const char* Text, Vec2 Pos, int color_b, int color)
{
    this->Text(Text, Vec2(Pos.x - 1, Pos.y + 1), color_b);
    this->Text(Text, Vec2(Pos.x - 1, Pos.y - 1), color_b);
    this->Text(Text, Vec2(Pos.x + 1, Pos.y + 1), color_b);
    this->Text(Text, Vec2(Pos.x + 1, Pos.y - 1), color_b);
    this->Text(Text, Pos, color);
}

void OwnImGui::UpdateWindowState()
{
    // 更新窗口数据
    POINT TempPoint{ 0,0 };
    RECT TempRect;
    GetClientRect(this->Window.hWindow, &TempRect);

    ClientToScreen(this->Window.hWindow, &TempPoint);
    this->Window.WindowRect.left = TempPoint.x;
    this->Window.WindowRect.right = this->Window.WindowRect.left + TempRect.right;
    this->Window.WindowRect.top = TempPoint.y;
    this->Window.WindowRect.bottom = this->Window.WindowRect.top + TempRect.bottom;

    this->Window.Width = this->Window.WindowRect.right - this->Window.WindowRect.left;
    this->Window.Height = this->Window.WindowRect.bottom - this->Window.WindowRect.top;
}

void OwnImGui::ConnectPoint(std::vector<Vec2> Points, int color, float thickness)
{
    if (Points.size() <= 0)
        return;
    for (int i = 0; i < Points.size() - 1; i++)
    {
        Line(Points[i], Points[i + 1], color, thickness);
        if (i == Points.size() - 2)
            Line(Points[i + 1], Points[0], color, thickness);
    }
}

void OwnImGui::CheckboxEx(const char* Text, bool* Point)
{
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    float height = ImGui::GetFrameHeight();
    float width = height * 1.55f;
    float radius = height * 0.50f;

    ImGui::InvisibleButton(Text, ImVec2(width, height));
    if (ImGui::IsItemClicked())
        *Point = !*Point;

    float t = *Point ? 1.0f : 0.0f;

    ImGuiContext& g = *GImGui;
    float ANIM_SPEED = 0.08f;
    if (g.LastActiveId == g.CurrentWindow->GetID(Text))
    {
        float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
        t = *Point ? (t_anim) : (1.0f - t_anim);
    }

    ImU32 col_bg;
    if (ImGui::IsItemHovered())
        col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.78f, 0.78f, 0.78f, 1.0f), ImVec4(0.86f, 0.07f, 0.23f, 1.0f), t));
    else
        col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.85f, 0.85f, 0.85f, 1.0f), ImVec4(0.78f, 0.07f, 0.15f, 1.0f), t));

    draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
    draw_list->AddCircleFilled(ImVec2(p.x + radius + t * (width - radius * 2.0f), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));
    ImGui::SameLine();
    ImGui::Text(Text);
}

int  OwnImGui::Color(float* Color_)
{
    return IM_COL32(Color_[0] * 255, Color_[1] * 255, Color_[2] * 255, Color_[3] * 255);
}