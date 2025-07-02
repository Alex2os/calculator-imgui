#include <iostream>
#include <windows.h>
#include <shellapi.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;


void CreditsWindow() {
	string github_link = "https://github.com/Alex1ne";

	ImGui::Begin("Credits", nullptr, ImGuiWindowFlags_NoResize);
	ImGui::Text("Developed by Alex1ne");

	// add color to a text.
	ImGui::TextUnformatted("Here is my GitHub: ");

	ImGui::SetCursorPos(ImVec2(10, 60));
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 0.8f, 1.f, 1.0f));
	ImGui::TextUnformatted("Alex1ne");
	ImGui::PopStyleColor();

	if (ImGui::IsItemHovered()){
		ImGui::SetMouseCursor(ImGuiMouseCursor_Hand); // change icon to the "select" hand of the mouse

		ImGui::SetCursorPos(ImVec2(10, 60));
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.6f, 0.f, 1.f, 1.0f));
		ImGui::TextUnformatted("Alex1ne");
		ImGui::PopStyleColor();

	}
	

	if (ImGui::IsItemClicked()) {

				// with this part we can go to the link if the user clicks it (read more about it if you can)
        #ifdef _WIN32
		ShellExecuteA(
			nullptr,           // hwnd
			"open",            // operation
			github_link.c_str(),       // file/URL as const char*
			nullptr, nullptr,
			SW_SHOWNORMAL
		);
        #endif

	}

	ImGui::TextUnformatted("Click on my username to go to my github!");
	ImGui::TextUnformatted("Thanks for using my calculator :D");
	ImGui::End();
}