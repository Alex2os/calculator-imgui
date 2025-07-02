#include <iostream>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;

int history_size = 0;
vector<float> user_history;

void HistoryWindow() {
	ImGui::Begin("History");
	ImGui::TextUnformatted("User history: ");
	for (int i = 0; i < history_size; i++) {

		ImGui::Text("%f", user_history[i]);

	}
	ImGui::End();

}

void CalculationHistory(const float &calculation_result) {
	
	history_size++;
	
	user_history.push_back(calculation_result);

}