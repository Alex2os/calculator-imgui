#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

using namespace std;

int isNumberCalculate(char);
int isfunctionCalculate(char);

void getResult(string &number1String, string &number2String, string string_number) {

	float return_result =0;

	float first_number = stof(number1String);
	float second_number = stof(number2String);

	cout << " str_number: " << string_number << " 1st number:" << first_number << " 2nd number:" << second_number << endl;

	if (string_number == "+") return_result = first_number + second_number;
	else if (string_number == "-") return_result = first_number - second_number;
	else if (string_number == "/") return_result = first_number / second_number;
	else if (string_number == "*") return_result = first_number * second_number;

	cout << "result obtained: " << return_result << endl;

	number1String.clear();
	number2String.clear();
	string_number.clear();
	number1String = to_string(return_result);
	cout << endl << "numb1str:" << number1String;

}

float Calculate(string &number_string) {

	float result = 0;
	float number1 = 0;
	float number2 = 0;

	bool number2Activator = false;

	string function_symbol;
	string number1String;
	string calculationString;
	string number2String;
	for (int i = 0; i < number_string.size(); i++) {

		if (isNumberCalculate(number_string[i]) == 1 && !number2Activator) number1String += number_string[i];
		else if (isNumberCalculate(number_string[i]) == 1 && number2Activator) number2String += number_string[i];
		else if (isfunctionCalculate(number_string[i]) == 1) {
			function_symbol = number_string[i];

			if (number2Activator) {

				getResult(number1String, number2String, function_symbol);
				

			}else number2Activator = true;
			
		}

		if (i == number_string.size() - 1) {


			getResult(number1String, number2String, function_symbol);

		}
		
	}

	result = stof(number1String);

	return result;

}