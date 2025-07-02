#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;

int isNumber(string &number_string) {

	char last_character = '\0';

	size_t pos;
	if (number_string.size() == 1);
	else last_character = number_string[number_string.size() - 2];

	float check_for_number = stoi(to_string(last_character), &pos, 10);

	for (int i = 48; i < 58; i++) { // numbers from 0 to 9 in ascii code

		if (check_for_number == i) return 1;

	}
	return 0;

}

int isFunction(string &number_string) {

	char last_character = '\0';

	size_t pos;
	if (number_string.size() == 1);
	else last_character = number_string[number_string.size() - 2];

	float check_for_function = stoi(to_string(last_character), &pos, 10);

	for (int i = 42; i < 48; i++) { // signs for +, -, / and * to check whether it's a function. it's in ascii code. add more if you expand the calculator.

		if (i == 44 || i == 46);
		else if (check_for_function == i) return 1;

	}
	return 0;

}

int isNumberCalculate(char character) {


	for (int i = 48; i < 58; i++) { 

		if (character == i) return 1;
	}
	return 0;

}

int isfunctionCalculate(char character) {

	size_t pos;

	int function = stoi(to_string(character), &pos, 10);

	for (int i = 42; i < 48; i++) {

		if (i == 44 || i == 46);
		else if ( function == i) return 1;

	}
	return 0;

}