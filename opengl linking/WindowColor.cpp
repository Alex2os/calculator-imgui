#include <iostream>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;

void SmallWindowsColor(float *small_windows_color) {
	bool p_open;

	ImGui::Begin("Windows color", &p_open);
	ImGui::Text("Choose a color for the windows");
	ImGui::ColorPicker4("Windows color", small_windows_color);
	ImGui::End();
}

