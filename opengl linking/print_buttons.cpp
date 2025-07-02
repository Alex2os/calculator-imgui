#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;

// buttons flags
ImGuiWindowFlags buttons_flags =
ImGuiWindowFlags_NoResize |
ImGuiWindowFlags_NoMove |
ImGuiWindowFlags_NoScrollbar;

void DrawNumbers(string &number_to_add) {

	ImGui::SetCursorPos(ImVec2(320, 30));
	if (ImGui::Button("7", ImVec2(40, 40))) {

		number_to_add = "7";
	
	}

	ImGui::SetCursorPos(ImVec2(370, 30));
	if (ImGui::Button("8", ImVec2(40, 40))) {

		number_to_add = "8";

	}

	ImGui::SetCursorPos(ImVec2(420, 30));
	if (ImGui::Button("9", ImVec2(40, 40))) {

		number_to_add = "9";

	}
	////// 4 - 6
	ImGui::SetCursorPos(ImVec2(320, 80));
	if (ImGui::Button("4", ImVec2(40, 40))) {

		number_to_add = "4";

	}

	ImGui::SetCursorPos(ImVec2(370, 80));
	if (ImGui::Button("5", ImVec2(40, 40))) {

		number_to_add = "5";

	}

	ImGui::SetCursorPos(ImVec2(420, 80));
	if (ImGui::Button("6", ImVec2(40, 40))) {

		number_to_add = "6";

	}
	////// 1 - 3
	ImGui::SetCursorPos(ImVec2(320, 130));
	if (ImGui::Button("1", ImVec2(40, 40))) {

		number_to_add = "1";

	}

	ImGui::SetCursorPos(ImVec2(370, 130));
	if (ImGui::Button("2", ImVec2(40, 40))) {

		number_to_add = "2";

	}

	ImGui::SetCursorPos(ImVec2(420, 130));
	if (ImGui::Button("3", ImVec2(40, 40))) {

		number_to_add = "3";

	}
	//// zero
	ImGui::SetCursorPos(ImVec2(370, 180));
	if (ImGui::Button("0", ImVec2(40, 40))) {

		number_to_add = "0";

	}
}

void DrawFunctions(string &function_to_add) {
	// calculations


		ImGui::Text("Calculate");
		ImGui::SetCursorPos(ImVec2(15, 30));
		if (ImGui::Button("+", ImVec2(40, 40))) {

			function_to_add = "plus";

		}

		ImGui::SetCursorPos(ImVec2(65, 30));
		if (ImGui::Button("-", ImVec2(40, 40))) {

			function_to_add = "minus";

		}

		ImGui::SetCursorPos(ImVec2(115, 30));
		if (ImGui::Button("/", ImVec2(40, 40))) {

			function_to_add = "divide";

		}

		ImGui::SetCursorPos(ImVec2(165, 30));
		if (ImGui::Button("x", ImVec2(40, 40))) {

			function_to_add = "multiply";

		}
		ImGui::SetCursorPos(ImVec2(270, 30));
		if (ImGui::Button("<", ImVec2(40, 40))) {

			function_to_add = "erase";

		}

		ImGui::SetCursorPos(ImVec2(270, 80));
		if (ImGui::Button("C", ImVec2(40, 40))) {

			function_to_add = "clear";

		}

		ImGui::SetCursorPos(ImVec2(270, 130));
		if (ImGui::Button("CE", ImVec2(40, 40))) {

			function_to_add = "clear_everything";

		}
		ImGui::SetCursorPos(ImVec2(270, 180));
		if (ImGui::Button("=", ImVec2(40, 40))) {

			function_to_add = "calculate";

		}
}

void InitializeCalculationsMenuChild() {

	ImGui::SetCursorPos(ImVec2(0, 140));

	ImGui::BeginChild("Calculate", ImVec2(470, 400), true, buttons_flags);

}

void EndCalculationsMenuChild() {

	ImGui::EndChild();

}