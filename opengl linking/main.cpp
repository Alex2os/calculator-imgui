// things to do/ ideas
// for the case of euler, pi, factorial, etc., you could send by reference the parameter to another function to calculate first those special symbols, and then change--
// the string in those functions, so then the calculate_algorithm will only have to work with /, *, +, -, etc.
//

#include <iostream>
#include <string>

// image handling with stb
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


// glm: mathematical library for graphics (like glfw and gl)
// glfw and opengl allows to create and control the screen/display

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
// do not include loader.h

using namespace std;

const GLint WIDTH = 1920, HEIGHT = 1080; // size of the display
bool p_open = true;
float calculation_result = 0;
string number_string = "";
float first_number = -1;
bool result = false;
bool isThereNumber = false;

// 
string number_to_add = "null";
string function_to_add = "null";

// window color
float window_color[3] = { 0.f, 0.f, 0.f };
float small_windows_color[4] = { 0.f, 0.f, 0.f, 0.f };


void DrawNumbers(string&);
void DrawFunctions(string&);

void InitializeCalculationsMenuChild();
void EndCalculationsMenuChild();

void PrintResults(string&, bool&, float&);
void KeyboardInputs(string&, string&);

void UpdateNumbers(string&, string&, bool&, bool&);
void UpdateFunctions(string&, string&, bool&, bool&);

float CalculateFunction(string&, string&, bool&, float&);

void ScreenColor(float[]);

void CreditsWindow();

void HistoryWindow();

void SmallWindowsColor(float *);

void StatsWindow(ImGuiIO&);


void Config() {

	// get and handle user inputs
	glfwPollEvents();

	// clear buffers
	glClearColor(window_color[0], window_color[1], window_color[2], 255.f);
	glClear(GL_COLOR_BUFFER_BIT);

	// imgui frames
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

}

void DrawAndRender(GLFWwindow *window) {

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(window);

}

int main() {

	////////////////////////////////////////////////////////////////////////////
	if (!glfwInit()) {
		cout << "error";
		glfwTerminate();
		return 1;
	}

	// initialization
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// create window
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Calculus", NULL, NULL);

	// window icon
	int iconW, iconH, channels;
	unsigned char* pixels = stbi_load("calculator.png", &iconW, &iconH, &channels, 4);
	GLFWimage images[1];
	images[0].width = iconW;
	images[0].height = iconH;
	images[0].pixels = pixels;

	glfwSetWindowIcon(window, 1, images);
	stbi_image_free(pixels);

	if (!window) {
		cout << "window not working" << endl;
		glfwTerminate();
		return 1;
	}

	// buffer size
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

	//  set context
	glfwMakeContextCurrent(window);

	// innit glew
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		cout << "not working glew";
		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}
	// viewport
	glViewport(0, 0, bufferWidth, bufferHeight);

	// init imgui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////
	// main loop
	while (!glfwWindowShouldClose(window)) {
		// color for all the windows
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(small_windows_color[0], small_windows_color[1], small_windows_color[2], small_windows_color[3]));

		// configuration of the loop and things
		Config();

		// start rendering of things:

		// calculator start
		ImGui::Begin("Calculator", nullptr, ImGuiWindowFlags_NoResize);


		PrintResults(number_string, result, calculation_result);

		InitializeCalculationsMenuChild();

		DrawFunctions(function_to_add);
		calculation_result = CalculateFunction(number_string, function_to_add, result, calculation_result);
		UpdateFunctions(function_to_add, number_string, isThereNumber, result);

		DrawNumbers(number_to_add);
		UpdateNumbers(number_to_add, number_string, isThereNumber, result);

		KeyboardInputs(number_to_add, function_to_add);
		UpdateNumbers(number_to_add, number_string, isThereNumber, result);

		EndCalculationsMenuChild();


		ImGui::End();
		// calculator end

		CreditsWindow();

		HistoryWindow();

		ScreenColor(window_color);

		SmallWindowsColor(small_windows_color);

		StatsWindow(io);


		// imgui draw/render
		DrawAndRender(window);

		ImGui::PopStyleColor();

	}
	//////////////////////////////////////


	// cleanup for glfw
	glfwDestroyWindow(window);
	glfwTerminate();

	// cleanup for imgui
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();


	return 0;
}