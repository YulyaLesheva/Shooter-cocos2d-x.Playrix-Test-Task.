#include "TextFile.h"
#include <iostream>
#include <fstream>
USING_NS_CC;

int getValueFromTxt(std::string varName)
{
	std::ifstream myFile;
	std::string myString;
	std::string inputString = varName;
	char equalSign;
	int value;
	int outputValue;

	myFile.open(CCFileUtils::sharedFileUtils()->fullPathForFilename("input.txt").c_str());

	while (myFile >> myString >> equalSign >> value) {
		if (myString == inputString) {
			outputValue = value;
		}
	}
	return outputValue;
}
