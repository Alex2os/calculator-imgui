#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;

int isNumber(string&);
float Calculate(string&);
void CalculationHistory(const float&);


void UpdateNumbers(string &number_to_add, string &number_string, bool &isThereNumber, bool&result) {

	if (number_to_add != "null") {

		if (result) result = false;

		if (number_to_add == "1") number_string += "1";
		else if (number_to_add == "2") number_string += "2";
		else if (number_to_add == "3") number_string += "3";
		else if (number_to_add == "4") number_string += "4";
		else if (number_to_add == "5") number_string += "5";
		else if (number_to_add == "6") number_string += "6";
		else if (number_to_add == "7") number_string += "7";
		else if (number_to_add == "8") number_string += "8";
		else if (number_to_add == "9") number_string += "9";
		else if (number_to_add == "0") number_string += "0";

		isThereNumber = true;
		number_to_add = "null";
	}

}

void UpdateFunctions(string& function_to_add, string& number_string, bool &isThereNumber, bool&result) {


	if (function_to_add == "erase") {

		if (number_string.size() == 0);
		else {

			if (isNumber(number_string) == 1) isThereNumber = true, function_to_add = "null";

			number_string.erase(number_string.size() - 1);
			result = false;

		}

	}
	else if (function_to_add == "clear") number_string.clear(), result = false;
	else if (function_to_add == "clear_everything") number_string.clear(), result = false;

	if (!isThereNumber) function_to_add = "null";

	

	if (function_to_add != "null") {

		if (function_to_add == "calculate");
		else{
		
			if (result) result = false;

		}
		

		if (function_to_add == "plus") number_string += "+";
		else if (function_to_add == "minus") number_string += "-";
		else if (function_to_add == "divide") number_string += "/";
		else if (function_to_add == "multiply") number_string += "*";

		isThereNumber = false;
		function_to_add = "null";
	}

}

float CalculateFunction(string &number_string, string &function_to_add, bool&result, float &calculation_result) {


	if (function_to_add == "calculate") calculation_result = Calculate(number_string), result = true, CalculationHistory(calculation_result);

	return calculation_result;
}