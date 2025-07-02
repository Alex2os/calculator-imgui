#include <iostream>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;

void ScreenColor(float window_color[]) { // cant pass by reference for some reason

	// screen color
	ImGui::Begin("Background color");
	ImGui::Text("Choose a color for the background:");
	ImGui::ColorPicker3("Bg color", window_color);
	ImGui::End();
	//

}