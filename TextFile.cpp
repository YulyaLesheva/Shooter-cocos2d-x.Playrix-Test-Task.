#include "TextFile.h"
#include <iostream>
#include <fstream>
USING_NS_CC;

int getValueFromTxt(std::string varName){

	std::ifstream yFile("input.txt");
	std::string yString;
	char yEqualSign;
	std::string inputString = varName;


	int yValue;
	int newValue;

	while (yFile >> yString >> yEqualSign >> yValue) {
		if (yString == inputString) {
			newValue = yValue;
		}
	}

	return newValue;

	
}
