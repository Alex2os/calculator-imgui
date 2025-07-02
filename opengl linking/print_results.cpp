#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;


void PrintResults(string &number_string, bool &result, float &calculation_result) {

	ImGuiWindowFlags result_flags =
	ImGuiWindowFlags_NoResize |
	ImGuiWindowFlags_NoMove |
	ImGuiWindowFlags_NoScrollbar;

	ImGui::SetCursorPos(ImVec2(0, 30)); // with this, we set the potition of drawing.

	ImGui::BeginChild("Result", ImVec2(470, 100), true, result_flags); // we can use the begin child function to create a window inside a window. // we put the name, size of the window, if we want a border or not (true or false) and the flags.
	{
		// inside here we put what we want inside the window. in this case, it's the result of the calculations.
		ImGui::Text("Result:");
		ImGui::SetCursorPos(ImVec2(10, 30));
		if (!result) ImGui::Text("%s", number_string.c_str());
		else ImGui::Text("%f", calculation_result);

	}
	ImGui::EndChild();

}