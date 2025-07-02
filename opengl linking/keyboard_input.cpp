#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;


void KeyboardInputs(string &number_to_add, string &function_to_add) {

	if (ImGui::IsKeyDown(ImGuiKey_LeftShift) && ImGui::IsKeyPressed(ImGuiKey_7)) function_to_add = "divide";
	else if (ImGui::IsKeyDown(ImGuiKey_LeftShift) && ImGui::IsKeyPressed(ImGuiKey_RightBracket)) function_to_add = "multiply";
	else if (ImGui::IsKeyPressed(ImGuiKey_RightBracket)) function_to_add = "plus";
	else if (ImGui::IsKeyPressed(ImGuiKey_Minus)) function_to_add = "minus";
	else if (ImGui::IsKeyPressed(ImGuiKey_Backspace)) function_to_add = "erase";
	else if (ImGui::IsKeyPressed(ImGuiKey_Enter)) function_to_add = "calculate";

	else if (ImGui::IsKeyPressed(ImGuiKey_0)) number_to_add = "0";
	else if (ImGui::IsKeyPressed(ImGuiKey_1)) number_to_add = "1";
	else if (ImGui::IsKeyPressed(ImGuiKey_2)) number_to_add = "2";
	else if (ImGui::IsKeyPressed(ImGuiKey_3)) number_to_add = "3";
	else if (ImGui::IsKeyPressed(ImGuiKey_4)) number_to_add = "4";
	else if (ImGui::IsKeyPressed(ImGuiKey_5)) number_to_add = "5";
	else if (ImGui::IsKeyPressed(ImGuiKey_6)) number_to_add = "6";
	else if (ImGui::IsKeyPressed(ImGuiKey_7)) number_to_add = "7";
	else if (ImGui::IsKeyPressed(ImGuiKey_8)) number_to_add = "8";
	else if (ImGui::IsKeyPressed(ImGuiKey_9)) number_to_add = "9";


}