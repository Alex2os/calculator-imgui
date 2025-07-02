#include <iostream>
#include <string>

#include "stb_image.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;

void StatsWindow(ImGuiIO& io) {
	ImGui::Begin("Stats", nullptr, ImGuiWindowFlags_NoResize);

	float fps = io.Framerate;
	ImGui::Text("Actual FPS: %.5f", fps);

	ImGui::End();
}